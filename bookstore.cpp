#include "bookstore.h"
#include <random>
#include <string>
#include <stdexcept>
using namespace std;

void Bookstore::change_time(unsigned int minutes) {
    int iteration = 0;
    if(minutes < 20)
    {
        throw out_of_range("Minutes should be bigger than 20");
    }
    iteration = minutes/20;
    set_time(iteration);
}

void Bookstore::read_customer(string file) {
    vector<vector<string>> c_data = read_from_file(file);
    for (int i = 0; i < c_data.size(); i++) {
        string name = c_data[i][0];
        string surname = c_data[i][1];
        unsigned int cardId = abs(stoi(c_data[i][2]));
        double money = rand()%200 + 20;
        Customer A(name, surname, cardId, money);
        customers_database.add_person(A);
    }
}

void Bookstore::read_salesmen(string file) {
    vector<vector<string>> salesmen_data = read_from_file(file);
    for (int i = 0; i < salesmen_data.size(); i++) {
        string name = salesmen_data[i][0];
        string surname = salesmen_data[i][1];
        unsigned int cardId = abs(stoi(salesmen_data[i][2]));
        string permissions = salesmen_data[i][3];
        unsigned int experience = abs(stoi(salesmen_data[i][4]));
        vector<string> departments;
        for(int j=5; j<salesmen_data.size(); j++)
        {
            departments.push_back(salesmen_data[i][j]);
        }
        Salesman A(name, surname, cardId, permissions, experience, departments);
        salesmen_database.add_person(A);
    }
}

void Bookstore::read_sections(string file) {
    vector<vector<string>> sections_data = read_from_file(file);
    for (int i = 0; i < sections_data.size(); i++) {
        string name = sections_data[i][0];
        string symbol = sections_data[i][1];
        string supervisor = sections_data[i][2];
        Section A(name, symbol, supervisor);
        sections.add_section(A);
    }
}

void Bookstore::read_books(string file) {
    vector<vector<string>> books_data = read_from_file(file);
    for (int i = 0; i < books_data.size(); i++) {
        string title = books_data[i][0];
        string author = books_data[i][1];
        unsigned int id = abs(stoi(books_data[i][2]));
        string genre = books_data[i][3];
        double price = rand()%100 + 10 + (rand()%99)/100;
        unsigned int number = rand()%5;
        Book A(title, author, genre, id, price, number);
        try {
            sections.get_section(genre).add_book(A);
        }
        catch (logic_error &e)
        {
            cout<<e.what();
        }
        books.add_book(A);
    }
}
