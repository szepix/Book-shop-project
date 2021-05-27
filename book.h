#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

//Class Book with private variables: title, author, genre, id, price, number

class Book
{
public:
    Book(string title, string author, string genre, unsigned int id, double price, unsigned int number);
    ~Book() {};

//getters for variables
    string get_title() const {return title;}
    string get_genre() const {return genre;}
    string get_author() const {return author;}
    unsigned int get_id() const {return id;}
    double get_price() const {return price;}
    unsigned int get_number() const {return number;}

//setters for variables
    void set_title(string new_title);
    void set_genre(string new_genre);
    void set_author(string new_author);
    void set_id(unsigned int new_Id);
    void set_price(double new_price);
    void set_number(unsigned int new_number);

    string to_string() const;

//operators overloading
	friend bool operator==(const Book& c1, const Book& c2);
	friend ostream& operator<<(ostream& os, const Book& dt);

private:
    string genre;
    string title;
    string author;
    unsigned int id;
    double price;
    unsigned int number;
};

#endif
