#include "section.h"

using namespace std;
//Dział księgarni!
Section::Section(string name, 
                 string description, 
                 string position, string symbol, 
                 int bookcase_num, 
                 string supervisor, 
                 vector <string> books)
{
    this -> name = name;
    this -> description = description;
    this -> position = position;
    this -> symbol = symbol;
    this -> bookcase_num = bookcase_num;
    this -> supervisor = supervisor;
    this -> books = books;
}

void Section::add_book(string title)
{
    books.push_back(title);
    cout<<"The book: "<<title<<" has been added"<<endl;
    
}
void Section::del_book(string title)
{   
    if (find(books.begin(), books.end(), title) != books.end())
    {
        books.erase(remove(books.begin(), books.end(), title));
        cout<<"The book: "<<title<<" has been deleted"<<endl;
    }
    else
    {
        cout << "There is no such a book"<<endl;
    }
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

const vector<string>& Section::get_books() const
{
    if (books.empty())
    {
        cout << "There are no books"<<endl;
    }
    else
    {
        cout<<"Available books: "<<endl;
        for(int i = 0; i < books.size(); i++)
        {
            cout << books[i] << endl;
        }
    }
    return books;
}

ostream& operator << (ostream& output, const Section &s)
{
    cout << "Name: "<< s.name <<endl;
    cout << "Description: "<< s.description<<endl;
    cout << "Position: "<< s.position<<endl;
    cout << "Symbol: "<< s.symbol<<endl;
    cout << "Number of bookcases: "<< s.bookcase_num<<endl;
    cout << "Supervisor: "<< s.supervisor<<endl;
    return output;
}

bool operator == (const Section &s1, const Section &s2)
{
    if((s1.name == s2.name) && 
       (s1.description == s2.description) && 
       (s1.position == s2.position) && 
       (s1.symbol == s2.symbol) && 
       (s1.bookcase_num == s2.bookcase_num) && 
       (s1.supervisor == s2.supervisor) && 
       (s1.books == s2.books))
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
       (s1.supervisor == s2.supervisor) && 
       (s1.books == s2.books))
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
    }
    return*this;
}
