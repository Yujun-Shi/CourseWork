#include "GrammarTree.h"
#include <typeinfo>
#include "myparser.h"
#include <iostream>


using namespace std;

int curLineNo = 1;
char* curID = NULL;
char* curString = NULL;
int curInt = 0;
double curFloat = 0.0;
char curChar = '\0';
// default is true
// push it down when encountered for or function definition
// pop it up every time when enter a compound statement
bool extraAreaSupportSwitch = true;

IdInfo GrammarTree::info = IdInfo(NON_ID_TYPE_T, NON_QUAL_TYPE_T);

int GrammarTree::nxtLabel = 0;

// triple address utils
vector<TripleAddr> GrammarTree::tripleAddrList = vector<TripleAddr>();

shared_ptr<GrammarNode> GrammarTree::curFuncNode;

vector<FuncTableEntry> GrammarTree::globalFuncTable = vector<FuncTableEntry>();

// vector<GlobalDec> GrammarTree::globalDecList = vector<GlobalDec>();

void GrammarTree::obtainIdInfo(shared_ptr<GrammarNode> _node) {
    if (typeid(*_node->type) == typeid(TypeQual)) {
        info.qualType = dynamic_cast<TypeQual* >(_node->type.get())->typeQualItem;
    }
    else if (typeid(*_node->type) == typeid(TypeSpec)) {
        info.idType = dynamic_cast<TypeSpec* >(_node->type.get())->typeSpecItem;
    }
    for (int i = 0; i < _node->children.size(); ++i) {
        obtainIdInfo(_node->children[i]);
    }
}

// since IdInfo is a static variable
void GrammarTree::fixIdInfo(shared_ptr<GrammarNode> _node, bool ifParam_) {
    if (typeid(*_node->type) == typeid(IdDec)) {
        // insert into corresponding symbol table
        shared_ptr<TableNode> id_table_ = dynamic_cast<IdDec*>(_node->type.get())->table;
        auto it = id_table_->table->find(string(_node->type->attr.name));
        if (it != id_table_->table->end()) {
            it->second.idType = info.idType;
            it->second.qualType = info.qualType;
            it->second.ifParam = ifParam_;
            // initialize the offset as 0
            it->second.offset = 0;
        }
        else {
            cout << "damn! this should never happen!\n";
        }
    }
    for (int i = 0; i < _node->children.size(); ++i) {
        fixIdInfo(_node->children[i], ifParam_);
    }
}

void GrammarTree::resetIdInfo() {
    info.idType = NON_ID_TYPE_T;
    info.qualType = NON_QUAL_TYPE_T;
}

std::string GrammarTree::newLabel() {
    return "_L" + to_string(nxtLabel++);
}

void GrammarTree::insertTriple(TripleAddr addr) {
    // since we use back order traverse (is that even a phrase?)
    tripleAddrList.push_back(addr);
}

void GrammarTree::recursiveFillInParam(FuncTableEntry& e, std::shared_ptr<GrammarNode> _node) {
    for (int i = 0; i < _node->children.size(); ++i) {
        recursiveFillInParam(e, _node->children[i]);
    }
    if (typeid(*(_node->type->what())) == typeid(ParamDec)) {
        e.paramNames.push_back(_node->children[1]->type->attr.name);
        e.paramType.push_back(dynamic_cast<TypeSpec*>
            (_node->children[0]->children[0]->type.get())->typeSpecItem);
        auto it = dynamic_cast<FuncDef*>(curFuncNode->type.get())->
            idTable->table->find(_node->children[1]->type->attr.name);
        it->second.offset = (e.paramType.size() - 1) * 4 + 8;
    }
}

void GrammarTree::recursivePushFuncCallParam(std::shared_ptr<GrammarNode> _node) {
    TripleAddr tmp;
    for (int i = 0; i < _node->children.size(); ++i) {
        recursivePushFuncCallParam(_node->children[i]);
    }
    if (typeid(*_node->type->what()) == typeid(IdUse) 
        || typeid(*_node->type->what()) == typeid(INumUse)
        || typeid(*_node->type->what()) == typeid(CharUse)) {
        tmp.operation = PUSH;
        tmp.addr[0] = _node->place;
        tmp.type[0] = _node->placeType;
        insertTriple(tmp);
    }
}

void GrammarTree::recursiveBuildTripleAddr(shared_ptr<GrammarNode> _node) {
    if(_node == nullptr){
        return;
    }
    const std::type_info& nodeType = typeid(*(_node->type));
    TripleAddr tmp;

    if (typeid(FuncDef) == nodeType) {
        curFuncNode = _node;
        // will fill up how many variables do we actually need
        tmp.operation = BEGINFUNC;
        tmp.addr[0] = _node->children[1]->children[0]->type->attr.name;
        insertTriple(tmp);
        dynamic_cast<FuncDef*>(_node->type.get())->nxtAvail = -4;
        dynamic_cast<FuncDef*>(_node->type.get())->beginFuncInd = tripleAddrList.size() - 1;
        // fill in the function info
        FuncTableEntry entry;
        entry.FuncName = _node->children[1]->children[0]->type->attr.name;
        entry.returnType = dynamic_cast<TypeSpec*>
            (_node->children[0]->children[0]->type.get())->typeSpecItem;
        recursiveFillInParam(entry, _node->children[1]);
        globalFuncTable.push_back(entry);

        // recursively find all ids
        TableNode::recursiveFillInOffset(dynamic_cast<FuncDef*>(_node->type.get())->idTable,
            dynamic_cast<FuncDef*>(_node->type.get())->nxtAvail);
    }

    if (typeid(*(_node->type)) == typeid(SelStmt)) {
        if (_node->children.size() == 2) {
            bool buildNewLabel = false;
            if (_node->type->nextLabel == "") { // assign a new label
                _node->type->nextLabel = newLabel();
                buildNewLabel = true;
            }
            // fill in label first
            _node->children[0]->type->trueLabel = newLabel();
            _node->children[0]->type->falseLabel = _node->type->nextLabel;
            _node->children[1]->type->nextLabel = _node->type->nextLabel;

            // recursively build
            recursiveBuildTripleAddr(_node->children[0]);
            tmp.operation = LABEL;
            tmp.addr[0] = _node->children[0]->type->trueLabel;
            insertTriple(tmp);
            recursiveBuildTripleAddr(_node->children[1]);
            if (buildNewLabel) {
                tmp.operation = LABEL;
                tmp.addr[0] = _node->type->nextLabel;
                insertTriple(tmp);
            }
        }
        else {
            // fill in label first
            bool buildNewLabel = false;

            _node->children[0]->type->trueLabel = newLabel();
            _node->children[0]->type->falseLabel = newLabel();
            if (_node->type->nextLabel == "") { // assign a new label
                _node->type->nextLabel = newLabel();
                buildNewLabel = true;
            }
            _node->children[1]->type->nextLabel = _node->type->nextLabel;
            _node->children[2]->type->nextLabel = _node->type->nextLabel;

            // recursively build
            recursiveBuildTripleAddr(_node->children[0]);
            tmp.operation = LABEL;
            tmp.addr[0] = _node->children[0]->type->trueLabel;
            insertTriple(tmp);
            recursiveBuildTripleAddr(_node->children[1]);
            tmp.operation = JMP;
            tmp.addr[0] = _node->type->nextLabel;
            insertTriple(tmp);
            tmp.operation = LABEL;
            tmp.addr[0] = _node->children[0]->type->falseLabel;
            insertTriple(tmp);
            recursiveBuildTripleAddr(_node->children[2]);
            if (buildNewLabel) {
                tmp.operation = LABEL;
                tmp.addr[0] = _node->type->nextLabel;
                insertTriple(tmp);
            }
        }
    }
    else if (typeid(*_node->type) == typeid(IterStmt)) {
        _node->type->beginLabel = newLabel();
        if (_node->children.size() == 2) { // while
            // fill in the label first
            bool buildNewLabel = false;
            _node->children[0]->type->trueLabel = newLabel();
            if (_node->type->nextLabel == "") {
                _node->type->nextLabel = newLabel();
                buildNewLabel = true;
            }
            _node->children[0]->type->falseLabel = _node->type->nextLabel;
            _node->children[1]->type->nextLabel = _node->type->beginLabel;
            
            // recursively build
            tmp.operation = LABEL;
            tmp.addr[0] = _node->type->beginLabel;
            insertTriple(tmp);
            recursiveBuildTripleAddr(_node->children[0]);
            tmp.addr[0] = _node->children[0]->type->trueLabel;
            insertTriple(tmp);
            recursiveBuildTripleAddr(_node->children[1]);
            
            tmp.operation = JMP;
            tmp.addr[0] = _node->type->beginLabel;
            insertTriple(tmp);
            if (buildNewLabel) {
                tmp.operation = LABEL;
                tmp.addr[0] = _node->type->nextLabel;
                insertTriple(tmp);
            }
        }
        else { // for
            bool buildNewLabel = false;
            
            // fill label first
            _node->children[1]->type->trueLabel = newLabel();
            if (_node->type->nextLabel == "") {
                _node->type->nextLabel = newLabel();
                buildNewLabel = true;
            }
            _node->children[1]->type->falseLabel = _node->type->nextLabel;
            // _node->children[3]->type->nextLabel = _node->type->beginLabel;
            _node->children[2]->type->nextLabel = _node->type->beginLabel;
            // recursively build
            recursiveBuildTripleAddr(_node->children[0]);
            tmp.operation = LABEL;
            tmp.addr[0] = _node->type->beginLabel;
            insertTriple(tmp);
            recursiveBuildTripleAddr(_node->children[1]);
            tmp.operation = LABEL;
            tmp.addr[0] = _node->children[1]->type->trueLabel;
            insertTriple(tmp);
            // here is the tricky part
            recursiveBuildTripleAddr(_node->children[3]);
            recursiveBuildTripleAddr(_node->children[2]);
            
            tmp.operation = JMP;
            tmp.addr[0] = _node->type->beginLabel;
            insertTriple(tmp);
            if (buildNewLabel) {
                tmp.operation = LABEL;
                tmp.addr[0] = _node->type->nextLabel;
                insertTriple(tmp);
            }
        }
    }
    else if (typeid(LogOrExpr) == typeid(*(_node->type))) {
        // fill in label
        _node->children[0]->type->trueLabel = _node->type->trueLabel;
        _node->children[0]->type->falseLabel = newLabel();
        _node->children[1]->type->trueLabel = _node->type->trueLabel;
        _node->children[1]->type->falseLabel = _node->type->falseLabel;
        
        // insert triple address
        recursiveBuildTripleAddr(_node->children[0]);
        tmp.operation = LABEL;
        tmp.addr[0] = _node->children[0]->type->falseLabel;
        insertTriple(tmp);
        recursiveBuildTripleAddr(_node->children[1]);
    }
    else if (typeid(LogAndExpr) == typeid(*(_node->type))) {
        // fill in label
        _node->children[0]->type->trueLabel = newLabel();
        _node->children[0]->type->falseLabel = _node->type->falseLabel;
        _node->children[1]->type->trueLabel = _node->type->trueLabel;
        _node->children[1]->type->falseLabel = _node->type->falseLabel;
        
        // insert triple address
        recursiveBuildTripleAddr(_node->children[0]);
        tmp.operation = LABEL;
        tmp.addr[0] = _node->children[0]->type->trueLabel;
        insertTriple(tmp);
        recursiveBuildTripleAddr(_node->children[1]);
    }
    else if (typeid(PrefixExpr) == typeid(*(_node->type)) && _node->type->attr.optype == LOGICNOT) {
        // fill in label
        _node->children[0]->type->trueLabel = _node->type->falseLabel;
        _node->children[0]->type->falseLabel = _node->type->trueLabel;

        // insert triple address
        recursiveBuildTripleAddr(_node->children[0]);
    }
    else {
        for (int i = 0; i < _node->children.size(); ++i) {
            recursiveBuildTripleAddr(_node->children[i]);
        }
    }
    if (typeid(InitDec) == nodeType) {
        if (_node->children[0]->placeType != _node->children[1]->placeType) {
            cout << "type error at line: " << _node->lineno << "\n";
            exit(0);
        }
        tmp.operation = ASSIGN;
        tmp.res = _node->children[0]->place;
        tmp.addr[0] = _node->children[1]->place;
        tmp.type[0] = _node->children[1]->placeType;
        insertTriple(tmp);
        _node->place = tmp.res;
        _node->placeType = _node->children[0]->placeType;
    }else if (typeid(PrintStmt) == nodeType) {
        tmp.operation = PRINT;
        tmp.addr[0] = _node->children[0]->place;
        tmp.type[0] = _node->children[0]->placeType;
        insertTriple(tmp);
    }else if (typeid(InputStmt) == nodeType) {
        tmp.operation = INPUT;
        tmp.addr[0] = _node->children[0]->place;
        insertTriple(tmp);
    }else if (typeid(FuncDef) == nodeType) {
        tmp.operation = ENDFUNC;
        tmp.addr[0] = _node->children[1]->children[0]->type->attr.name;
        tmp.addr[1] = to_string(-(dynamic_cast<FuncDef*>(_node->type.get())->nxtAvail + 4));
        // backward fill in
        tripleAddrList[dynamic_cast<FuncDef*>(_node->type.get())->beginFuncInd].addr[1]
            = to_string(-(dynamic_cast<FuncDef*>(_node->type.get())->nxtAvail + 4));
        
        insertTriple(tmp);
    }else if (nodeType == typeid(AssignExpr)) {

        if (_node->children[0]->placeType != _node->children[1]->placeType) {
            cout << "type error at line: " << _node->lineno << "\n";
            exit(0);
        }
        if (_node->type->attr.optype == ASSIGN) {
            tmp.operation = ASSIGN;
            tmp.res = _node->children[0]->place;
            tmp.addr[0] = _node->children[1]->place;
            tmp.type[0] = _node->children[1]->placeType;
            insertTriple(tmp);

            _node->place = tmp.res;
            _node->placeType = _node->children[0]->placeType;
            return;
        }

        switch (_node->type->attr.optype) {
        // some op, and ASSIGN
        case ADDASSIGN:
            tmp.operation = ADD;
            break;
        case MINUSASSIGN:
            tmp.operation = MINUS;
            break;
        case MULASSIGN:
            tmp.operation = MUL;
            break;
        case DIVASSIGN:
            tmp.operation = DIV;
            break;
        }

        // operation and assign
        tmp.addr[0] = _node->children[0]->place;
        tmp.type[0] = _node->children[0]->placeType;
        tmp.addr[1] = _node->children[1]->place;
        tmp.type[1] = _node->children[1]->placeType;
        tmp.res = _node->children[0]->place;
        insertTriple(tmp);

        _node->place = tmp.res;
        _node->placeType = _node->children[0]->placeType;
        return;
    }
    else if (nodeType == typeid(BitOrExpr) || nodeType == typeid(BitXorExpr)
        || nodeType == typeid(BitAndExpr) || nodeType == typeid(ShiftExpr)
        || nodeType == typeid(AddExpr) || nodeType == typeid(MulExpr)) {

        // type check
        if (_node->children[0]->placeType != _node->children[1]->placeType) {
            cout << "type error at line " << _node->lineno << "\n";
            exit(0);
        }
        tmp.operation = _node->type->attr.optype;
        tmp.addr[0] = _node->children[0]->place;
        tmp.type[0] = _node->children[0]->placeType;
        tmp.addr[1] = _node->children[1]->place;
        tmp.type[1] = _node->children[1]->placeType;
        tmp.res = "0[ebp" + to_string(dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail) + "]";
        dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail -= 4;
        insertTriple(tmp);

        _node->place = tmp.res;
        _node->placeType = _node->children[0]->placeType;
        return;
    }
    else if (nodeType == typeid(EqualExpr)
        || nodeType == typeid(NonEqualExpr)) {
        // type check
        if (_node->children[0]->placeType != _node->children[1]->placeType) {
            cout << "type error at line " << _node->lineno << "\n";
            exit(0);
        }
        // compare
        tmp.operation = CMP;
        tmp.addr[0] = _node->children[0]->place;
        tmp.type[0] = _node->children[0]->placeType;
        tmp.addr[1] = _node->children[1]->place;
        tmp.type[1] = _node->children[1]->placeType;
        insertTriple(tmp);
        // jump if true
        switch (_node->type->attr.optype) {
        case GE:
            tmp.operation = JGE;
            break;
        case GT:
            tmp.operation = JGT;
            break;
        case LE:
            tmp.operation = JLE;
            break;
        case LT:
            tmp.operation = JLT;
            break;
        case EQ:
            tmp.operation = JEQ;
            break;
        case NEQ:
            tmp.operation = JNEQ;
            break;
        }
        tmp.addr[0] = _node->type->trueLabel;
        insertTriple(tmp);
        // jump if false
        tmp.operation = JMP;
        tmp.addr[0] = _node->type->falseLabel;
        insertTriple(tmp);
    }
    else if (nodeType == typeid(PrefixExpr)) {
        // only int
        if (_node->children[0]->placeType != INT_T) {
            cout << "type error at line " << _node->lineno << "\n";
            exit(0);
        }
        if (_node->type->attr.optype == MINUS ||
            _node->type->attr.optype == BITNOT) {
            if (_node->type->attr.optype == MINUS) {
                tmp.operation = MINUS;
                tmp.res = "0[ebp" + to_string(dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail) + "]";
                dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail -= 4;

                tmp.addr[0] = "0";
                tmp.type[0] = INT_T;
                tmp.addr[1] = _node->children[0]->place;
                tmp.type[1] = _node->children[0]->placeType;
                insertTriple(tmp);
            }
            else {
                tmp.operation = _node->type->attr.optype;
                tmp.res = "0[ebp" + to_string(dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail) + "]";
                dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail -= 4;

                tmp.addr[0] = _node->children[0]->place;

                insertTriple(tmp);
            }
        }
        else if(_node->type->attr.optype == INC 
            || _node->type->attr.optype == DEC){
            if (_node->type->attr.optype == INC) {
                tmp.operation = ADD;
            }
            else if (_node->type->attr.optype == DEC) {
                tmp.operation = MINUS;
            }
            else {
                cout << "not gonna happen, dude!\n";
                exit(0);
            }
            tmp.addr[0] = _node->children[0]->place;
            tmp.type[0] = _node->children[0]->placeType;
            tmp.addr[1] = "1";
            tmp.type[1] = INT_T;
            tmp.res = _node->children[0]->place;
            insertTriple(tmp);
        }

        _node->place = tmp.res;
        _node->placeType = _node->children[0]->placeType;
    }
    else if (nodeType == typeid(PostfixExpr)) {
        if (_node->children[0]->placeType != INT_T) {
            cout << "type error at line " << _node->lineno << "\n";
            exit(0);
        }

        tmp.res = "0[ebp" + to_string(dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail) + "]";
        dynamic_cast<FuncDef*>(curFuncNode->type.get())->nxtAvail -= 4;

        tmp.operation = ASSIGN;
        tmp.addr[0] = _node->children[0]->place;
        tmp.type[0] = _node->children[0]->placeType;
        insertTriple(tmp);
        // set place of current node as temp
        // note that this is kind of special
        _node->place = tmp.res;
        _node->placeType = _node->children[0]->placeType;
        if (_node->type->attr.optype == INC) {
            tmp.operation = ADD;
        }
        else if (_node->type->attr.optype == DEC) {
            tmp.operation = MINUS;
        }
        else {
            cout << "not gonna happen, dude\n";
            exit(0);
        }
        tmp.addr[0] = _node->children[0]->place;
        tmp.type[0] = _node->children[0]->placeType;
        tmp.addr[1] = "1";
        tmp.type[1] = INT_T;
        tmp.res = _node->children[0]->place;
        insertTriple(tmp);
    }
    else if (nodeType == typeid(FuncCallExpr)) {
        int num_param;
        for (int i = 0; i < globalFuncTable.size(); ++i) {
            if (globalFuncTable[i].FuncName == _node->children[0]->type->attr.name) {
                num_param = globalFuncTable[i].paramType.size();
                break;
            }
        }
        recursivePushFuncCallParam(_node->children[1]);
        tmp.operation = CALL;
        tmp.addr[0] = _node->children[0]->type->attr.name;
        // add esp
        tmp.addr[1] = to_string(num_param*4);
        insertTriple(tmp);
    }
    else if (nodeType == typeid(IdUse)) {
        IdInfo info_;
        TableNode::lookupId(_node->type->attr.name, info_, dynamic_cast<IdUse*>(_node->type.get())->table);
        if (info_.offset < 0) {
            _node->place = "0[ebp" + to_string(info_.offset) + "]";
        }
        else if (info_.offset == 0) { // use offset = 0 to denote global variable
            _node->place = "_" + string(_node->type->attr.name);
        }
        else {
            _node->place = to_string(info_.offset) + "[ebp]";
        }
        _node->placeType = info_.idType;
    }
    else if (nodeType == typeid(IdDec)) {
        IdInfo info_;
        TableNode::lookupId(_node->type->attr.name, info_, dynamic_cast<IdDec*>(_node->type.get())->table);
        if (info_.offset < 0) {
            _node->place = "0[ebp" + to_string(info_.offset) + "]";
        }
        else if (info_.offset == 0) { // use offset = 0 to denote global variable
            _node->place = "_" + string(_node->type->attr.name);
        }
        else {
            _node->place = to_string(info_.offset) + "[ebp]";
        }
        _node->placeType = info_.idType;
    }
    else if (nodeType == typeid(INumUse)) {
        _node->place = to_string(_node->type->attr.intVal);
        _node->placeType = INT_T;
    }
    else if (nodeType == typeid(CharUse)) {
        _node->place = to_string(_node->type->attr.charVal);
        _node->placeType = CHAR_T;
    }
}


void GrammarTree::translateTripleAddr(ostream& os) {
    for (int i = 0; i < tripleAddrList.size(); ++i) {

        switch (tripleAddrList[i].operation) {
        case INPUT:
            os << "\tinvoke crt_scanf, OFFSET format, addr input_buffer\n";
            os << "\tmov eax, input_buffer\n";
            os << "\tmov " << tripleAddrList[i].addr[0] << ", eax\n";
            break;
        case PRINT:
            os <<"\tmov " <<"eax, "<<tripleAddrList[i].addr[0]<<"\n";
            os << "\tinvoke crt_printf, OFFSET format, eax\n";
            os << "\tinvoke crt_printf, OFFSET newline\n";
            break;
        case BEGINFUNC:
            os << tripleAddrList[i].addr[0]<<" proc\n";
            os << "\tpush ebp\n";
            os << "\tmov ebp, esp\n";
            os << "\tsub esp, " <<tripleAddrList[i].addr[1]<< "\n";
            break;
        case ENDFUNC:
            os << "\tadd esp, " << tripleAddrList[i].addr[1] << "\n";
            os << "\tpop ebp\n";
            os << "\tret\n";
            os <<tripleAddrList[i].addr[0] << " endp\n";
            break;
        case JMP:
            os << "\tjmp " << tripleAddrList[i].addr[0] << "\n";
            break;
        case ASSIGN:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if(tripleAddrList[i].type[0] == CHAR_T){
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }

            break;
        case ADD:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tadd eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tadd al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case MINUS:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tsub eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tsub al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case MUL:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov ebx, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmul ebx\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov bl, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmul bl\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case DIV:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov ebx, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tdiv ebx\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov bl, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tdiv bl\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case BITOR:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tor eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tor al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case BITXOR:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\txor eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\txor al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case BITAND:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tand eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tand al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case CMP:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov ebx, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tcmp eax, ebx\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tmov bl, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tcmp al, bl\n";
            }
            break;
        case LEFTSHIFT:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tshl eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tshl al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case RIGHTSHIFT:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tshr eax, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tshr al, " << tripleAddrList[i].addr[1] << "\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case BITNOT:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tnot eax\n";
                os << "\tmov " << tripleAddrList[i].res << ", eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tnot al\n";
                os << "\tmov " << tripleAddrList[i].res << ", al\n";
            }
            break;
        case JGT:
            os << "\tjg " << tripleAddrList[i].addr[0]<<"\n";
            break;
        case JGE:
            os << "\tjge " << tripleAddrList[i].addr[0] << "\n";
            break;
        case JLT:
            os << "\tjl " << tripleAddrList[i].addr[0] << "\n";
            break;
        case JLE:
            os << "\tjle " << tripleAddrList[i].addr[0] << "\n";
            break;
        case JEQ:
            os << "\tje " << tripleAddrList[i].addr[0] << "\n";
            break;
        case JNEQ:
            os << "\tjne " << tripleAddrList[i].addr[0] << "\n";
            break;
        case LABEL:
            os << tripleAddrList[i].addr[0] << ":\n";
            break;
        case CALL:
            os << "\tcall " << tripleAddrList[i].addr[0] <<"\n";
            os << "\tadd esp, " << tripleAddrList[i].addr[1] << "\n";
            break;
        case PUSH:
            if (tripleAddrList[i].type[0] == INT_T) {
                os << "\tmov eax, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tpush eax\n";
            }
            else if (tripleAddrList[i].type[0] == CHAR_T) {
                os << "\tmov al, " << tripleAddrList[i].addr[0] << "\n";
                os << "\tpush eax\n";
            }
            break;
        }
    }
}

void GrammarTree::printHeader(ostream& os) {
    os << "\t.586\n";
    os << "\t.model flat, stdcall\n";
    os << "\toption casemap : none\n";
    os << "\tinclude \\masm32\\macros\\macros.asm\n";
    os << "\tinclude    \\masm32\\include\\msvcrt.inc\n";
    os << "\tincludelib \\masm32\\lib\\msvcrt.lib\n";
    os << "\t.data\n";
    os << "\tformat db \"%d\",0\n";
    os << "\tinput_buffer DWORD ?\n";
    os << "\tnewline BYTE 13,10,0\n";
    // print global variable
    for (auto it = TableNode::curNode->table->begin();
        it != TableNode::curNode->table->end(); ++it) {
        int i;
        for (i = 0; i < globalFuncTable.size(); ++i) {
            if (globalFuncTable[i].FuncName == it->first) {
                break;
            }
        }
        if (i == globalFuncTable.size()) { // if not a function
            if (it->second.idType == INT_T) {
                os << "\t_" + it->first << " DWORD 0\n";
            }
            else if (it->second.idType == CHAR_T) {
                os << "\t_" + it->first << " BYTE 0\n";
            }
        }
    }
    os << "\t.code\n";
    os << "start:\n";
    os << "\tcall main\n";
    os << "\tinvoke crt__exit,0\n";
}

void GrammarTree::printEnd(ostream& os) {
    os << "end start\n";
}

void GrammarTree::genCode(ostream &os) {
    printHeader(os);
    translateTripleAddr(os);
    printEnd(os);
}

void GrammarTree::printTripleAddr() {
    for (int i = 0; i < tripleAddrList.size(); ++i) {
        cout <<"op: "<<tripleAddrList[i].operation 
            << "  addr1: " << tripleAddrList[i].addr[0] << "  addr2: "
            << tripleAddrList[i].addr[1] << "  res: " << tripleAddrList[i].res<<"\n";
    }
}


void GrammarTree::printTree() {
    printTree(root);
}


void GrammarTree::printTree(shared_ptr<GrammarNode> _node) {
    if(_node.get() == nullptr) {
        return;
    }
    _node->printNode();
    for(int i = 0; i < _node->children.size(); ++i) {
        printTree(_node->children[i]);
    }
}
