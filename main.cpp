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
using namespace std;






int main()
{
    // PersonCol <Customer> A;
    // Customer B("AAAA", "BBB", 15, 30);
    // Customer C("AAAAAAAA", "BBBBBBBBB", 150, 300);
    // A.add_person(B);
    // A.add_person(C);
    // A.show_all();
    // cout<<endl<<endl;
    // cout<<A.get_person(15);
    // PersonCol <Salesman> A;
    // vector <string> C;
    // C.push_back("aaa");
    // Salesman B("AAAAA", "BBBB", 1, "CEO", 5, 11.2, C);
    // A.add_person(B);
    // A.show_all();
    // CustomerCol customers;
    // Menu menu(customers);
    // menu.run();
    // SectionCol D;
    // // vector <string> G;
    // // G.push_back("xxx");
    // BooksCol A;
    // Book CEP("CEP","JA",5, 11.21);
    // A.add_book(CEP);
    // Book XXX("AAA","JA",6, 21.21);
    // A.add_book(XXX);
    // BooksCol B;
    // B.add_book(CEP);
    // Section F("XXX", "XXX", "XXX", "A", 5, "aaa", A);
    // Section H("XXXXXaa", "XXXaa", "XXXaa", "A", 5, "aaa", B);
    // D.add_section(F);
    // D.add_section(H);
    // D.show_all();
    // D.delete_section("XXX");
    // D.show_all();
    // Bookstore bookshop;
    // bookshop.set_time(0);
    // bookshop.change_time(15);
    // cout<<bookshop.get_time();

    Book CEP("CEP","JA",5, 11.21);
    Book XXX("XXX","JA",6, 21.21);

    read_from_file("plik_bazowy.txt");

    string text;
    text = CEP.to_string() + "\n";
    text = text + XXX.to_string();

    write_to_file("plik_koncowy.txt", text);

    return 0;
}


