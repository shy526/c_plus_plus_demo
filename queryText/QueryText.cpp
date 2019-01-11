//
// Created by admin on 2019/1/11.
//

#include "QueryText.h"
#include "QueryResult.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <set>
#include <algorithm>

using std::string;
using std::getline;
using std::istringstream;
using std::set;
using std::cout;
using std::endl;

QueryText::QueryText(std::ifstream &file) : lines(new std::vector<std::string>) {
    string row;
    while (getline(file, row)) {
        this->lines->push_back(row);
        istringstream rowStream(row);
        string word;
        while (rowStream >> word) {
            auto &index = this->indexes[cleanup_str(word)];
            if (!index) {
                index.reset(new set<line_on>);
            }
            index->insert(lines->size() - 1);

        }
    }

}

void QueryText::catIndexes() {
    auto begin = indexes.begin(), end = indexes.end();
    for (; begin != end; ++begin) {
        cout<<"--------------------"<< begin->first<<"----------------------"<<endl;
        auto item = begin->second;
        std::for_each(item->begin(), item->end(), [](line_on on) { cout << on << endl; });
    }
}

void QueryText::catText() {
    cout<<"--------------------"<<"正文"<<"----------------------"<<endl;
    std::for_each(lines->begin(), lines->end(), [](string v) { cout << v << endl; });
}

QueryResult QueryText::query(const std::string &key) {
    static std::shared_ptr<set<line_on >> nodata(new set<line_on >);
    auto result=this->indexes.find(cleanup_str(key));
    if (result == this->indexes.end()){
        return QueryResult(nodata,this->lines,key);
    }
    return QueryResult(result->second,this->lines,key);

}

void print(const QueryResult&qr){
   auto item = qr.indexes;

    cout<<"--------------------"<<"查询:"<<qr.key<<"查询结果"<<"----------------------"<<endl;
   std::for_each(item->begin(),item->end(),[qr](int v){
      cout << *(qr.file->begin() + v) <<endl;
   });
}

