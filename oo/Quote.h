//
// Created by admin on 2019/3/12.
//

#ifndef C_DEMO_QUOTE_H
#define C_DEMO_QUOTE_H


#include <string>

class Quote {
public:
    Quote()= default;
    explicit Quote(const std::string &bookNo, double price);
    virtual ~Quote() = default;
    virtual double net_price(std::size_t) const;
    virtual Quote * clone()const &;
    virtual Quote * clone() &&;
    std::string isbn() const ;
private:
    std::string bookNo;
protected:
    double price;
};


#endif //C_DEMO_QUOTE_H
