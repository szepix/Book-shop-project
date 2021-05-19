#ifndef section_h
#define section_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "books_col.h"
//header działu!

using namespace std;

class Section
{
    public:
        Section() {};

        Section(string name, string symbol);

        Section(const Section &section)
        {
            name = section.name;
            symbol = section.symbol;
            supervisor = section.supervisor;
            books = section.books;
        }
        
        friend ostream& operator << (ostream& output, const Section &s);

        friend bool operator == (const Section &s1, const Section &s2);

        friend bool operator != (const Section &s1, const Section &s2);

        Section& operator=(const Section &s);

        void add_book(Book book);

        void add_supervisor(unsigned int id);

        void del_book(unsigned int id);

        void change_symbol(string new_symbol);

        void change_name(string new_name);

        string get_name() const;

        string to_string() const;

        string get_symbol() const;

        const map<unsigned int, Book>& get_books() const;

    protected:
        BooksCol books;
        string name;
        vector<unsigned int> supervisor;
        string symbol;
};
#endif
