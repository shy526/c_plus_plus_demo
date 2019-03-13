//
// Created by admin on 2019/3/12.
//

#include "Basket.h"
#include <iostream>

bool Basket::compare(const std::shared_ptr<Quote> &l, const std::shared_ptr<Quote> &r) {
    return l->isbn()<r->isbn();
}

void Basket::addItem(const std::shared_ptr<Quote> &sale) {
    items.insert(sale);
}

double Basket::total_receipt(std::ostream &os) const {
    double  sum=0;
    //items.upper_bound(*iter) 跳过相同的关键字
    for(auto iter=items.cbegin();iter!=items.cend();iter=items.upper_bound(*iter)){
        sum+=printTotal(os, **iter, items.count(*iter));
    }
    return sum;
}

double Basket::printTotal(std::ostream &os, const Quote &item, std::size_t n) const  {
    double ret=item.net_price(n);
    os<<"买了"<<n<<"本编号"<<item.isbn()<<"的书,总价格是"<<ret<<"元"<<std::endl;
    return ret;
}

void Basket::addItem(Quote &q) {
    items.insert(std::shared_ptr<Quote> (q.clone()));
}

void Basket::addItem(Quote &&q) {
    items.insert(std::shared_ptr<Quote> (q.clone()));
}



