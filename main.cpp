#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "customer.h"
#include "utils.h"
#include "salesman.h"
#include "person_col.h"
#include "section_col.h"
#include "section.h"
#include "books_col.h"
#include "bookstore.h"
#include "book.h"
using namespace std;






int main()
{
    // bookshop.change_time(15);
    // cout<<bookshop.get_time();
    
    // Book Umberto("siema","JA","jakis tam",6, 21.21, 5);

    // vector<vector<string>> a = read_from_file("Salesmans.csv");
    // cout<< a[0][0]<<endl;
    // string text;
    // text = CEP.to_string() + "\n";
    // text = text + Umberto.to_string();

    // write_to_file("plik_koncowy.txt", text);

    //Book CEP("CEP","JA","fantasy", 5, 11.21);
    // sections.get_section(genre).add_book(A);
    // books.add_book(A);
    
    Bookstore Bookshop;
    Bookshop.read_sections("Sections.csv");
    Bookshop.read_salesmen("Salesmen.csv");
    Bookshop.read_books("Books.csv");
    Bookshop.read_customer("Customers.csv");

    return 0;
}


