#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
public:
    Book(string title, string author, string genre, unsigned int id, double price, unsigned int number);
    ~Book() {};

    string getTitle() const {return title;}
    string getGenre() const {return genre;}
    string getAuthor() const {return author;}
    unsigned int getId() const {return id;}
    double getPrice() const {return price;}
    unsigned int getNumber() const {return number;}

    void setTitle(string new_title);

    void setGenre(string new_genre);

    void setAuthor(string new_author);

    void setId(unsigned int new_Id);

    void setPrice(double new_price);

    void setNumber(unsigned int new_number);

    string to_string() const;

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
