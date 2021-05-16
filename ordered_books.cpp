#include <iostream>
#include "ordered_books.h"
#include <map>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, const OrderedBooks& basket) {
    os << basket.to_string();
    return os;
}
double OrderedBooks::get_total_price() const {
    double sum = 0;
    map<unsigned int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        sum += it->second.getPrice();
    }
    return sum;
}

string OrderedBooks::to_string() const {
    stringstream ss;
    ss << "Ordered books: \n";

    map<unsigned int, Book> books = get_books();
    map<unsigned int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        ss << it->second<<endl;
    }

    ss << "\nTotal price: " << get_total_price()<<" zl"<<endl;
    return ss.str();
}