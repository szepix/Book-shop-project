#ifndef BASKET_H
#define BASKET_H

#include <map>

#include "book.h"

using namespace std;

class Basket {
    public:
        void add_book(Book& c);
        void delete_book(int id);
        Book& get_book(int id);
        bool has_book_id(int id);
        double get_total_price() const;
        string to_string() const;
        friend ostream& operator<<(ostream& os, const Basket& basket);
    private:
        map<int, Book> books;
};

#endif
