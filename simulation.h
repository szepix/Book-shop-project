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
using namespace std;

class Simulation
{
public:
    Simulation() {};
    ~Simulation() {};
    void run();
    void load_data_from_files();
    void load_simulation_data(string file);
    const Bookstore& get_bookstore() const {return bookstore;}
    unsigned int get_time() const {return time;}
    void set_time(unsigned int new_time) {time = new_time;}
    void change_time(unsigned int minutes);
    void select_random_data();


private:
    Bookstore bookstore;
    unsigned int customers_number;
    unsigned int salesmen_number;
    unsigned int time;
};

#endif