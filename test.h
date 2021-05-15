#ifndef test_h
#define test_h
#include "section.h"
#include <cstdlib>
#include <cctype>

//Header do testowania!

class Test
{
    public:
        void test();

        void start_menu();

        void main_menu();

        bool checking_first_value(std::string input);

        bool checking_second_value(std::string input);

        enum operations
        {
            fantasy = 1,
            biography = 2,
            compare =3,
            exit = 0,
            get_name = 1,
            get_description = 2,
            get_position = 3,
            get_bookcase = 4,
            get_symbol = 5,
            get_titles = 6,
            change_name = 7,
            change_description = 8,
            change_position = 9,
            change_bookcase = 10,
            change_symbol = 11,
            add = 12,
            del = 13,
            copy = 14,
            assign = 15,
            info = 16
        };

        std::string input_1;

        int input_1_new;

        std::string input_2;

        int input_2_new;

        std::string choice_str;

        std::string choice_char;

        std::string choice_int;

        int choice_int_new;
        
        bool check_1;

        bool check_2;

        bool check_3;

        bool check_4;
        
        int x = -1;

};
#endif
