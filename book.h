#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
public:
    Book(string title, string author, int id, double price);
    ~Book() {};

    string getTitle(){return title;}
    string getAuthor(){return author;}
    int getId(){return id;}
    double getPrice() const {return price;}

    string to_string() const;

	friend bool operator==(const Book& c1, const Book& c2);
	friend ostream& operator<<(ostream& os, const Book& dt);

private:
    string title;
    string author;
    int id;
    double price;
};

#endif