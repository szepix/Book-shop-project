#ifndef section_h
#define section_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "books_col.h"
//header działu!

class Section
{
    public:
        Section()
        {
            name = "Unknown";
            symbol = "Unknown";
            supervisor = "Unknown";
        }

        Section(string name, string symbol, string supervisor);

        Section(const Section &section)
        {
            name = section.name;
            symbol = section.symbol;
            supervisor = section.supervisor;
            books = section.books;
        }
        
        friend std::ostream& operator << (std::ostream& output, const Section &s);

        friend bool operator == (const Section &s1, const Section &s2);

        friend bool operator != (const Section &s1, const Section &s2);

        Section& operator=(const Section &s);

        void add_book(Book book);

        void del_book(unsigned int id);

        void change_symbol(std::string new_symbol);

        void change_name(std::string new_name);

        std::string get_name() const;

        std::string to_string() const;

        std::string get_symbol() const;

        const map<unsigned int, Book>& get_books() const;

    protected:
        BooksCol books;

        std::string name;

        std::string supervisor;

        std::string symbol;
};
#endif
