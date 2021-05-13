#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

bool checking_int(string choice);
bool checking_money_val(string choice);

void entering_int_data(int *number, string text);
void entering_money_val(double *number, string text);
void enter_option(string text, int* new_choice, int end_range);

#endif
