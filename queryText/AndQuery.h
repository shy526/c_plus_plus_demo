//
// Created by admin on 2019/3/13.
//

#ifndef C_DEMO_ANDQUERY_H
#define C_DEMO_ANDQUERY_H

#include "BinaryQuery.h"
#include <algorithm>

/**
 * and 操作
 */
class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &lhs, const Query &rhs, const std::string &opSym) : BinaryQuery(lhs, rhs, opSym) {};

    QueryResult eval(QueryText &text) override {
        auto r = rhs.eval(text);
        auto l = lhs.eval(text);
        std::shared_ptr<std::set<line_on>> result = std::make_shared<std::set<line_on>>();
        std::set_intersection(
                r.getIndexes()->begin(),
                r.getIndexes()->end(),
                l.getIndexes()->begin(),
                l.getIndexes()->end(),
                std::inserter(*result,
                result->begin()));

        std::shared_ptr<std::vector<std::string>> file = l.getFile();
        return QueryResult(result, file, rep());
    }
};


#endif //C_DEMO_ANDQUERY_H
