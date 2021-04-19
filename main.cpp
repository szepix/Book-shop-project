#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "customer.h"
#include "customer_col.h"
#include "utils.h"
#include "menu.h"

using namespace std;


int main()
{
    CustomerCol customers;
    Menu menu(customers);
    menu.run();

    return 0;
}