#ifndef BASKET_H
#define BASKET_H

#include <map>

#include "book.h"
#include "box.h"

using namespace std;

class Basket : public Box
{
public:
    virtual string to_string() const;
    friend ostream& operator<<(ostream& os, const Basket& basket);
};

#endif
