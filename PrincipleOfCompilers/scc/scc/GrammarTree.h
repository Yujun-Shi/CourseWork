#ifndef _GRAMMARTREE_H_
#define _GRAMMARTREE_H_

#ifndef OUTPUT_PADDING
#define OUTPUT_PADDING 20
#endif

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <memory>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "NodeType.h"
#include "TableNode.h"

// extra defines support for TripleAddr operation part!!!
// apart from all these add, minus stuff
#define BEGINFUNC 1000
#define ENDFUNC 1001
#define LABEL 1002
#define DECVAR 1003
#define CMP 1004
#define JMP 1005

#define JEQ 1006
#define JNEQ 1007
#define JLE 1008
#define JGE 1009
#define JLT 1010
#define JGT 1011

#define CALL 1012
#define PUSH 1013

struct TripleAddr {
    int operation;
    IdType type[2];
    std::string addr[2];
    std::string res;
    TripleAddr() {
        type[0] = NON_ID_TYPE_T;
        type[1] = NON_ID_TYPE_T;
    }
};

struct FuncTableEntry {
    std::string FuncName;
    IdType returnType;
    std::vector<IdType> paramType;
    std::vector<std::string> paramNames;
};

/*
struct GlobalDec {
    IdType type;
    std::string id_name;
};
*/

class GrammarNode {
public: // field
    std::shared_ptr<NodeType> type;
    std::vector<std::shared_ptr<GrammarNode> > children;
    int lineno;
    
    std::string place;
    IdType placeType;

public: // method
    GrammarNode(NodeType* type_, int num_children, int lineno_) {
        type = std::shared_ptr<NodeType>(type_);
        children = std::vector<std::shared_ptr<GrammarNode> >(num_children);
        lineno = lineno_;
    }
    void printNode(){
        std::cout << this << ": " << std::right << 
            std::setw(OUTPUT_PADDING)<<typeid(*type->what()).name();
        std::cout<<std::right << std::setw(OUTPUT_PADDING) <<
            type->printAttr() << std::right << std::setw(OUTPUT_PADDING)<< "children: ";
        for(int i = 0; i < children.size(); ++i) {
            std::cout << children[i].get() << " ";
        }
        std::cout<<'\n';
    }
};

class GrammarTree {
public: // method
    GrammarTree() : root(nullptr) {}
    void printTree();

    // ID info utils
    static void obtainIdInfo(std::shared_ptr<GrammarNode> _node);
    static void fixIdInfo(std::shared_ptr<GrammarNode> _node, bool ifParam_ = false);
    static void resetIdInfo();

    // triple address code translate utils
    // first, we only consider simple operation
    static void insertTriple(TripleAddr addr);
    static void recursiveBuildTripleAddr(std::shared_ptr<GrammarNode> _g);
    static void recursiveFillInParam(FuncTableEntry& e, std::shared_ptr<GrammarNode> _node);
    static void recursivePushFuncCallParam(std::shared_ptr<GrammarNode> _node);
    static void printHeader(std::ostream& os);
    static void translateTripleAddr(std::ostream& os);
    static void printEnd(std::ostream& os);
    static void genCode(std::ostream& os);
    static void printTripleAddr();

    // label util
    static std::string newLabel();

    // global declaration utils
    // static std::vector<GlobalDec> globalDecList;

public: // field
    // ID info utils
    static IdInfo info;
    
    // triple address code translate utils
    // optimization of temp variable!
    static std::vector<TripleAddr> tripleAddrList;
    
    std::shared_ptr<GrammarNode> root;
   
    // label util
    static int nxtLabel;
    static std::shared_ptr<GrammarNode> curFuncNode;

    // global function table
    static std::vector<FuncTableEntry> globalFuncTable;

private: // method
    void printTree(std::shared_ptr<GrammarNode> _node);
};

extern int curLineNo;
extern char* curID;
extern char* curString;
extern int curInt;
extern double curFloat;
extern bool extraAreaSupportSwitch;
extern char curChar;

#endif
