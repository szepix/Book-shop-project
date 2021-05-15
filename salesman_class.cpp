#include <iostream>
#include <vector>

/*Proszę zaimplementować klasę reprezentującą sprzedawcę w księgarni.
Sprzedawca cechuje się np. imieniem, nazwiskiem, poziomem uprawnień, doświadczeniem itp.
oraz zbiorem działów tematycznych, które ma pod opieką.
 Możliwa jest m.in. zmiana cech sprzedawcy oraz obsługiwanych przez niego działów.*/
using namespace std;

class Salesman
{
    string name;
    string surname;
    int worker_id;
    string permissions;
    int seniority;
    int salary;
    vector <string> departments;
    bool check_if_same(Salesman &obj)
    {
        bool same = 0;
        int checker = 0;
        if(obj.name == name) checker++;
        if(obj.surname == surname) checker++;
        if(obj.worker_id == worker_id) checker++;
        if(obj.permissions == permissions) checker++;
        if(obj.seniority == seniority) checker++;
        if(obj.salary == salary) checker++;
        for(int i=0; i<departments.size(); i++)
        {
            if(obj.departments.size() != departments.size()) break;
            if(obj.departments[i] == departments[i])
            {
                checker++;
            }
        }
        if(checker == (6 + departments.size())) same = 1;
        return same;
    }
    void make_same(Salesman &obj)
    {
        name = obj.name;
        surname = obj.surname;
        worker_id = obj.worker_id;
        permissions = obj.permissions;
        seniority = obj.seniority;
        salary = obj.salary;
        departments = obj.departments;
    }
public:
    friend ostream& operator <<(ostream &strumien, Salesman &obj);
    void display_name()
    {
        std::cout<<"Worker's name is: "<<name<<endl;
    }
    void display_salary()
    {
        std::cout<<"Worker's salary is: "<<salary<<endl;
    }
    void display_surname()
    {
        std::cout<<"Worker's surname is: "<<surname<<endl;
    }
    void display_id()
    {
        std::cout<<"Worker's id is: "<<worker_id<<endl;
    }
    void display_permissions_level()
    {
        std::cout<<"Worker's permission level is: "<<permissions<<endl;
    }
    void display_seniority()
    {
        std::cout<<"Worker's seniority is: "<<seniority<<endl;
    }
    void display_departments()
    {
        std::cout<<"Worker's departments are: \n";
        for(int i=0; i<departments.size(); i++)
        {
            std::cout<<departments[i]<<endl;
        }
    }
    void set_name(string new_name)
    {
        name = new_name;
        std::cout<<"Worker's name is changed to: "<<name<<endl;
    }
    void set_surname(string new_surname)
    {
        surname = new_surname;
        std::cout<<"Worker's surname is changed to: "<<surname<<endl;
    }
    void set_id(int new_id)
    {
        worker_id = new_id;
        std::cout<<"Worker's id is changed to: "<<worker_id<<endl;
    }
    void set_permissions(string new_permissions)
    {
        permissions = new_permissions;
        std::cout<<"Worker's permissions is changed to: "<<permissions<<endl;
    }
    void set_seniority(int new_seniority)
    {
        seniority = new_seniority;
        std::cout<<"Worker's seniority is changed to: "<<seniority<<endl;
    }
    void set_salary(int new_salary)
    {
        salary = new_salary;
        std::cout<<"Worker's seniority is changed to: "<<salary<<endl;
    }
    void add_department(string new_department)
    {
        departments.push_back(new_department);
        std::cout<<"Added new department: "<<new_department<<endl;
    }
    void replace_departments(vector <string> new_list)
    {
        departments = new_list;
        std::cout<<"Changed list to: ";
        display_departments();
    }
    void remove_department(string department)
    {
        for (int i = 0; i < departments.size(); i++) {
            if (departments[i] == department) {
                departments.erase(departments.begin() + i);
            }
        }
        std::cout<<"Removed department: "<<department<<endl;
    }
    Salesman(string name, string surname, int worker_id, string permissions, int seniority, int salary,vector <string> departments) {
        this->name = name;
        this->surname = surname;
        this->worker_id = worker_id;
        this->permissions = permissions;
        this->seniority = seniority;
        this->departments = departments;
        this->salary = salary;
    }
    Salesman(Salesman &obj) {
        this->name = obj.name;
        this->surname = obj.surname;
        this->worker_id = obj.worker_id;
        this->permissions = obj.permissions;
        this->seniority = obj.seniority;
        this->departments = obj.departments;
        this->salary = obj.salary;
    }
    bool operator != (Salesman &obj)
    {
        if(check_if_same(obj) == 1) return 0;
        else return 1;
    }
    bool operator == (Salesman &obj)
    {
        if(check_if_same(obj)) return 1;
        else return 0;
    }
    Salesman operator = (Salesman &obj)
    {
        make_same(obj);
        return *this;
    }
};
ostream& operator<<(ostream &strumien, Salesman &obj)
{
    cout<< "Worker's name is: "<< obj.name<<endl;
    cout<< "Worker's surname is: "<< obj.surname<<endl;
    cout<< "Worker's id is: "<< obj.worker_id<<endl;
    cout<< "Worker's permission is: "<< obj.permissions<<endl;
    cout<< "Worker's seniority is: "<< obj.seniority<<endl;
    cout<< "Worker's salary is: "<< obj.salary<<endl;
    obj.display_departments();
    return strumien;
}