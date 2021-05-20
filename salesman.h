#ifndef SALESMAN_H
#define SALESMAN_H
#include <iostream>
#include <vector>
#include "person.h"
#include "person_col.h"
#include "customer.h"
using namespace std;
class Salesman : public Person
{
public:
    Salesman(string name, string surname, unsigned int cardId, string permissions, unsigned int experience,vector <string> departments);
    Salesman(){};
    // Salesman(Salesman &obj);

    friend ostream& operator <<(ostream &strumien, Salesman &obj);


    bool check_if_same(const Salesman &obj,const Salesman &obj2) const;
    void make_same(Salesman &obj);
    string get_permissions() const {return permissions;}

    unsigned int display_experience() const {return experience;}
    vector<string> get_departments() {return departments;}

    const Customer& get_customer() const {return customer;}
    string to_string() const;

    void set_permissions(string new_permissions);
    void set_experience(unsigned int new_experience);
    void set_customer(Customer new_customer);
    void add_department(string new_department);
    void replace_departments(vector <string> new_list);
    void remove_department(string department);
    void display_departments();

    Salesman& operator = (const Salesman &obj);
    friend bool operator == (const Salesman &obj,const Salesman &obj2);
    friend bool operator != (const Salesman &obj,const Salesman &obj2);
    friend ostream& operator<<(ostream& strumien, const Salesman& obj);

private:

    vector<string> departments;

    string permissions;

    unsigned int experience;

    Customer customer;
};
#endif

