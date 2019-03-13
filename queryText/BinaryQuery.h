//
// Created by admin on 2019/3/13.
//

#ifndef C_DEMO_BINARYQUERY_H
#define C_DEMO_BINARYQUERY_H

#include "Query.h"

/**
 * 二元操作都需要继承的接口
 */
class BinaryQuery : public BaseQuery {


protected:
    BinaryQuery(const Query &lhs, const Query &rhs, const std::string &opSym) : lhs(lhs), rhs(rhs), opSym(opSym) {};

    std::string rep() const override {
        return "(" + lhs.rep() + opSym + rhs.rep() + ")";
    }

    Query lhs, rhs;
    std::string opSym;

};

#endif //C_DEMO_BINARYQUERY_H
