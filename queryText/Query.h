//
// Created by admin on 2019/3/12.
//

#ifndef C_DEMO_QUERY_H
#define C_DEMO_QUERY_H


#include "QueryResult.h"
#include "QueryText.h"

/**
 * 查询抽象基类
 */
class BaseQuery {
    friend class Query;
private:
    /**
     * 返回匹配的QueryResult
     * @return QueryResult
     */
    virtual QueryResult eval( QueryText &)  = 0;
    /**
     * 查询的string
     * @return
     */
    virtual std::string rep() const = 0;

protected:
    typedef std::vector<std::string>::size_type line_on;
    virtual ~BaseQuery() = default;
};

/**
 * 管理BaseQuery的继承体系
 */
class Query {
    friend Query operator~(const Query &);

    friend Query operator|(const Query &, const Query &);

    friend Query operator&(const Query &, const Query &);

public:

    Query(const std::string &s);

    QueryResult eval( QueryText &t) const { return q->eval(t); }

    std::string rep() const {return q->rep();}

private:
    Query(std::shared_ptr<BaseQuery> query) : q(query) {};
    std::shared_ptr<BaseQuery> q;
};
inline std::ostream &operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

#endif //C_DEMO_QUERY_H
