#ifndef section_h
#define section_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//header działu!

class Section
{
    public:
        Section()
        {
            name = "Unknown";
            description = "Unknown";
            position = "Unknown";
            symbol = "A";
            bookcase_num = 0; 
            supervisor = "Unknown";
            books = {};
        }

        Section(std::string name,
                std::string description,
                std::string position, 
                std::string symbol, int bookcase_num, 
                std::string supervisor, 
                std::vector <std::string> books);

        Section(const Section &section)
        {
            name = section.name;
            description = section.description;
            position = section.position;
            symbol = section.symbol;
            bookcase_num = section.bookcase_num; 
            supervisor = section.supervisor;
            books = section.books;
        }
        
        friend std::ostream& operator << (std::ostream& output, const Section &s);

        friend bool operator == (const Section &s1, const Section &s2);

        friend bool operator != (const Section &s1, const Section &s2);

        Section& operator=(const Section &s);

        void add_book(std::string title);

        void del_book(std::string title);

        void change_description(std::string new_description);

        void change_position(std::string new_position);

        void change_symbol(std::string new_symbol);

        void change_bookcase_num(int new_num);

        void change_name(std::string new_name);

        std::string get_name() const;

        std::string get_description() const;

        std::string get_position() const;
        
        int get_bookcase_num() const;

        std::string get_symbol() const;

        const std::vector<std::string>& get_books() const;

    protected:
        std::vector <std::string> books;

        std::string name;

        std::string description;

        std::string position;

        std::string supervisor;

        int bookcase_num;

        std::string symbol;
};
#endif
