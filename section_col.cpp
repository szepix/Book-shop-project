#include <map>
#include <iostream>
#include "section_col.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

void SectionCol::add_section(Section& c){
    string sectionName = c.get_name();
    sections.insert(map<string, Section>::value_type(sectionName, c));
}

void SectionCol::delete_section(string name) {
    map<string, Section>::iterator it = sections.find(name);
    if (it != sections.end()) {
        sections.erase(it);
    }
    else {
        throw logic_error("This section does not exist - " + name+"\n");
    }
}

Section& SectionCol::get_section(string name) {
    if (is_section(name)) {
        return sections.find(name)->second;
    }
    else {
        throw logic_error("This section does not exist - " + name+"\n");
    }
}

const map<string, Section>& SectionCol::get_sections() const {
    return sections;
}


bool SectionCol::is_section(string name)
{
    map<string, Section>::iterator it = sections.find(name);
    if (it != sections.end()) {
        return true;
    }
    return false;


    // // map<string, Section>::iterator it;
    // if (sections.find(name) != sections.end())
    // {
    //     return true;
    // }
    // return false;
}

void SectionCol::show_all()
{
    cout<<"Sections: "<<endl;
    map<string, Section>::iterator it;
    for(it = sections.begin(); it != sections.end(); it++) {
        cout << it->second<<endl;
    }
}






