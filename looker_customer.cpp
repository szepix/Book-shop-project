#include "looker_customer.h"

LookerCustomer::LookerCustomer(string name, string surname, unsigned int cardId, double money)
    : Customer(name, surname, cardId, money) {}

LookerCustomer::LookerCustomer() : Customer() {}

LookerCustomer::~LookerCustomer() {}

void LookerCustomer::add_to_looked_at_books(Book& book) {
    looked_at_books.push_back(book);
}

void LookerCustomer::interaction(Book& book) {
    add_to_looked_at_books(book);
}

