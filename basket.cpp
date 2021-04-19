#include <iostream>
#include "basket.h"
#include <map>
#include <sstream>

using namespace std;

void Basket::add_book(Book& book){
    int bookId = book.getId();
    if(books.find(bookId) != books.end())
    {
        cout << "This number already exists" << endl;
    }
    else {
        books.insert(map<int, Book>::value_type(bookId, book));
    }
}

void Basket::delete_book(int id) {
    map<int, Book>::iterator it = books.find(id);
    if (it != books.end()) {
        books.erase(it);
    }
    else {
        cout << "This book does not exist" << endl;
    }
}

Book& Basket::get_book(int id) {
    return books.find(id)->second;
}

double Basket::get_total_price() const {
    double sum = 0;
    map<int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        sum += it->second.getPrice();
    }
    return sum;
}

bool Basket::has_book_id(int id){
    return books.find(id) != books.end();
}

ostream& operator<<(ostream& os, const Basket& basket) {
    os << basket.to_string();
    return os;
}

string Basket::to_string() const {
    stringstream ss;
    ss << "Basket: \n";

    map<int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        ss << it->second;
    }

    ss << "\ntotal_price = " << get_total_price()<<" zl"<<endl;
    return ss.str();
}