#include <iostream>
#include <vector>
#include "salesman.h"

using namespace std;

bool Salesman::check_if_same(Salesman &obj, Salesman &obj2)
{
    bool same = 0;
    int checker = 0;
    if(obj.name == obj2.name) checker++;
    if(obj.surname == obj2.surname) checker++;
    if(obj.worker_id == obj2.worker_id) checker++;
    if(obj.permissions == obj2.permissions) checker++;
    if(obj.experience == obj2.experience) checker++;
    if(obj.salary == obj2.salary) checker++;
    for(int i=0; i<obj2.departments.size(); i++)
    {
        if(obj.departments.size() != obj2.departments.size()) break;
        if(obj.departments[i] == obj2.departments[i])
        {
            checker++;
        }
    }
    if(checker == (6 + obj2.departments.size())) same = 1;
    return same;
}
void Salesman::make_same(Salesman &obj)
{
    name = obj.name;
    surname = obj.surname;
    worker_id = obj.worker_id;
    permissions = obj.permissions;
    experience = obj.experience;
    salary = obj.salary;
    departments = obj.departments;
}

void Salesman::display_departments()
{
    std::cout<<"Worker's departments are: \n";
    for(int i=0; i<departments.size(); i++)
    {
        std::cout<<departments[i]<<endl;
    }
}

void Salesman::set_name(string new_name)
{
    name = new_name;
}
void Salesman::set_surname(string new_surname)
{
    surname = new_surname;
}
void Salesman::set_id(int new_id)
{
    worker_id = new_id;
}
void Salesman::set_permissions(unsigned int new_permissions)
{
    permissions = new_permissions;
}
void Salesman::set_experience(string new_experience)
{
    experience = new_experience;
}
void Salesman::set_salary(double new_salary)
{
    salary = new_salary;
}
void Salesman::add_department(string new_department)
{
    departments.push_back(new_department);
}
void Salesman::replace_departments(std::vector <string> new_list)
{
    departments = new_list;
}
void Salesman::remove_department(string department)
{
    for (int i = 0; i < departments.size(); i++) {
        if (departments[i] == department) {
            departments.erase(departments.begin() + i);
        }
    }
}
Salesman::Salesman(string name, string surname, int worker_id, unsigned int permissions, string experience, double salary,vector <string> departments) {
    this->name = name;
    this->surname = surname;
    this->worker_id = worker_id;
    this->permissions = permissions;
    this->experience = experience;
    this->departments = departments;
    this->salary = salary;
}
Salesman::Salesman(Salesman &obj) {
    this->name = obj.name;
    this->surname = obj.surname;
    this->worker_id = obj.worker_id;
    this->permissions = obj.permissions;
    this->experience = obj.experience;
    this->departments = obj.departments;
    this->salary = obj.salary;
}
bool operator != (Salesman &obj, Salesman &obj2)
{
    if(obj.check_if_same(obj, obj2) == 1) return 0;
    else return 1;
}


bool operator == (Salesman &obj, Salesman &obj2)
{
    if(obj.check_if_same(obj, obj2)) return 1;
    else return 0;
}
Salesman& Salesman::operator = (Salesman &obj)
{
    make_same(obj);
    return *this;
}
ostream& operator<<(ostream &strumien, Salesman &obj)
{
    cout<< "Worker's name is: "<< obj.name<<endl;
    cout<< "Worker's surname is: "<< obj.surname<<endl;
    cout<< "Worker's id is: "<< obj.worker_id<<endl;
    cout<< "Worker's permission is: "<< obj.permissions<<endl;
    cout<< "Worker's experience is: "<< obj.experience<<endl;
    cout<< "Worker's salary is: "<< obj.salary<<endl;
    obj.display_departments();
    return strumien;
}
