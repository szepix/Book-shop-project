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
    const map<string, Section>& get_sections() const {return sections.get_sections();}
    const map<unsigned int, Salesman>& get_salesmen_database() const {return salesmen_database.get_persons();}
    const map<unsigned int, Salesman>& get_salesmen_shop() const {return salesmen_shop.get_persons();}
    const map<unsigned int, Customer>& get_customers_database() const {return customers_database.get_persons();}
    const map<unsigned int, Customer>& get_customers_shop() const {return customers_shop.get_persons();}
    //const Salesman& get_current_salesman() const {return current_salesman;}
    // void set_current_salesman(Salesman& new_salesman) {current_salesman = new_salesman;}
    unsigned int get_time() const {return time;}
    void set_time(unsigned int new_time) {time = new_time;}
    void change_time(unsigned int minutes);
    void read_customer(string file);
    void read_salesmen(string file);
    void read_sections(string file);
    void read_books(string file);



private:
    SectionCol sections;
    BooksCol books;
    PersonCol <Salesman> salesmen_shop;
    PersonCol <Salesman> salesmen_database;
    PersonCol <Customer> customers_shop;
    PersonCol <Customer> customers_database;
    unsigned int time;  
};

#endif