//
// Created by admin on 2019/3/13.
//

#include <string>
#include "Query.h"
#include "OrQuery.h"
#include "WordQuery.h"
#include "AndQuery.h"

Query::Query(const std::string &s) : q(new WordQuery(s)) {

}

Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<BaseQuery>(new OrQuery(lhs, rhs, "|"));
}

Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<BaseQuery>(new AndQuery(lhs, rhs, "&"));
}

