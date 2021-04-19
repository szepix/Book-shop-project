#ifndef MENU_H
#define MENU_H

#include "customer_col.h"

enum program_operations{
    choosed_client = 1,
    add_client = 2,
    show_all_clients = 3,
    copy_allocate_test = 4,
    program_end = 5,
};

enum customer_operations{
    show_client = 1,
    change_client_data,
    change_client_basket,
    remove_client
};

enum data_operations{
    client_name = 1,
    client_surname,
    client_cardId,
    client_age,
    client_cash,
    client_preferences
};

enum book_operations{
    add_book = 1,
    remove_book,
};

enum preferences_operations{
    add_preference = 1,
    remove_preference = 2
};

enum testing_operations{
    copy_customer = 1,
    allocate_customer,
};


class Menu {
public:
    Menu(CustomerCol& customers) : customers(customers) {};

	void run();
    void show_all_customers(CustomerCol& customers);
    void show_customer(CustomerCol& customers, int cardId);
    void change_customer_data(CustomerCol& customers, int cardId);
    void set_customer_name(CustomerCol& customers, int cardId);
    void set_customer_surname(CustomerCol& customers, int cardId);
    void set_customer_cardId(CustomerCol& customers, int cardId);
    void set_customer_age(CustomerCol& customers, int cardId);
    void set_customer_cash(CustomerCol& customers, int cardId);
    void change_customer_preferences(CustomerCol& customers, int cardId);
    void add_customer_preferences(CustomerCol& customers, int cardId);
    void remove_customer_preference(CustomerCol& customers, int cardId);
    void change_basket(CustomerCol& customers, int cardId);
    void add_book_to_basket(CustomerCol& customers, int cardId);
    void remove_book_from_basket(CustomerCol& customers, int cardId);
    void remove_customer(CustomerCol& customers, int cardId);
    void add_customer(CustomerCol& customers);
    Customer entering_new_customer();
    void end_program();
    void test_copying_and_allocation();
    void test_copying(Customer& c1);
    void test_allocation(Customer& c1);

private:
	CustomerCol& customers;
};

#endif