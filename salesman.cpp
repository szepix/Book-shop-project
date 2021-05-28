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
    for(int i=0; i<obj2.departments.size(); i++)
    {
        if(obj.departments.size() != obj2.departments.size()) break;
        if(obj.departments[i] == obj2.departments[i])
        {
            checker++;
        }
    }
    if(checker == (5 + obj2.departments.size())) same = 1;
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

void Salesman::add_book_to_basket(Book &book)
{
    customer.add_to_basket(book);
}

void Salesman::add_book_to_ordered_books(Book &book)
{
    customer.add_to_ordered_books(book);
}

void Salesman::set_permissions(string new_permissions)
{
    permissions = new_permissions;
}

void Salesman::set_experience(unsigned int new_experience)
{
    experience = new_experience;
}

void Salesman::set_customer(Customer new_customer)
{
    customer = new_customer;
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
Salesman::Salesman(string name, string surname, unsigned int cardId,string permissions, unsigned int experience, vector <string> departments) : Person(name, surname, cardId)
{
    this->permissions = permissions;
    this->experience = experience;
    this->departments = departments;
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
    ss<< "Salesman's name is: "<< name<<endl;
    ss<< "Salesman's surname is: "<< surname<<endl;
    ss<< "Salesman's id is: "<< cardId<<endl;
    ss<< "Salesman's permission is: "<< permissions<<endl;
    ss<< "Salesman's experience is: "<< experience<<endl;
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
        departments = obj.departments;
    }

    return *this;
}

ostream& operator<<(ostream &output, Salesman &obj)
{
    output << obj.to_string();
    return output;
}