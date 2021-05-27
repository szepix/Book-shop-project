#ifndef UTILS_H
#define UTILS_H

#include <string>


using namespace std;
// downloading data from an external file
vector<vector<string>> read_from_file(string file);
// writing data to an external file
void write_to_file(string file, string text);

#endif
