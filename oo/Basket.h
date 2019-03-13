//
// Created by admin on 2019/3/12.
//

#ifndef C_DEMO_BASKET_H
#define C_DEMO_BASKET_H


#include <set>
#include <memory>
#include "Quote.h"

class Basket {
public:
    Basket()= default;

    void addItem(const std::shared_ptr<Quote> &);
    //拷贝
    void addItem(Quote &);
    //移动
    void addItem(Quote &&);

    double  total_receipt(std::ostream&) const;
    double printTotal(std::ostream &, const  Quote&,std::size_t)  const ;
private:
    static bool compare(const std::shared_ptr<Quote> &,const std::shared_ptr<Quote> &);
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>  items{compare};
};


#endif //C_DEMO_BASKET_H
