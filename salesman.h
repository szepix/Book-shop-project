#ifndef SALESMAN_H
#define SALESMAN_H
#include <iostream>
#include <vector>

class Salesman
{
public:
    std::vector <std::string> departments;

    std::string name;

    std::string surname;

    unsigned int worker_id;

    unsigned int permissions;

    std::string experience;

    double salary;

    Salesman(std::string name, std::string surname, int worker_id, unsigned int permissions, std::string experience, double salary,std::vector <std::string> departments);
    Salesman(Salesman &obj);

    friend std::ostream& operator <<(std::ostream &strumien, Salesman &obj);

    std::string get_name() {return name;}
    bool check_if_same(Salesman &obj, Salesman &obj2);
    void make_same(Salesman &obj);
    double get_salary() {return salary;}
    std::string get_surname() {return surname;}
    unsigned int get_id() {return worker_id;}
    unsigned int get_permissions() {return permissions;}
    std::string display_experience() {return experience;}
    std::vector <std::string> get_departments() {return departments;}
    void set_surname(std::string new_surname);
    void set_name(std::string new_name);
    void set_id(int new_id);
    void set_permissions(unsigned int new_permissions);
    void set_experience(std::string new_experience);
    void set_salary(double new_salary);
    void add_department(std::string new_department);
    void replace_departments(std::vector <std::string> new_list);
    void remove_department(std::string department);
    void display_departments();
    Salesman& operator = (Salesman &obj);
    friend bool operator == (Salesman &obj, Salesman &obj2);
    friend bool operator != (Salesman &obj, Salesman &obj2);
    friend std::ostream& operator<<(std::ostream& strumien, const Salesman& obj);
};
#endif

