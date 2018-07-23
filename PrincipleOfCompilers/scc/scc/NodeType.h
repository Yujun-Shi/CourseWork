#ifndef _NODETYPE_H_
#define _NODETYPE_H_

#ifndef OUTPUT_PADDING
#define OUTPUT_PADDING 20
#endif

#include "IdType.h"
#include "TableNode.h"
#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <string>


typedef std::string nodeStr;

union Attribute {
    int optype;
    int jmptype;
    int intVal;    // value of constant
    int pointerDegree;
    double floatVal;
    char charVal;
    char* name;
    Attribute() { floatVal = 0.0; }
};

class NodeType {
public: // field
    Attribute attr;
    std::string trueLabel;
    std::string falseLabel;
    std::string beginLabel;
    std::string nextLabel;

public: // method
    NodeType():trueLabel(""), falseLabel(""), nextLabel("") {}
    virtual NodeType* what() = 0; // pure virtual method that must be implemented
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~NodeType() {}
};

class TransUnit : public NodeType {
public:
    TransUnit(){}
    virtual TransUnit* what(){ return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~TransUnit() {}
};
class FuncDef : public NodeType {
public:
    FuncDef(){}
    virtual FuncDef* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~FuncDef() {};
public: // field
    std::shared_ptr<TableNode> idTable;
    int nxtAvail;
    int beginFuncInd;
};

class DecSpec : public NodeType {
public:
    DecSpec() {}
    virtual DecSpec* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~DecSpec() {}
public:
    std::list<int> typeSpecList;
    std::list<int> typeQualList;
};
class TypeSpec : public NodeType {
public:
    TypeSpec() {}
    virtual TypeSpec* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(attr.name); }
    virtual ~TypeSpec() {}
public:
    IdType typeSpecItem;
};
class TypeQual : public NodeType {
public:
    TypeQual() {}
    virtual TypeQual* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(attr.name); }
    virtual ~TypeQual() {}
public:
    QualType typeQualItem;
};
class Declarator : public NodeType {
public:
    Declarator() {}
    virtual Declarator* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~Declarator() {}
};
class DirDeclarator : public NodeType {
public:
    DirDeclarator() {}
    virtual DirDeclarator* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~DirDeclarator() {}
};
class FuncDeclarator : public NodeType {
public:
    FuncDeclarator() {}
    virtual FuncDeclarator* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~FuncDeclarator() {}
};
class ParamList : public NodeType {
public:
    ParamList() {}
    virtual ParamList* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~ParamList() {}
};
class ParamDec : public NodeType {
public:
    ParamDec() {}
    virtual ParamDec* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~ParamDec() {}
};
class Dec : public NodeType {
public:
    Dec() {}
    virtual Dec* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~Dec() {}
};
class InitDecList : public NodeType {
public:
    InitDecList() {}
    virtual InitDecList* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~InitDecList() {}
};
class InitDec : public NodeType {
public:
    InitDec() {}
    virtual InitDec* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~InitDec() {}
};
class Expr : public NodeType {
public:
    Expr() {}
    virtual Expr* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~Expr() {}
};
class AssignExpr : public NodeType {
public:
    AssignExpr() {}
    virtual AssignExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~AssignExpr() {}
};
class EqualExpr : public NodeType {
public:
    EqualExpr() {}
    virtual EqualExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~EqualExpr() {}
};
class AddExpr : public NodeType {
public:
    AddExpr() {}
    virtual AddExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~AddExpr() {}
};
class MulExpr : public NodeType {
public:
    MulExpr() {}
    virtual MulExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~MulExpr() {}
};
class PrefixExpr : public NodeType {
public:
    PrefixExpr() {}
    virtual PrefixExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~PrefixExpr() {}
};
class PostfixExpr : public NodeType {
public:
    PostfixExpr() {}
    virtual PostfixExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~PostfixExpr() {}
};

class LogOrExpr : public NodeType {
public:
    LogOrExpr() {}
    virtual LogOrExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~LogOrExpr() {}
};
class LogAndExpr : public NodeType {
public:
    LogAndExpr() {}
    virtual LogAndExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~LogAndExpr() {}
};

class BitOrExpr : public NodeType {
public:
    BitOrExpr() {}
    virtual BitOrExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~BitOrExpr() {}
};
class BitXorExpr : public NodeType {
public:
    BitXorExpr() {}
    virtual BitXorExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~BitXorExpr() {}
};
class BitAndExpr : public NodeType {
public:
    BitAndExpr() {}
    virtual BitAndExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~BitAndExpr() {}
};
class NonEqualExpr : public NodeType {
public:
    NonEqualExpr() {}
    virtual NonEqualExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~NonEqualExpr() {}
};
class ShiftExpr : public NodeType {
public:
    ShiftExpr() {}
    virtual ShiftExpr* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.optype); }
    virtual ~ShiftExpr() {}
};

class InputStmt : public NodeType {
public:
    InputStmt() {}
    virtual InputStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~InputStmt() {}
};

class PrintStmt : public NodeType {
public:
    PrintStmt() {}
    virtual PrintStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~PrintStmt() {}
};

class CmpStmt : public NodeType {
public:
    CmpStmt() {}
    virtual CmpStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~CmpStmt() {}
};
class BlockItemList : public NodeType {
public:
    BlockItemList() {}
    virtual BlockItemList* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~BlockItemList() {}
};
class IterStmt : public NodeType {
public:
    IterStmt() {}
    virtual IterStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~IterStmt() {}
};
class SelStmt : public NodeType {
public:
    SelStmt() {}
    virtual SelStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~SelStmt() {}
};
class JmpStmt : public NodeType {
public:
    JmpStmt() {}
    virtual JmpStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~JmpStmt() {}
};
class IdUse : public NodeType {
public:
    IdUse() {}
    virtual IdUse* what() { return this; }
    virtual nodeStr printAttr() {
        nodeStr id_name = nodeStr(attr.name);
        IdInfo id_info;
        TableNode::lookupId(id_name, id_info, table);
        return id_info.toString()  + " " + id_name;
    }
    virtual ~IdUse()
    {
        if (attr.name != NULL) 
            delete attr.name;
    }
public: // field
    std::shared_ptr<TableNode> table;
};

class IdDec : public NodeType {
public:
    IdDec() {}
    virtual IdDec* what() { return this; }
    virtual nodeStr printAttr() {
        nodeStr id_name = nodeStr(attr.name);
        IdInfo id_info;
        std::shared_ptr<SymbolTable> t = table->table;
        id_info = t->at(id_name);
        return id_info.toString() + " " + id_name;
    }
    virtual ~IdDec()
    {
        if (attr.name != NULL)
            delete attr.name;
    }
public: // field
    std::shared_ptr<TableNode> table;
};

class INumUse : public NodeType {
public:
    INumUse() {}
    virtual INumUse* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.intVal); }
    virtual ~INumUse() {}
};

class FNumUse : public NodeType {
public:
    FNumUse(){}
    virtual FNumUse* what(){ return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.floatVal); }
    virtual ~FNumUse() {}
};

class CharUse : public NodeType {
public:
    CharUse() {}
    virtual CharUse* what() { return this; }
    virtual nodeStr printAttr() { return ""; }
    virtual ~CharUse() {}
};

class PointerUse : public NodeType {
public:
    PointerUse() {}
    virtual PointerUse* what() { return this; }
    virtual nodeStr printAttr() { return std::to_string(attr.pointerDegree); }
    virtual ~PointerUse() {}
};

class StringUse : public NodeType {
public:
    StringUse() {}
    virtual StringUse* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(attr.name); }
    virtual ~StringUse(){
        if (attr.name != NULL)
            delete attr.name;
    }
};

class FuncCallExpr : public NodeType {
public:
    FuncCallExpr(){}
    virtual FuncCallExpr* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~FuncCallExpr() {}
};

class ArgExprList : public NodeType{
public:
    ArgExprList() {}
    virtual ArgExprList* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~ArgExprList() {}
};

class EmptyStmt : public NodeType {
public:
    EmptyStmt() {}
    virtual EmptyStmt* what() { return this; }
    virtual nodeStr printAttr() { return nodeStr(""); }
    virtual ~EmptyStmt() {}
};

#endif
