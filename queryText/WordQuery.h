//
// Created by admin on 2019/3/12.
//

#ifndef C_DEMO_WORDQUERY_H
#define C_DEMO_WORDQUERY_H


#include <string>
#include "Query.h"
#include "QueryText.h"

class WordQuery: public BaseQuery{
    friend class Query;
    WordQuery(const std::string &queryWord) : queryWord(queryWord) {}
    QueryResult eval( QueryText & t)   {
        return t.query(queryWord);
     }
    /**
     * 查询的string
     * @return
     */
     std::string rep() const {
        return queryWord;
     }
    std::string queryWord;

};
#endif //C_DEMO_WORDQUERY_H
