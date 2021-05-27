#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

//Class Person which is parent class for: Salesman, Customer
//Contains protected variables: name, surname, cardId

class Person {
public:
    Person(string name, string surname, int cardId) {
        this->name = name;
        this->surname = surname;
        this->cardId = cardId;
    };
    Person() {};
    virtual ~Person() {};

//getters for variables
	string get_name() const { return name; }
	string get_surname() const { return surname; }
    unsigned int get_card_id() const{ return cardId; }

//setters for variables
    void set_name(string new_name) { name = new_name; }
	void set_surname(string new_surname) { surname = new_surname; }
    void set_card_id(unsigned int new_cardId) { cardId = new_cardId; }

    virtual string to_string() const = 0;
    
protected:
    string name;
	string surname;
    unsigned int cardId;
};

#endif