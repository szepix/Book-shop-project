#include "bookstore.h"
#include <random>
#include <string>
#include <stdexcept>
using namespace std;

void Bookstore::add_customer_to_shop(unsigned int id)
{
    customers_shop.add_person(customers_database.get_person(id));
}

void Bookstore::add_salesman_to_shop(unsigned int id)
{
    salesmen_shop.add_person(salesmen_database.get_person(id));
}

void Bookstore::read_customer(string file) {
    vector<vector<string>> c_data = read_from_file(file);
    for (int i = 0; i < c_data.size(); i++) {
        if (c_data[i].size() < 3)
        {
            throw invalid_argument("Not enough information about customer");
        }
        string name = c_data[i][0];
        string surname = c_data[i][1];
        unsigned int cardId;
        try
        {
            cardId = abs(stoi(c_data[i][2]));
        }
        catch(const invalid_argument& e)
        {
            throw invalid_argument("Invalid cardId  -  customer's id: "  + c_data[i][2]);
        }

        double money = (double)(rand()%99)/100;
        money += rand()%200 + 20;
        money = floor((money * 100) + .5) / 100;
        Customer A(name, surname, cardId, money);
        customers_database.add_person(A);
    }
}

void Bookstore::remove_customer_from_shop(unsigned int id)
{
    customers_shop.delete_person(id);
}

void Bookstore::read_salesmen(string file) {
    vector<vector<string>> salesmen_data = read_from_file(file);
    for (int i = 0; i < salesmen_data.size(); i++) {
        if (salesmen_data[i].size() < 6)
        {
            throw invalid_argument("Not enough information about salesman");
        }
        string name = salesmen_data[i][0];
        string surname = salesmen_data[i][1];
        unsigned int cardId;
        string permissions = salesmen_data[i][3];
        unsigned int experience;
        try
        {
            cardId = abs(stoi(salesmen_data[i][2]));
        }
        catch(const invalid_argument& e)
        {
            throw invalid_argument("Invalid int data  -  salesman's id: "  + salesmen_data[i][2]);
        }
        try
        {
            experience = abs(stoi(salesmen_data[i][4]));
        }
        catch(const invalid_argument& e)
        {
            throw invalid_argument("Invalid int data  -   salesman's experience: " + salesmen_data[i][4]);
        }
        vector<string> departments;
        for(int j=5; j<salesmen_data[i].size(); j++)
        {
            departments.push_back(salesmen_data[i][j]);
            sections.get_section(salesmen_data[i][j]).add_supervisor(cardId);
        }
        Salesman A(name, surname, cardId, permissions, experience, departments);
        salesmen_database.add_person(A);
    }
}

void Bookstore::read_sections(string file) {
    vector<vector<string>> sections_data = read_from_file(file);
    for (int i = 0; i < sections_data.size(); i++) {
        if (sections_data[i].size() != 2)
        {
            throw invalid_argument("Wrong amount of information about section");
        }
        string name = sections_data[i][0];
        string symbol = sections_data[i][1];
        Section A(name, symbol);
        sections.add_section(A);
    }
}

void Bookstore::add_customer_to_salesman(unsigned int cust_id, unsigned int sal_id)
{
    salesmen_shop.get_person(sal_id).set_customer(customers_shop.get_person(cust_id));
}

void Bookstore::remove_customer_from_salesman(unsigned int sal_id)
{
    Customer c;
    salesmen_shop.get_person(sal_id).set_customer(c);
}


void Bookstore::read_books(string file) {
    vector<vector<string>> books_data = read_from_file(file);
    for (int i = 0; i < books_data.size(); i++) {
        if (books_data[i].size() != 4)
        {
            throw invalid_argument("Not enough information about salesman");
        }
        string title = books_data[i][0];
        string author = books_data[i][1];
        unsigned int id;
        try
        {
            id = abs(stoi(books_data[i][2]));
        }
        catch(const invalid_argument& e)
        {
            throw invalid_argument("Invalid id  -  books's id: "  + books_data[i][2]);
        }
        string genre = books_data[i][3];
        double price = (double)(rand()%99)/100;
        price += (rand()%100 + 10);
        price = floor((price * 100) + .5) / 100;
        unsigned int number = rand()%5;
        books_id.push_back(id);
        Book A(title, author, genre, id, price, number);
        sections.get_section(genre).add_book(A);
        books.add_book(A);
    }
}
