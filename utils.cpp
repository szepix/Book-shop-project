#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "utils.h"

using namespace std;

bool checking_int(string choice){
    int length = choice.length();
    for (int i=0; i < length; i++){
        if (isdigit(choice[i]) == false){
            return false;
        }
    }
    return true;
}

void entering_int_data(int *number, string text){
    int value;
    string data;
    bool condition = false;
    while (condition == false){
        cout<<text;
        cin>>data;
        if (checking_int(data) == true){
            if(stoi(data) >= 0){
                *number = stoi(data);
                condition = true;
            }
        }
        else{cout<<"Incorrect value\n";}
    }
}

void entering_money_val(double *number, string text){
    int value;
    string data;
    bool condition = false;
    while (condition == false){
        cout<<text;
        cin>>data;
        if (checking_money_val(data) == true){
            if(stod(data) >= 0){
                *number = stod(data);
                condition = true;
            }
        }
        else{cout<<"Incorrect value\n";}
    }
}

bool checking_money_val(string choice){
    int dots = 0;
    int length = choice.length();
    if (!(choice[length-3] == '.')){
        return false;
    }
    for (int i=0; i < length; i++){
        if ((isdigit(choice[i]) == false) && (choice[i] != '.')){
            return false;
        }
        else if (choice[i] == '.'){dots++;}
        if (dots > 1){return false;}
    }
    return true;
}

void enter_option(string text, int* new_choice, int end_range){
    string choice;
    bool condition = false;
    while (condition == false){
        cout << text;
        cin >> choice;
        if (checking_int(choice)){
            *new_choice = stoi(choice);
            if (*new_choice >= 1 && *new_choice <= end_range){
                condition = true;
            }
            else{cout << "There is no such option";}
        }
        else{cout << "Incorrect value"; }
    }
}

vector<vector<string>> read_from_file(string file){
    ifstream myFile(file);
    string lineText;
    string lineTextValue;

    vector<vector<string>> parts = {};

    if(myFile){
        while (getline(myFile, lineText)) {
            cout<<lineText;
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
