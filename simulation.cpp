#include "simulation.h"

using namespace std;

void Simulation::load_data_from_files()
{
    bookstore.read_sections("Sections.csv");
    bookstore.read_salesmen("Salesmen.csv");
    bookstore.read_books("Books.csv");
    bookstore.read_customer("Customers.csv");
    load_simulation_data("Simulation.csv");
    select_random_data();
}

void Simulation::change_time(unsigned int minutes) {
    int iteration = 0;
    if(minutes < 1)
    {
        throw out_of_range("Minutes should be bigger or equal to 1");
    }
    iteration = minutes;
    set_time(iteration);
}

void Simulation::load_simulation_data(string file)
{
    vector<vector<string>> sim_data = read_from_file(file);
    customers_number = abs(stoi(sim_data[0][0]));
    salesmen_number = abs(stoi(sim_data[0][1]));
    time = abs(stoi(sim_data[0][2]));


}

void Simulation::select_random_data()
{
    int customer_size = bookstore.get_customers_database().get_size();
    for(int i=0; i<customers_number;i++)
    {
        unsigned int random_number;
        do
        {
            random_number = rand()%(customer_size) + 1;
        }while (bookstore.get_customers_shop().has_id(random_number));
        customers_id.push_back(random_number);
        bookstore.add_customer_to_shop(random_number);
    }

    int salesmen_size = bookstore.get_salesmen_database().get_size();
    for(int i=0; i<salesmen_number;i++)
    {
        unsigned int random_number;
        do
        {
            random_number = rand()%(salesmen_size) + 1;
        }while (bookstore.get_salesmen_shop().has_id(random_number));
        salesmen_id.push_back(random_number);
        bookstore.add_salesman_to_shop(random_number);
    }
}





void Simulation::run()
{
    stringstream ss;
    ss<<endl;
    load_data_from_files();
    unsigned int cust_size = bookstore.get_customers_shop().get_size();
    for (unsigned int i=0; i< time; i++)
    {
        bool condition = false;
        typename map<unsigned int, Salesman>::const_iterator it;
        // TODO Gdy liczba salesmen = 0
        if(bookstore.get_salesmen_shop().get_people().empty()){break;}
        for(it = bookstore.get_salesmen_shop().get_people().cbegin(); it != bookstore.get_salesmen_shop().get_people().cend(); it++) {
            if (cust_size == 0) {
                condition = true;
                break;
            }
            else {
                unsigned int random_cust_id = rand()%(cust_size);
                unsigned int cust_id = customers_id[random_cust_id];
                customers_id.erase(customers_id.begin()+random_cust_id);
                --cust_size;
                unsigned int sal_id = it->second.get_card_id();
                bookstore.add_customer_to_salesman(cust_id, sal_id);
                bookstore.remove_customer_from_shop(cust_id);
                Salesman & salesman = bookstore.get_salesmen_shop().get_person(sal_id);
                Customer & customer = salesman.get_customer();
                ss<<"Salesman with card id "<<salesman.get_card_id()<<" got a new client"<<"    Iteration: "<<i+1<<endl;
                bool cond=true;
                while (cond) {
                    unsigned int random_book = rand()%bookstore.get_books_id().size() + 1;
                    random_book = bookstore.get_books_id()[random_book];
                    Book &book = bookstore.get_book_col().get_book(random_book);

                    ss<<"Client "<<customer.get_card_id()<<" asked about the book with id " << book.get_id()<<endl;
                    if (!book.get_number() == 0)
                    {
                        unsigned int operations;
                        if((!customer.get_basket().is_empty()) || (!customer.get_ordered().is_empty()))
                        {
                            operations = decision_yes;
                        }
                        else
                        {
                            operations = rand()%2 +1;
                        }
                        switch (operations) {
                            case buy:
                            {
                                if (customer.get_money() < book.get_price()) {
                                    ss<<"Client "<<customer.get_card_id()<<" couldn't afford the book with id  " << book.get_id()<<endl;
                                    operations = rand()%2;
                                    switch (operations) {
                                        case decision_yes:
                                        {
                                            ss<<"Client "<<customer.get_card_id()<<" decided to choose another book"<<endl;
                                        }
                                        case decision_no:
                                        {
                                            ss<<"Client "<<customer.get_card_id() << " decided to leave the shop"<<endl;
                                            ss<<"Number of clients who are in the bookstore: "<<bookstore.get_customers_shop().get_size()<<endl;
                                            cond = false;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    customer.add_to_basket(book);
                                    book.set_number(book.get_number()-1);
                                    customer.set_money(customer.get_money() - book.get_price());
                                    operations = rand()%2;
                                    ss<<"Client "<<customer.get_card_id()<<" bought the book with id "<< book.get_id()<<endl;
                                    if (operations == decision_no)
                                    {
                                        ss<<"Client "<<customer.get_card_id() << " decided to leave the shop after buying book"<<endl;
                                        ss<<"Number of clients who are in the bookstore: "<<bookstore.get_customers_shop().get_size()<<endl;
                                        cond = false;
                                    }
                                }
                                break;
                            }
                            case resign:
                            {
                                ss<<"Client "<<customer.get_card_id() << " decided to leave the shop"<<endl;
                                ss<<"Number of clients who are in the bookstore: "<<bookstore.get_customers_shop().get_size()<<endl<<endl;
                                cond = false;
                                break;
                            }
                        }
                    }
                    else
                    {
                        unsigned int operations;
                        if((!customer.get_basket().is_empty()) || (!customer.get_ordered().is_empty()))
                        {
                            operations = decision_yes;
                        }
                        else
                        {
                            operations = rand()%2 +1;
                        }
                        switch (operations) {
                            case order:
                            {
                                customer.add_to_ordered_books(book);
                                operations = rand()%2;
                                if (operations == decision_no)
                                {
                                    ss<<"Client "<<customer.get_card_id() << " decided to leave the shop after ordering book"<<endl;
                                    ss<<"Number of clients who are in the bookstore: "<<bookstore.get_customers_shop().get_size()<<endl;
                                    cond = false;
                                }
                                break;
                            }
                            case resign:
                            {
                                ss<<"Client "<<customer.get_card_id() << " decided to leave the shop"<<endl;
                                ss<<"Number of clients who are in the bookstore: "<<bookstore.get_customers_shop().get_size()<<endl<<endl;
                                cond = false;
                                break;
                            }
                        }
                    }
                }
                if (!customer.get_basket().is_empty())
                {
                    ss<<customer.get_basket()<<endl;
                }
                if (!customer.get_ordered().is_empty())
                {
                    ss<<customer.get_ordered()<<endl;
                }
                ss<<endl<<endl;
            }
        }
        if (condition) {break;}
    }
    string end_simulation =  "The simulation has ended";
    ss<<end_simulation;
    string result = ss.str();
    cout<<result;
    write_to_file("simulation_result.txt", result);
    exit(0);
}


