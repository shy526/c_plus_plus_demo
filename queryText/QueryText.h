//
// Created by admin on 2019/1/11.
//

#ifndef C_DEMO_QUERYTEXT_H
#define C_DEMO_QUERYTEXT_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
class QueryResult;
class QueryText {
public:
    typedef  std::vector<std::string>::size_type line_on;
    /**
     * 初始化并建立索引
     */
    explicit QueryText(std::ifstream &);
    /**
     * 查看已经建立的索引
     */
    void catIndexes();
    void catText();
    /**
     * 查询
     * @return  QueryResult
     */
    QueryResult query( const std::string &);
private:
    /**
     *记录行数据
     */

    std::shared_ptr<std::vector<std::string>>lines;
    /**
     *key: 单词
     *value:行号集合
     */

    std::map<std::string,std::shared_ptr<std::set<line_on>>> indexes;
    std:: string cleanup_str(const std::string &word) const
    {
        std::string ret;
        for (auto it = word.begin(); it != word.end(); ++it) {
            if (!ispunct(*it))
                ret += tolower(*it);
        }
        return ret;
    }
};


#endif //C_DEMO_QUERYTEXT_H
