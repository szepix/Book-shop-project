#include "section.h"

using namespace std;
//Dział księgarni!
Section::Section(string name, 
                 string description, 
                 string position, string symbol, 
                 int bookcase_num, 
                 string supervisor, 
                 BooksCol books)
{
    this -> name = name;
    this -> description = description;
    this -> position = position;
    this -> symbol = symbol;
    this -> bookcase_num = bookcase_num;
    this -> supervisor = supervisor;
    this -> books = books;
}

void Section::add_book(Book book)
{
    books.add_book(book);
    cout<<"The book: "<<book.getTitle()<<" has been added"<<endl;
    
}
void Section::del_book(unsigned int id)
{   
    books.delete_book(id);
}

void Section::change_description(string new_description)
{
    description = new_description;
    cout<<"The new section description is: "<<description<<endl;
}

void Section::change_position(string new_position)
{
    position = new_position;
    cout<<"The new section position is: "<<position<<endl;
}

void Section::change_symbol(string new_symbol)
{
    symbol = new_symbol;
    cout<<"The new section symbol is: "<<symbol<<endl;
}

void Section::change_bookcase_num(int new_num)
{
    bookcase_num = new_num;
    cout<<"The new section bookcase number is: "<<bookcase_num<<endl;
}

void Section::change_name(string new_name)
{
    name = new_name;
    cout<<"The new section name is:: "<<name<<endl;
}

string Section::get_name() const
{
    return name;
}

string Section::get_description() const
{
    return description;
}

string Section::get_position() const
{
    return position;
}
        
int Section::get_bookcase_num() const
{
    return bookcase_num;
}

string Section::get_symbol() const
{
    return symbol;
}

const map<unsigned int, Book>& Section::get_books() const
{
    return books.get_books();
}

string Section::to_string() const {
    stringstream ss;
    ss << "Name: "<< name <<endl;
    ss << "Description: "<< description<<endl;
    ss << "Position: "<< position<<endl;
    ss << "Symbol: "<< symbol<<endl;
    ss << "Number of bookcases: "<< bookcase_num<<endl;
    ss << "Supervisor: "<< supervisor<<endl;
    ss << "Books: \n";
    map<unsigned int, Book> books = get_books();
    map<unsigned int, Book>::const_iterator it;
    for(it = books.cbegin(); it != books.cend(); it++) {
        ss << it->second<<endl;
    }

    return ss.str();
}

ostream& operator << (ostream& output, const Section &s)
{
    output<<s.to_string();
    return output;
}

bool operator == (const Section &s1, const Section &s2)
{
    if((s1.name == s2.name) && 
       (s1.description == s2.description) && 
       (s1.position == s2.position) && 
       (s1.symbol == s2.symbol) && 
       (s1.bookcase_num == s2.bookcase_num) && 
       (s1.supervisor == s2.supervisor))
        {
            cout <<"Sections are the same"<<endl;
            return true;
        }
    else
    {   
        cout <<"Sections are diffrent"<<endl;
        return false;
    }
}

bool operator != (const Section &s1, const Section &s2)
{
    if((s1.name == s2.name) && 
       (s1.description == s2.description) && 
       (s1.position == s2.position) && 
       (s1.symbol == s2.symbol) && 
       (s1.bookcase_num == s2.bookcase_num) && 
       (s1.supervisor == s2.supervisor))
        {
            cout <<"Sections are diffrent"<<endl;
            return false;
        }
    else
    {
        cout <<"Sections are the same"<<endl;
        return true;
    }
}

Section& Section::operator=(const Section &s)
{
    if(this != &s)
    {
        name = s.name;
        description = s.description;
        position = s.position;
        symbol = s.symbol;
        bookcase_num = s.bookcase_num; 
        supervisor = s.supervisor;
        books = s.books;
        return*this;
    }
    return*this;
}
