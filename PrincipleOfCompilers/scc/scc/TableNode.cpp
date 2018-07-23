//
// Created by yujunshi on 11/12/17.
//

#include "TableNode.h"
using namespace std;

bool TableNode::insertId(std::string idName, IdInfo info) {
    auto probe = curNode->table->find(idName);
    if (probe != curNode->table->end()) { // if this symbol has been inserted
        return false;
    }
    curNode->table->insert({idName, info});
    return true;
}

// iteratively look up
bool TableNode::lookupId(std::string idName, IdInfo &info) {
    shared_ptr<TableNode> working = curNode;
    auto probe = working->table->find(idName);
    while (probe == working->table->end()) {
        working = working->parent;
        if (working.get() == NULL) {
            return false;
        }
        probe = working->table->find(idName);
    }
    info = working->table->at(idName);
    return true;
}

bool TableNode::lookupId(std::string idName, IdInfo &info, shared_ptr<TableNode> start) {
    shared_ptr<TableNode> working = start;
    auto probe = working->table->find(idName);
    while (probe == working->table->end()) {
        working = working->parent;
        if (working.get() == NULL) {
            return false;
        }
        probe = working->table->find(idName);
    }
    info = working->table->at(idName);
    return true;
}

shared_ptr<TableNode> TableNode::curNode = make_shared<TableNode>();

void TableNode::moveDown() {
    shared_ptr<TableNode> tmp = make_shared<TableNode>();
    tmp->parent = curNode;
    // point to it's children
    curNode->children.push_back(tmp);
    curNode = tmp;
}
void TableNode::moveUp() {
    curNode = curNode->parent;
}

void TableNode::recursiveFillInOffset(shared_ptr<TableNode> _n, int& nxtAvail) {
    for (auto it = _n->table->begin(); it != _n->table->end(); ++it) {
        if(it->second.ifParam){
            continue;
        }
        else {
            it->second.offset = nxtAvail;
            // allocate 4 bytes for each
            nxtAvail -= 4;
        }
    }
    for (int i = 0; i < _n->children.size(); ++i) {
        recursiveFillInOffset(_n->children[i], nxtAvail);
    }
}

