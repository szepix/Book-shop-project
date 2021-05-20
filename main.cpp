#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cmath>


#include "customer.h"
#include "utils.h"
#include "salesman.h"
#include "person_col.h"
#include "section_col.h"
#include "section.h"
#include "books_col.h"
#include "bookstore.h"
#include "book.h"
#include "simulation.h"

using namespace std;






int main()
{
    srand(time(NULL));
    Simulation simulation;
    simulation.run();

    // PersonCol<Customer> col;
    // Customer c("1", "1", 1, 12.12);
    // col.add_person(c);
    // Customer d = col.get_person(1);
    // double x = 5.12341343524523246436234322342;

    // double rounded = floor((x * 100) + .5) / 100;


    // cout<<rounded<<endl;


    return 0;
}
