//
// Created by admin on 2019/1/11.
//

#ifndef C_DEMO_QUERYRESULT_H
#define C_DEMO_QUERYRESULT_H

#include <memory>
#include <set>
#include <vector>

class QueryResult{
    /**
     * 打印结果
     * 友员函数
     */
    friend void print(const QueryResult&);
public:
    using line_on=std::vector<std::string>::size_type;

    QueryResult( std::shared_ptr<std::set<line_on>> &s,
                 std::shared_ptr<std::vector<std::string>> &q, std::string c):indexes(s),file(q),key(c){

    };

private:
    /**
     * 记录的行号的集合
     */
    std::shared_ptr<std::set<line_on>> indexes;
    /**
     * 文本
     */
    std::shared_ptr<std::vector<std::string>> file;
    std::string key;
};
void print(const QueryResult&);
#endif //C_DEMO_QUERYRESULT_H
