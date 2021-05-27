#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "utils.h"

using namespace std;

vector<vector<string>> read_from_file(string file){
    ifstream myFile(file);
    string lineText;
    string lineTextValue;

    vector<vector<string>> parts = {};
    getline(myFile, lineText);
    // TODO OBSŁUŻYĆ BŁĄD !!!
    if(myFile){
        while (getline(myFile, lineText)) {
            vector<string> part;
            stringstream ss;
            ss<<lineText;
            while(getline(ss, lineTextValue, ',')) {
                part.push_back(lineTextValue);
            }
            parts.push_back(part);
        }
    }

    myFile.close();

    return parts;
}

void write_to_file(string file, string text) {
    ofstream myFile(file);
    if (myFile) {
        myFile << text;
    }

    myFile.close();

}
