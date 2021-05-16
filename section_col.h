#ifndef SECTION_COL_H
#define SECTION_COL_H

#include "section.h"
#include <map>

using namespace std;

class SectionCol
{
    public:
    void add_section(Section& c);
    void delete_section(string name);
    Section& get_section(string name);
    const map<string, Section>& get_sections() const;
    void show_all();
    private:
        map<string, Section> sections;
};

#endif