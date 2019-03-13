//
// Created by admin on 2019/3/12.
//

#include "Quote.h"

Quote::Quote(const std::string &bookNo, double price) : bookNo(bookNo), price(price) {}

double Quote::net_price(size_t n=1) const {
    return n*price;
}

std::string Quote::isbn() const {
    return bookNo;
}

Quote *Quote::clone() const &{
    return new Quote(*this);
}

Quote *Quote::clone() &&{
    return new Quote(std::move(*this));
}
