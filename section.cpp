#include "section.h"

using namespace std;
//Dział księgarni!
Section::Section(string name,
                 string symbol,
                 string supervisor)
{
    this -> name = name;
    this -> symbol = symbol;
    this -> supervisor = supervisor;
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

void Section::change_symbol(string new_symbol)
{
    symbol = new_symbol;
    cout<<"The new section symbol is: "<<symbol<<endl;
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
    ss << "Symbol: "<< symbol<<endl;
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
       (s1.symbol == s2.symbol) && 
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
       (s1.symbol == s2.symbol) &&
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
        symbol = s.symbol;
        supervisor = s.supervisor;
        books = s.books;
        return*this;
    }
    return*this;
}
