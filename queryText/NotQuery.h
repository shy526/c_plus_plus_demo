//
// Created by admin on 2019/3/13.
//

#ifndef C_DEMO_NOTQUERY_H
#define C_DEMO_NOTQUERY_H

#include "Query.h"

class NotQuery : public BaseQuery{
    friend  Query operator~(const Query &);

    NotQuery(const Query &query) : query(query) {}

    QueryResult eval(QueryText &text) override ;

    std::string rep() const override {
        return "~ ("+query.rep()+")";
    }
    Query query;
};

Query operator~(const Query &x ) {
    return std::shared_ptr<BaseQuery>(new NotQuery(x));
}

#endif //C_DEMO_NOTQUERY_H
