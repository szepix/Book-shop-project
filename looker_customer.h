#ifndef LOOKER_CUSTOMER_H
#define LOOKER_CUSTOMER_H

#include <vector>
#include "customer.h"
#include "book.h"

class LookerCustomer : public Customer
{
public:
    LookerCustomer(string name, string surname, unsigned int cardId, double money)
        : Customer(name, surname, cardId, money) {}
    LookerCustomer() : Customer() {}
    ~LookerCustomer() {}

    void add_to_looked_at_books(Book& book) {
        looked_at_books.push_back(book);
    }

    void interaction(Book& book) override {
        add_to_looked_at_books(book);
    }

private:
    vector<Book> looked_at_books;
};

#endif

