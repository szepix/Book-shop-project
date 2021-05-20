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
    if(minutes < 20)
    {
        throw out_of_range("Minutes should be bigger than 20");
    }
    iteration = minutes/20;
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
            random_number = rand()%(customer_size-1) + 1;
        }while (bookstore.get_customers_shop().has_id(random_number));
        bookstore.add_customer_to_shop(random_number);
    }

    int salesmen_size = bookstore.get_salesmen_database().get_size();
    for(int i=0; i<salesmen_number;i++)
    {
        unsigned int random_number;
        do
        {
            random_number = rand()%(salesmen_size-1) + 1;
        }while (bookstore.get_salesmen_shop().has_id(random_number));
        bookstore.add_salesman_to_shop(random_number);
    }
}





void Simulation::run()
{
    stringstream ss;
    load_data_from_files();
    for (unsigned int i=0; i< time; i++)
    {
        bool condition = false;
        typename map<unsigned int, Salesman>::iterator it;
        // TODO Gdy liczba salesmen = 0
        for(it = bookstore.get_salesmen_shop().get_persons().begin(); it != bookstore.get_salesmen_shop().get_persons().end(); it++) {
            unsigned int cust_size = bookstore.get_customers_shop().get_size();
            if (cust_size == 0) {
                condition = true;
                break;
            }
            else {
                unsigned int cust_id = rand()%(cust_size-1) + 1;
                // Customer& customer = bookstore.get_customers_shop().get_person(cust_id);
                it->second.set_customer(bookstore.get_customers_shop().get_person(cust_id));
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


