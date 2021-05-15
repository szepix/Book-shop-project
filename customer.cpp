#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ostream>

#include "customer.h"

Customer::Customer(string name, string surname, unsigned int cardId, int age) : Person(name, surname, cardId)
{
    this->age = age;
};

string Customer::to_string() const {
    stringstream ss;
    ss << "Customer\nname:" << name << "\nsurname: " << surname << "\ncardId: " << cardId<< "\nage: " << age <<" zl"<< endl << preferences_to_string()<< endl<< basket <<endl<< ordered_books<<endl;
    return ss.str();
}

Customer& Customer::operator=(const Customer& c) {
    if (this != &c) {
        name = c.name;
        surname = c.surname;
        cardId = c.cardId;
        age = c.age;
        basket = c.basket;
        ordered_books = c.ordered_books;
        preferences = c.preferences;
    }
    return *this;
}

bool operator==(const Customer& c1, const Customer& c2){
    return ((c1.name == c2.name) && (c1.surname == c2.surname) && (c1.cardId == c2.cardId) && (c1.age == c2.age));
}

bool operator!=(const Customer& c1, const Customer& c2){
    return ((c1.name != c2.name) || (c1.surname != c2.surname) || (c1.cardId != c2.cardId) || (c1.age != c2.age));
}

ostream& operator<<(ostream& os, const Customer& c){
    os << c.to_string();
    return os;
}

void Customer::add_to_basket(Book& book){
    basket.add_book(book);
}

void Customer::remove_from_basket(int book_id){
    basket.delete_book(book_id);
}

void Customer::add_to_ordered_books(Book& book){
    ordered_books.add_book(book);
}

void Customer::remove_from_ordered_books(int book_id){
    ordered_books.delete_book(book_id);
}

void Customer::add_preference(string preference){
    preferences.push_back(preference);
}

bool Customer::remove_preference(string preference){
    vector<string>::iterator it = find(preferences.begin(), preferences.end(), preference);
        if (it == preferences.end()){
            cout<<"This preference does not exist"<<endl;
            return false;
        }
        else {
            preferences.erase(it);
            return true;
        }
}

string Customer::preferences_to_string() const{
    stringstream ss;
    ss << "Preferences: "<<endl;
    for (int i=0; i < preferences.size(); i++){
        ss << preferences[i]<<endl;
    }
    return ss.str();
}




























// #include <iostream>
// #include <string>
// #include <sstream>
// #include <cstdlib>
// #include <vector>
// #include <algorithm>
// #include <ostream>

// #include "customer.h"

// Customer::Customer(string name, string surname, int cardId, int age, double cash)
// {
//     this->name = name;
//     this->surname = surname;
//     this->cardId = cardId;
//     this->age = age;
//     this->cash = cash;
// };

// string Customer::to_string() const {
//     stringstream ss;
//     ss << "Customer\nname:" << name << "\nsurname: " << surname << "\ncardId: " << cardId<< "\nage: " << age << "\ncash: "<< cash <<" zl"<< endl<< basket << preferences_to_string()<< endl;
//     return ss.str();
// }

// Customer& Customer::operator=(const Customer& c) {
//     if (this != &c) {
//         name = c.name;
//         surname = c.surname;
//         cardId = c.cardId;
//         age = c.age;
//         cash = c.cash;
//         basket = c.basket;
//         preferences = c.preferences;
//     }
//     return *this;
// }

// bool operator==(const Customer& c1, const Customer& c2){
//     return ((c1.name == c2.name) && (c1.surname == c2.surname) && (c1.cardId == c2.cardId) && (c1.age == c2.age));
// }

// bool operator!=(const Customer& c1, const Customer& c2){
//     return ((c1.name != c2.name) || (c1.surname != c2.surname) || (c1.cardId != c2.cardId) || (c1.age != c2.age));
// }

// ostream& operator<<(ostream& os, const Customer& c){
//     os << c.to_string();
//     return os;
// }

// void Customer::add_to_basket(Book& book){
//     basket.add_book(book);
// }

// void Customer::remove_from_basket(int book_id){
//     basket.delete_book(book_id);
// }

// void Customer::add_preference(string preference){
//     preferences.push_back(preference);
// }

// bool Customer::remove_preference(string preference){
//     vector<string>::iterator it = find(preferences.begin(), preferences.end(), preference);
//         if (it == preferences.end()){
//             cout<<"This preference does not exist"<<endl;
//             return false;
//         }
//         else {
//             preferences.erase(it);
//             return true;
//         }
// }

// string Customer::preferences_to_string() const{
//     stringstream ss;
//     ss << "Preferences: "<<endl;
//     for (int i=0; i < preferences.size(); i++){
//         ss << preferences[i]<<endl;
//     }
//     return ss.str();
// }