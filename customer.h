#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "basket.h"
#include "utils.h"

using namespace std;

class Customer
{
public:
	Customer(string name, string surname, int cardId, int age, double cash);
	Customer(const Customer& c) : name(c.name), surname(c.surname), cardId(c.cardId), age(c.age), cash(c.cash), basket(c.basket), preferences(c.preferences) {}
	~Customer() {}

	Customer& operator=(const Customer& c);

	string getName() { return name; }
	string getSurname() { return surname; }
	int getCardId() { return cardId; }
	int getAge() { return age; }
	double getCash() { return cash; }
	Basket& getBasket() { return basket; }
	vector<string>& getPreferences() { return preferences; }

	void setName(string new_name) { name = new_name; }
	void setSurname(string new_surname) { surname = new_surname; }
	void setCardId(int new_cardId) { cardId = new_cardId; }
	void setAge(int new_age) { age = new_age; }
	void setCash(double new_cash) { cash = new_cash; }

	void add_preference(string preference);
	bool remove_preference(string preference);

	void add_to_basket(Book& book);
	void remove_from_basket(int book_id);

	string to_string() const;
	string preferences_to_string() const;

	friend bool operator==(const Customer& c1, const Customer& c2);
	friend bool operator!=(const Customer& c1, const Customer& c2);
	friend ostream& operator<<(ostream& os, const Customer& dt);

private:
	Customer() {};

	string name;
	string surname;
	int cardId;
	int age;
	double cash;
	Basket basket;
	vector<string> preferences;
};

#endif