#include <iostream>
#include <algorithm>
#include <map>

#include "customer_col.h"
#include "utils.h"

void CustomerCol::add_customer(Customer& c) {
    int cardId = c.getCardId();
    if (!has_customer_id(cardId)) {
        customers.insert(map<int, Customer>::value_type(cardId, c));
    }
    else {
        cout << "Such a client already exists" << endl;
    }
}

void CustomerCol::delete_customer(int id) {
    map<int, Customer>::iterator it = customers.find(id);
    if (it != customers.end()) {
        customers.erase(it);
    }
    else {
        cout << "Such a client does not exist" << endl;
    }
}

Customer& CustomerCol::get_customer(int id) {
    return customers.find(id)->second;
}

bool CustomerCol::has_customer_id(int id) {
    return customers.find(id) != customers.end();
}

bool CustomerCol::empty(){
    return customers.empty();
}

void CustomerCol::show_all(){
    cout<<"Customers: "<<endl;
    map<int, Customer>::iterator it;
    for(it = customers.begin(); it != customers.end(); it++) {
        cout << it->second.to_string()<<endl;
    }
}

int CustomerCol::select_customer()
{
    string string_customer;
    bool condition = false;
    int number = -1;
    while (condition == false){
        cout<<"\nSelect customer (loyalty card number): ";
        cin>>string_customer;
        if (checking_int(string_customer)){
            number = stoi(string_customer);
            if (has_customer_id(number)){
                condition = true;
            }
            else{
                cout<<"There is no such number";
                return 0;
            }
        }
        else{cout<<"Not a number";}
    }
    return number;
}

void CustomerCol::entering_card_id(string prompt, int *number){
    bool condition = false;
    while (condition == false){
        entering_int_data(number, prompt);
        if ((!has_customer_id(*number)) && (*number > 0)){
            condition = true;
        }
        else{
            cout<<"This number already exists or is incorrect\n";
        }
    }
}

void CustomerCol::change_card_id(int oldId, int newId) {
    Customer c = get_customer(oldId);
    c.setCardId(newId);
    delete_customer(oldId);
    add_customer(c);
}
