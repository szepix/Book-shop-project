#ifndef SALESMAN_H
#define SALESMAN_H
#include <iostream>
#include <vector>
#include "person.h"
#include "person_col.h"
class Salesman : public Person
{
public:
    Salesman(std::string name, std::string surname, unsigned int cardId, std::string permissions, unsigned int experience, double salary,std::vector <std::string> departments);
    Salesman(){};
    // Salesman(Salesman &obj);

    friend std::ostream& operator <<(std::ostream &strumien, Salesman &obj);

    
    bool check_if_same(const Salesman &obj,const Salesman &obj2) const;
    void make_same(Salesman &obj);
    double get_salary() const {return salary;}
    std::string get_permissions() const {return permissions;}

    unsigned int display_experience() const {return experience;}
    std::vector <std::string> get_departments() {return departments;}

    string to_string() const;

    void set_permissions(std::string new_permissions);
    void set_experience(unsigned int new_experience);
    void set_salary(double new_salary);
    void add_department(std::string new_department);
    void replace_departments(std::vector <std::string> new_list);
    void remove_department(std::string department);
    void display_departments();

    Salesman& operator = (const Salesman &obj);
    friend bool operator == (const Salesman &obj,const Salesman &obj2);
    friend bool operator != (const Salesman &obj,const Salesman &obj2);
    friend std::ostream& operator<<(std::ostream& strumien, const Salesman& obj);

private:
    
    std::vector <std::string> departments;

    std::string permissions;

    unsigned int experience;

    double salary;
};
#endif

