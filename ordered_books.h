#ifndef ORDERED_BOOKS_H
#define ORDERED_BOOKS_H

#include <map>

#include "book.h"
#include "box.h"

using namespace std;

class OrderedBooks : public Box
{
public:
    virtual string to_string() const;
    friend ostream& operator<<(ostream& os, const OrderedBooks& basket);
};

#endif