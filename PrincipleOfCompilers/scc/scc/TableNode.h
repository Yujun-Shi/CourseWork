//
// Created by yujunshi on 11/12/17.
//


#ifndef TABLE_HIERARCHY_H
#define TABLE_HIERARCHY_H

#include <string>
#include <vector>
#include <memory>
#include "unordered_map"
#include "IdType.h"


typedef std::unordered_map<std::string, IdInfo> SymbolTable;

class TableNode {
public: // method
    TableNode() : parent(NULL) { table = std::make_shared<SymbolTable>(); }
    bool insertId(std::string idName, IdInfo type);
    bool lookupId(std::string idName, IdInfo &idType);
    static bool lookupId(std::string idName, IdInfo &idType, std::shared_ptr<TableNode> start);
public: // static field & method
    // handle the construction of the whole hierarchy
    std::shared_ptr<SymbolTable> table;
    static std::shared_ptr<TableNode> curNode;
    static void moveDown();
    static void moveUp();
    static void recursiveFillInOffset(std::shared_ptr<TableNode> _n, int& nxtAvail);
    std::vector<std::shared_ptr<TableNode>> children;
private: // field
    std::shared_ptr<TableNode> parent;
};


#endif // TABLE_HIERARCHY_H
