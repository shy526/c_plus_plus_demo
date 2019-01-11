#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "queryText/QueryText.h"
#include "queryText/QueryResult.h"
using std::ifstream;
using std::string;
/**
 * 查询
 * @return
 */
void queryTextTest(){
    string filePath="./../data/queryTextData.txt";
    ifstream file(filePath);
    QueryText query(file);
    query.catIndexes();
    query.catText();
    auto result= query.query("she");
    print(result);
}

int main() {
    queryTextTest();
    return 0;
}