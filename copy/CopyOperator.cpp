//
// Created by admin on 2019/1/12.
//

#include "CopyOperator.h"
#include <iostream>


CopyOperator &CopyOperator::operator=(const CopyOperator & value) {
    std::cout<<"赋值重载"<<std::endl;
    this->size=value.size;
    return *this;
}

int CopyOperator::getSize() const {
    return size;
}

CopyOperator::CopyOperator(int size) : size(size) {}
