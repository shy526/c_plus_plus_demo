//
// Created by admin on 2019/1/12.
//

#include "CopyConstructor.h"
#include "iostream"
CopyTest::CopyTest(int value):value(value) {
    std::cout<<"--------------"<<"执行构造函数"<<"--------------"<<std::endl;
}



CopyTest::CopyTest(const CopyTest &v):value(v.value) {
    std::cout<<"--------------"<<"执行拷贝函数"<<"--------------"<<std::endl;
}


int CopyTest::getValue() const {
    return value;
}


CopyTest::CopyTest() {
    std::cout<<"--------------"<<"执行默认构造函数"<<"--------------"<<std::endl;
}
