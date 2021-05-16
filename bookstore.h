#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "section_col.h"
#include "person_col.h"
#include "salesman.h"
#include "customer.h"
#include <stdexcept>
class Bookstore
{
public:
    Bookstore(){};
    const map<string, Section>& get_sections() const {return sections.get_sections();}
    const map<unsigned int, Salesman>& get_salesmans() const {return salesmans.get_persons();}
    const map<unsigned int, Customer>& get_customers_database() const {return customers_database.get_persons();}
    const map<unsigned int, Customer>& get_customers_shop() const {return customers_shop.get_persons();}
    const Salesman& get_current_salesman() const {return current_salesman;}
    void set_current_salesman(Salesman& new_salesman) {current_salesman = new_salesman;}
    unsigned int get_time() const {return time;}
    void set_time(unsigned int new_time) {time = new_time;}
    void change_time(unsigned int minutes) 
    {
        int iteration = 0;
        if(minutes < 20)
        {
            throw out_of_range("Minutes should be bigger than 20");
        }
        iteration = minutes/20;
        set_time(iteration);
    }
private:
    SectionCol sections;
    Salesman current_salesman;
    PersonCol <Salesman> salesmans;
    PersonCol <Customer> customers_shop;
    PersonCol <Customer> customers_database;
    unsigned int time;  
};

#endif