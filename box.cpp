#include <iostream>
#include "box.h"
#include <map>
#include <sstream>

using namespace std;


void Box::add_book(Book& book){
    int bookId = book.getId();
    books.insert(map<unsigned int, Book>::value_type(bookId, book));
}

void Box::delete_book(unsigned int id) {
    map<unsigned int, Book>::iterator it = books.find(id);
    if (it != books.end()) {
        books.erase(it);
    }
    else {
        cout << "This book does not exist" << endl;
    }
}

Book& Box::get_book(unsigned int id) {
    return books.find(id)->second;
}

const map<unsigned int, Book>& Box::get_books() const {
    return books;
}


bool Box::has_book_id(unsigned int id){
    return books.find(id) != books.end();
}


