#include <iostream>
#include "basket.h"
#include <map>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, const Basket& basket) {
    os << basket.to_string();
    return os;
}

string Basket::to_string() const {
    stringstream ss;
    ss << "Basket: \n";

    map<unsigned int, Book> books = get_books();
    map<unsigned int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        ss << it->second<<endl;
    }

    ss << "\nTotal price: " << get_total_price()<<" zl"<<endl;
    return ss.str();
}

double Basket::get_total_price() const {
    double sum = 0;
    map<unsigned int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        sum += it->second.getPrice();
    }
    return sum;
}