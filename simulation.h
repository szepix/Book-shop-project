#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <random>
#include <string>
#include "bookstore.h"
#include "utils.h"
#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "salesman.h"
#include "customer.h"
using namespace std;


// Class Simulation is responsible for running the bookstore simulation. It has private variables such as:
// - bookstore
// - customers_id
// - salesmen_id
// - customers_number
// - salesmen_number
// - time

enum operations{
    buy = 1,
    resign = 2,
    order = 1,
    continue_yes = 1,
    continue_no = 0,
};


class Simulation
{
public:
    Simulation() {};
    ~Simulation() {};
    // running the bookstore simulation
    void run();
    // loading the settings needed for the simulation
    void load_data_from_files();
    // loading data about (books, customers, salesmen, sections) from a file needed for simulation
    void load_simulation_data(string file);
    // getter of an object of the Bookstore class
    const Bookstore& get_bookstore() const {return bookstore;}
    unsigned int get_time() const {return time;}
    void set_time(unsigned int new_time) {time = new_time;}
    // determining simulation run time
    void change_time(unsigned int minutes);
    // random determination of the number of customers and salesmen taking part in the simulation and downloading objects to the shop from the database
    void select_random_data();


private:
    Bookstore bookstore;
    vector <unsigned int> customers_id;
    vector <unsigned int> salesmen_id;
    vector <unsigned int> looker_customers_id;
    unsigned int customers_number;
    unsigned int salesmen_number;
    unsigned int looker_customers_number;
    unsigned int time;
    stringstream ss;
};

#endif