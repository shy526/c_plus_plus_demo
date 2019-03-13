//
// Created by admin on 2019/3/13.
//

#ifndef C_DEMO_ORQUERY_H
#define C_DEMO_ORQUERY_H

#include "BinaryQuery.h"
/**
 * or 操作
 */
class OrQuery : public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &lhs, const Query &rhs, const std::string &opSym) : BinaryQuery(lhs, rhs, opSym) {};

    QueryResult eval(QueryText &text) override {
        const QueryResult &r = rhs.eval(text);
        const QueryResult &l = lhs.eval(text);
         std::shared_ptr<std::set<line_on>> result = std::make_shared<std::set<line_on>>(r.getIndexes()->begin(), r.getIndexes()->end());
        result->insert(l.getIndexes()->begin(),l.getIndexes()->end());
        std::shared_ptr<std::vector<std::string>> file = l.getFile();
        return QueryResult(result,file,rep());
    }
};


#endif //C_DEMO_ORQUERY_H
