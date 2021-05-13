#include <iostream>
#include <algorithm>
#include "menu.h"
#include "utils.h"
#include "test_customer.h"

using namespace std;

void Menu::show_all_customers(CustomerCol& customers){
    customers.show_all();
}

void Menu::show_customer(CustomerCol& customers, int cardId){
    cout << customers.get_customer(cardId);
}

void Menu::set_customer_name(CustomerCol& customers, int cardId){
    string name;
    cout << "Enter new name: ";
    cin >> name;
    customers.get_customer(cardId).setName(name);
}

void Menu::set_customer_surname(CustomerCol& customers, int cardId){
    string surname;
    cout << "Enter new surname: ";
    cin >> surname;
    customers.get_customer(cardId).setSurname(surname);
}

void Menu::set_customer_cardId(CustomerCol& customers, int cardId){
    int id = -1;
    string prompt = "Enter new cardId: ";
    customers.entering_card_id(prompt, &id);
    if (cardId != id) {
        customers.change_card_id(cardId, id);
    }
}

void Menu::set_customer_age(CustomerCol& customers, int cardId){
    int id = -1;
    string prompt = "Enter new age: ";
    entering_int_data(&id, prompt);
    customers.get_customer(cardId).setAge(id);
}

void Menu::set_customer_cash(CustomerCol& customers, int cardId){
    double money = 0;
    string prompt = "Enter new cash (in X.xx format): ";
    entering_money_val(&money, prompt);
    customers.get_customer(cardId).setCash(money);
}

void Menu::add_customer_preferences(CustomerCol& customers, int cardId){
    string preference;
    int number;
    entering_int_data(&number, "Enter number of new preferences: ");
    for (int i=0; i < number; i++){
        while (true){
            cout<<"Enter new preference: ";
            cin>>preference;
            vector<string>::iterator it = find(customers.get_customer(cardId).getPreferences().begin(), customers.get_customer(cardId).getPreferences().end(), preference);
            if (it != customers.get_customer(cardId).getPreferences().end()){cout<<"This preference already exist"<<endl;}
            else{
                customers.get_customer(cardId).add_preference(preference);
                break;
            }
        }
    }
    if (number == 1){cout<<"\nPreference has been added"<<endl;}
    else {cout<<"\nPreferences have been added"<<endl;}
}

void Menu::remove_customer_preference(CustomerCol& customers, int cardId){
    string preference;
    cout<<customers.get_customer(cardId).preferences_to_string()<<endl;
    while (true){
        cout<<"Enter preference: ";
        cin>>preference;
            if (customers.get_customer(cardId).remove_preference(preference)){
                cout<<"\nThis preference has been deleted"<<endl;
                break;
            }
    }
}

void Menu::change_customer_preferences(CustomerCol& customers, int cardId){
    int option;
    string preference;
    string text = "Choose option\n\n1. Add preference\n2. Remove preference\n\nEnter option: ";
    enter_option(text, &option, 2);
    switch (option)
    {
        case add_preference:
            add_customer_preferences(customers, cardId);
            break;
        case remove_preference:
            remove_customer_preference(customers, cardId);
            break;
    }
}

void Menu::change_customer_data(CustomerCol& customers, int cardId){
    int option;
    string text = "\nChoose what you want to change\n\n1. name\n2. surname\n3. cardId\n4. age\n5. cash\n6. preferences\n\nOption:  ";
    enter_option(text, &option, 6);
    switch(option)
    {
        case client_name:
            set_customer_name(customers, cardId);
            break;
        case client_surname:
            set_customer_surname(customers, cardId);
            break;
        case client_cardId:
            set_customer_cardId(customers, cardId);
            break;
        case client_age:
            set_customer_age(customers, cardId);
            break;
        case client_cash:
            set_customer_cash(customers, cardId);
            break;
        case client_preferences:
            change_customer_preferences(customers, cardId);
            break;
    }
}

void Menu::add_book_to_basket(CustomerCol& customers, int cardId){
    string title, author;
    string text1 = "Enter book id: ";
    string text2 = "Enter price (in X.xx format): ";
    int bookId;
    double price;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author: ";
    cin >> author;
    entering_int_data(&bookId, text1);
    if (!customers.get_customer(cardId).getBasket().has_book_id(bookId))
    {
        entering_money_val(&price, text2);
        Book b = Book(title, author, bookId, price);
        customers.get_customer(cardId).add_to_basket(b);
        cout<<"\nBook has been added"<<endl;
    }
    else
    {
        cout<<"This book already exists";
    }
}

void Menu::remove_book_from_basket(CustomerCol& customers, int cardId){
    cout << customers.get_customer(cardId).getBasket().to_string();
    string text = "Enter book id: ";
    int bookId;
    while (true){
        entering_int_data(&bookId, text);
        if (customers.get_customer(cardId).getBasket().has_book_id(bookId)){
            customers.get_customer(cardId).remove_from_basket(bookId);
            cout<<"\nThis book has been deleted"<<endl;
            break;
        }
        else {cout<<"This book does not exist"<<endl;}
    }
}

void Menu::change_basket(CustomerCol& customers, int cardId){
    int option;
    string text = "Choose option\n\n1. Add to basket\n2. Remove from basket\n\nEnter option: ";
    enter_option(text, &option, 2);
    switch(option)
    {
        case add_book:
            add_book_to_basket(customers, cardId);
            break;
        case remove_book:
            remove_book_from_basket(customers, cardId);
            break;
    }
}

void Menu::remove_customer(CustomerCol& customers, int cardId){
    customers.delete_customer(cardId);
    cout<<"\nThis customer has been deleted"<<endl;
}

void Menu::end_program(){
    cout << "\n\nSee you next time\n\n";
    exit(0);
}

Customer Menu::entering_new_customer(){
    int cardId, age;
    double cash;
    string name, surname;
    string text1 = "Enter new cardId: ";
    string text2 = "Enter new age: ";
    string text3 = "Enter new cash (in X.xx format): ";
    cout << "Enter new name: ";
    cin >> name;
    cout << "Enter new surname: ";
    cin >> surname;
    customers.entering_card_id(text1, &cardId);
    entering_int_data(&age, text2);
    entering_money_val(&cash, text3);
    Customer c = Customer(name, surname, cardId, age, cash);
    return c;
}

void Menu::add_customer(CustomerCol& customers){
    Customer c = entering_new_customer();
    customers.add_customer(c);
    cout<<"\nCustomer has been added"<<endl;
}

void Menu::test_copying(Customer& c1){
    Customer c2(c1);
    cout<<"\nOld customer: "<<endl<<c1<<endl;
    cout<<"Copied customer: "<<endl<<c2<<endl<<endl;
    cout<<"Checking whether they are identical"<<endl;
    if (c1 == c2){cout<<"They are identical"<<endl;}
    else if (c1 != c2) {cout<<"They are not identical"<<endl;}
}

void Menu::test_allocation(Customer& c1){
    cout<<"\nOld customer: "<<endl<<c1<<endl<<endl;
    cout<<"Enter second customer"<<endl;
    Customer c2 = entering_new_customer();
    cout<<"\nNew customer: "<<endl<<c2<<endl;
    cout<<"Checking whether they are identical"<<endl<<endl;
    if (c1 == c2){cout<<"They are identical"<<endl<<endl;}
    else if (c1 != c2) {cout<<"They are not identical"<<endl<<endl;}
    c1 = c2;
    cout<<"After alocation"<<endl;
    cout<<"Old customer: "<<endl<<c1<<endl;
    cout<<"Allocated customer: "<<endl<<c2<<endl;
    cout<<"Checking whether they are identical"<<endl<<endl;
    if (c1 == c2){cout<<"They are identical"<<endl;}
    else if (c1 != c2) {cout<<"They are not identical"<<endl;}
}

void Menu::test_copying_and_allocation(){
    int option;
    cout<<"Create new customer"<<endl<<endl;
    Customer c1 = entering_new_customer();
    enter_option("\nChoose operation\n\n1. copying\n2. allocation\n\nEnter option: ", &option, 2);
    switch(option)
    {
        case copy_customer:
            test_copying(c1);
            break;
        case allocate_customer:
            test_allocation(c1);
            break;
    }
}

void Menu::run()
{
    while (true)
    {
        int new_choice;
        string text = "\n\nEnter option\n\n1. Choose customer\n2. Add customer\n3. Show all customers \n4. Test copying and allocation\n5. Exit\n\nEnter the type of operation:  ";
        enter_option(text, &new_choice, 5);
        switch (new_choice)
        {
        case choosed_client:
        {
            int choice;
            if (customers.empty()){
                cout<<"\nThe customer list is empty";
                break;
            }
            int cardId = customers.select_customer();
            if (!cardId){
                break;
            }
            text = "\n\nEnter option\n\n1. Show customer data\n2. Change customer data\n3. Change basket contents\n4. Remove customer\n5. Exit\n\nEnter the type of operation:  ";
            enter_option(text, &choice, 5);

            switch(choice)
            {
                case show_client:
                    show_customer(customers, cardId);
                    break;
                case change_client_data:
                    change_customer_data(customers, cardId);
                    break;
                case change_client_basket:
                    change_basket(customers, cardId);
                    break;
                case remove_client:
                    remove_customer(customers, cardId);
                    break;
                case program_end:
                    end_program();
                    break;
            }
            break;
        }
        case add_client:
            add_customer(customers);
            break;
        case show_all_clients:
            show_all_customers(customers);
            break;
        case copy_allocate_test:
            test_copying_and_allocation();
            break;
        case program_end:
            end_program();
            break;
        }
    }
}