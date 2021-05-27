#ifndef section_h
#define section_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "books_col.h"

using namespace std;

// Class Section contains private variables such as:
// - books
// - name
// - supervisor
// - symbol
// An object of class Section represents a section in a bookstore

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
    // operators overloading
    friend ostream& operator << (ostream& output, const Section &s);
    friend bool operator == (const Section &s1, const Section &s2);
    friend bool operator != (const Section &s1, const Section &s2);
    Section& operator=(const Section &s);

    // methods to add and delete books from section
    void add_book(Book book);
    void del_book(unsigned int id);

    // adding the supervisor who is responsible for this section
    void add_supervisor(unsigned int id);

    // setters of variables
    void set_symbol(string new_symbol);
    void set_name(string new_name);

    // getters of variables
    string get_name() const;
    string get_symbol() const;
    const map<unsigned int, Book>& get_books() const;

    // convert section's data to string
    string to_string() const;

protected:
    BooksCol books;
    string name;
    vector<unsigned int> supervisor;
    string symbol;
};
#endif
