#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "queryText/QueryText.h"
#include "queryText/QueryResult.h"
#include "copy/CopyConstructor.h"
#include "copy/CopyOperator.h"

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

void copyTest(){
    CopyTest copy(1);
    std::cout<<"--------------"<<" CopyTest copy(1);"<<"--------------"<<std::endl;
    CopyTest copy2=copy;
    std::cout<<"--------------"<<" CopyTest copy2=copy;"<<"--------------"<<std::endl;
    //必须有拷贝或者移动构造函数,必须是存在切可以访问的
    CopyTest copy3=1;
    std::cout<<"--------------"<<"  CopyTest copy3=1;"<<"--------------"<<std::endl;
    CopyTest copy4;
    std::cout<<"--------------"<<"  CopyTest copy4;"<<"--------------"<<std::endl;
}

void copyTest2() {
    CopyOperator cs(1);
    CopyOperator cs1(2);
    cs=cs1;
    std::cout<<cs.getSize()<<std::endl;
    std::cout<<cs1.getSize()<<std::endl;
}
int main() {
    copyTest2();
    return 0;
}