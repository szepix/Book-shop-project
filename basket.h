#ifndef BASKET_H
#define BASKET_H

#include <map>

#include "book.h"
#include "box.h"

using namespace std;

//class Basket - inherits from class Box
//Contains methods to getting total price and getting receipt

class Basket : public Box
{
public:
    double get_total_price() const;
    virtual string to_string() const;
    friend ostream& operator<<(ostream& os, const Basket& basket);
};

#endif
