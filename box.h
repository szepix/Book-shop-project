#ifndef BOX_H
#define BOX_H

#include <map>

#include "book.h"

using namespace std;

class Box {
    public:
        void add_book(Book& c);
        void delete_book(unsigned int id);
        Book& get_book(unsigned int id);
        const map<unsigned int, Book>& get_books() const;
        bool has_book_id(unsigned int id);
        virtual string to_string() const = 0;
        virtual ~Box() {};
    protected:
        map<unsigned int, Book> books;
};

#endif
