#include <iostream>
#include <string>
#include <sstream>

#include "book.h"

Book::Book(string title, string author, string genre, unsigned int id, double price, unsigned int number){
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->id = id;
    this->price = price;
    this->number = number;
};

string Book::to_string() const {
    stringstream ss;
    ss << title << " - " << author << "   Price: " << price << " zl ";
    return ss.str();
}

bool operator==(const Book& b1, const Book& b2){
    return (b1.id == b2.id);
}

ostream& operator<<(ostream& os, const Book& b){
    os << b.to_string();
    return os;
}

void Book::set_title(string new_title)
{
    title = new_title;
}

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