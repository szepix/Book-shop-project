#include <iostream>
#include <vector>
#include "salesman.h"
#include <sstream>
using namespace std;

bool Salesman::check_if_same (const Salesman &obj,const Salesman &obj2) const
{
    bool same = 0;
    int checker = 0;
    if(obj.name == obj2.name) checker++;
    if(obj.surname == obj2.surname) checker++;
    if(obj.cardId == obj2.cardId) checker++;
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
// void Salesman::make_same(Salesman &obj)
// {
//     name = obj.name;
//     surname = obj.surname;
//     cardId = obj.cardId;
//     permissions = obj.permissions;
//     experience = obj.experience;
//     salary = obj.salary;
//     departments = obj.departments;
// }

void Salesman::display_departments()
{
    std::cout<<"Worker's departments are: \n";
    for(int i=0; i<departments.size(); i++)
    {
        std::cout<<departments[i]<<endl;
    }
}

void Salesman::set_permissions(string new_permissions)
{
    permissions = new_permissions;
}
void Salesman::set_experience(unsigned int new_experience)
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
};
Salesman::Salesman(string name, string surname, unsigned int cardId,string permissions, unsigned int experience, double salary,vector <string> departments) : Person(name, surname, cardId) 
{
    this->permissions = permissions;
    this->experience = experience;
    this->departments = departments;
    this->salary = salary;
};

// Salesman::Salesman(Salesman &obj)
// {
//     this->name = obj.name;
//     this->surname = obj.surname;
//     this->cardId = obj.cardId;
//     this->permissions = obj.permissions;
//     this->experience = obj.experience;
//     this->departments = obj.departments;
//     this->salary = obj.salary;
// };

string Salesman::to_string() const {
    stringstream ss;
    ss<< "Worker's name is: "<< name<<endl;
    ss<< "Worker's surname is: "<< surname<<endl;
    ss<< "Worker's id is: "<< cardId<<endl;
    ss<< "Worker's permission is: "<< permissions<<endl;
    ss<< "Worker's experience is: "<< experience<<endl;
    ss<< "Worker's salary is: "<< salary<<endl;
    return ss.str();
}
bool operator != (const Salesman &obj,const Salesman &obj2)
{
    if(obj.check_if_same(obj, obj2) == 1) return 0;
    else return 1;
}


bool operator == (const Salesman &obj,const Salesman &obj2)
{
    if(obj.check_if_same(obj, obj2)) return 1;
    else return 0;
}

Salesman& Salesman::operator = (const Salesman &obj)
{
    if(this!=&obj)
    {
        name = obj.name;
        surname = obj.surname;
        cardId = obj.cardId;
        permissions = obj.permissions;
        experience = obj.experience;
        salary = obj.salary;
        departments = obj.departments;
    }

    return *this;
}

ostream& operator<<(ostream &strumien, Salesman &obj)
{
    strumien << obj.to_string();
    return strumien;
}