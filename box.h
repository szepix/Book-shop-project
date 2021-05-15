#ifndef BOX_H
#define BOX_H

#include <map>

#include "book.h"

using namespace std;

class Box {
    public:
        void add_book(Book& c);
        void delete_book(int id);
        Book& get_book(int id);
        const map<int, Book>& get_books() const;
        bool has_book_id(int id);
        double get_total_price() const;
        virtual string to_string() const = 0;
        virtual ~Box() {};
    private:
        map<int, Book> books;
};

#endif
