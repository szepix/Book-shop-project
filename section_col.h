#ifndef SECTION_COL_H
#define SECTION_COL_H

#include "section.h"
#include <map>

using namespace std;

// Class SectionCol contains private variable sections
// An object of class SectionCol represents the collection of sections that a bookshop has.

class SectionCol
{
    public:
    // method to add section to variable sections
    void add_section(Section& c);
    // method to remove section from variable sections
    void delete_section(string name);
    // checking whether such a section exists
    bool is_section(string name);
    // getter of an object of class Section
    Section& get_section(string name);
    // getter of the variable sections
    const map<string, Section>& get_sections() const;
    // method to show all sections
    void show_all();
    private:
        map<string, Section> sections;
};

#endif