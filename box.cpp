#include <iostream>
#include "box.h"
#include <map>
#include <sstream>

using namespace std;


void Box::add_book(Book& book){
    int bookId = book.getId();
    if(books.find(bookId) != books.end())
    {
        cout << "This number already exists" << endl;
    }
    else {
        books.insert(map<int, Book>::value_type(bookId, book));
    }
}

void Box::delete_book(int id) {
    map<int, Book>::iterator it = books.find(id);
    if (it != books.end()) {
        books.erase(it);
    }
    else {
        cout << "This book does not exist" << endl;
    }
}

Book& Box::get_book(int id) {
    return books.find(id)->second;
}

const map<int, Book>& Box::get_books() const {
    return books;
}

double Box::get_total_price() const {
    double sum = 0;
    map<int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        sum += it->second.getPrice();
    }
    return sum;
}

bool Box::has_book_id(int id){
    return books.find(id) != books.end();
}


