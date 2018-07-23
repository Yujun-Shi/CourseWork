#pragma once

#include <string>

enum IdType{ INT_T, DOUBLE_T, FLOAT_T, CHAR_T, VOID_T, NON_ID_TYPE_T };

enum QualType { CONST_T, NON_QUAL_TYPE_T };

class IdInfo {
public:
    IdType idType;
    QualType qualType;
    int offset;
    bool ifParam;
public:
    IdInfo(IdType idType_, QualType qualType_) 
        : idType(idType_), qualType(qualType_) {}
    IdInfo() {
        idType = NON_ID_TYPE_T;
        qualType = NON_QUAL_TYPE_T;
        ifParam = false;
        offset = 0;
    }
    std::string toString() {
        std::string res = "";
        switch (qualType) {
        case CONST_T:
            res += "const ";
            break;
        default:
            break;
        }

        switch (idType) {
        case INT_T:
            res += "int ";
            break;
        case DOUBLE_T:
            res += "double ";
            break;
        case FLOAT_T:
            res += "float ";
            break;
        case CHAR_T:
            res += "char ";
            break;
        case VOID_T:
            res += "void ";
            break;
        default:
            break;
        }
        return res;
    }
};