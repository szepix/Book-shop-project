#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
public:
    Person(string name, string surname, int cardId) {
        this->name = name;
        this->surname = surname;
        this->cardId = cardId;
    };
    Person() {};
	string getName() const { return name; }
	string getSurname() const { return surname; }
    unsigned int getCardId() const{ return cardId; }

    void setName(string new_name) { name = new_name; }
	void setSurname(string new_surname) { surname = new_surname; }
    void setCardId(unsigned int new_cardId) { cardId = new_cardId; }

    virtual string to_string() const = 0;
    virtual ~Person() {};

protected:
    string name;
	string surname;
    unsigned int cardId;
};

#endif