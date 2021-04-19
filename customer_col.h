#ifndef CUSTOMER_COL_H
#define CUSTOMER_COL_H

#include <map>

#include "customer.h"

using namespace std;

class CustomerCol {
    public:
        void add_customer(Customer& c);
        void delete_customer(int id);
        Customer& get_customer(int id);

        void entering_card_id(string text, int *number);
        void change_card_id(int oldId, int newId);
        void show_all();

        int select_customer();
        bool has_customer_id(int id);
        bool empty();
    private:
        map<int, Customer> customers;
};

#endif