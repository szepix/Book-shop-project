#include "simulation.h"
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
                bool exit=true;
                while (exit) {
                    unsigned int random_book = rand()%bookstore.get_books_id().size() + 1;
                    random_book = bookstore.get_books_id()[random_book];
                    if (!bookstore.get_book_col().get_book(random_book).get_number() == 0)
                    {
                        unsigned int operations = rand()%2 +1;
                        switch (operations) {
                            case buy:
                                operations = rand()%2;
                                if (operations == decision_no)
                                {
                                    //bookstore.get_customers_shop().get_person(cust_id).add_to_basket();
                                    exit = false;
                                }
                                break;
                            case resign:
                                exit = false;
                                break;
                        }
                    }
                    else
                    {
                        unsigned int operations = rand()%2 +1;
                        switch (operations) {
                            case order:






                                operations = rand()%2;
                                if (operations == decision_no)
                                {
                                    exit = false;
                                }
                                break;
                            case resign:
                                exit = false;
                                break;
                        }
                    }
                }

            }
        }
        if (condition) {break;}
    }
    string end =  "The simulation has ended";
    cout<<end;
    ss<<end;
    string result = ss.str();
    write_to_file("simulation_result.txt", result);
    exit(0);
}


