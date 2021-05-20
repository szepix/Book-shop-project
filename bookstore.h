#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "section_col.h"
#include "person_col.h"
#include "salesman.h"
#include "customer.h"
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Bookstore
{
public:
    Bookstore(){};
    const SectionCol& get_sections() const {return sections;}
    const PersonCol<Salesman>& get_salesmen_database() const {return salesmen_database;}
    const PersonCol<Salesman>& get_salesmen_shop() const {return salesmen_shop;}
    const PersonCol<Customer>& get_customers_database() const {return customers_database;}
    const PersonCol<Customer>& get_customers_shop() const {return customers_shop;}
    //const Salesman& get_current_salesman() const {return current_salesman;}
    // void set_current_salesman(Salesman& new_salesman) {current_salesman = new_salesman;}
    void read_customer(string file);
    void read_salesmen(string file);
    void read_sections(string file);
    void read_books(string file);
    void add_customer_to_shop(unsigned int id);
    void add_salesman_to_shop(unsigned int id);




private:
    SectionCol sections;
    BooksCol books;
    PersonCol <Salesman> salesmen_shop;
    PersonCol <Salesman> salesmen_database;
    PersonCol <Customer> customers_shop;
    PersonCol <Customer> customers_database;
};
#endif