#include <iostream>
#include <string>
#include <sstream>

#include "book.h"

Book::Book(string title, string author, int id, double price){
    this->title = title;
    this->author = author;
    this->id = id;
    this->price = price;
};

string Book::to_string() const {
    stringstream ss;
    ss << "Book(title: " << title << ", author: " << author << ", price: " << price << " zl , id: " << id << ")" << endl;
    return ss.str();
}

bool operator==(const Book& b1, const Book& b2){
    return (b1.id == b2.id);
}

ostream& operator<<(ostream& os, const Book& b){
    os << b.to_string();
    return os;
}