#include <iostream>
#include <string>
#include <sstream>

#include "book.h"

Book::Book(string title, string author, string genre, unsigned int id, double price, unsigned int number) : title(title), author(author), genre(genre), id(id), price(price), number(number) {}

string Book::to_string() const { return "Id: " + std::to_string(id) + "   Title: " + title + " - " + author + "   Price: " + std::to_string(price) + " zl " + "   Number of books: " + std::to_string(number); }

Book& Book::operator=(const Book& b) {
    if (this != &b) {
        title = b.title;
        author = b.author;
        genre = b.genre;
        id = b.id;
        price = b.price;
        number = b.number;
    }
    return *this;
}


friend bool operator==(const Book& b1, const Book& b2) { return (b1.id == b2.id); }
friend ostream& operator<<(ostream& os, const Book& b) { os << b.to_string(); return os; }

Book& Book::set_title(string new_title) { title = new_title; return *this; }

void Book::set_genre(string new_genre)
{
    genre = new_genre;
}

void Book::set_author(string new_author)
{
    author = new_author;
}

void Book::set_id(unsigned int new_Id)
{
    id = new_Id;
}

void Book::set_price(double new_price)
{
    price = new_price;
}

void Book::set_number(unsigned int new_number)
{
    number = new_number;
}