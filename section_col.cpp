#include <map>
#include <iostream>
#include "section_col.h"
#include <algorithm>

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
        cout << "This book does not exist" << endl;
    }
}

Section& SectionCol::get_section(string name) {
    return sections.find(name)->second;
}

const map<string, Section>& SectionCol::get_sections() const {
    return sections;
}

void SectionCol::show_all()
{
    cout<<"Sections: "<<endl;
    map<string, Section>::iterator it;
    for(it = sections.begin(); it != sections.end(); it++) {
        cout << it->second<<endl;
    }
}



