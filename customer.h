#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "basket.h"
#include "ordered_books.h"
#include "utils.h"
#include "person.h"


using namespace std;

//Class Customer - inherits from class Person
//Contains private variables: money, basket, ordered_books, preferences

class Customer : public Person
{
public:
	Customer(string name, string surname, unsigned int cardId, double money);
	Customer() {};
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// Customer(const Customer& c) : name(c.name), surname(c.surname), cardId(c.cardId), age(c.age), basket(c.basket), preferences(c.preferences), ordered_books(c.ordered_books) {}
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	~Customer() {}

//getters for variables
	double get_money() const {return money;}
	const Basket& get_basket() const { return basket; }
	const OrderedBooks& get_ordered() const { return ordered_books; }
	const vector<string>& get_preferences() const { return preferences; }

//methods to add or remove specified elements from collection
	void add_preference(string preference);
	bool remove_preference(string preference);
	void add_to_basket(Book& book);
	void remove_from_basket(int book_id);
	void add_to_ordered_books(Book& book);
	void remove_from_ordered_books(int book_id);

//methods to get string from objects
	string to_string() const;
	string preferences_to_string() const;

//method to set variable
	void set_money(double new_money) {money = new_money;};

//operators overloading
	friend bool operator==(const Customer& c1, const Customer& c2);
	friend bool operator!=(const Customer& c1, const Customer& c2);
	friend ostream& operator<<(ostream& os, const Customer& dt);
	Customer& operator=(const Customer& c);

private:
	double money;
	Basket basket;
	OrderedBooks ordered_books;
	vector<string> preferences;
};

#endif
