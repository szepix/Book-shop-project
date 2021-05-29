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
    return 0;
}
