#include "test.h"

using namespace std;

//Klasa do testowania!

void Test::start_menu()
{
    cout<<"Bookstore section"<<endl;
    cout<<"1. Fantasy"<<endl;
    cout<<"2. Biography"<<endl;
    cout<<"3. Compare sections"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Choose operaion or section to work with by its number: "<<endl;
}

void Test::main_menu()
{
    cout<<"Bookstore section"<<endl;
    cout<<"1. Get the name of the section"<<endl;
    cout<<"2. Get the description of the section"<<endl;
    cout<<"3. Get the position of the section"<<endl;
    cout<<"4. Get the number of bookcases in the section"<<endl;
    cout<<"5. Get the symbol of the section"<<endl;
    cout<<"6. Get titles of books in the section"<<endl;
    cout<<"7. Change name of the section"<<endl;
    cout<<"8. Change the description of the section "<<endl;
    cout<<"9. Change the position of the section"<<endl;
    cout<<"10. Change the number of bookcases in the section"<<endl;
    cout<<"11. Change the symbol of the section"<<endl;
    cout<<"12. Add book to the section"<<endl;
    cout<<"13. Delete book from the section"<<endl;
    cout<<"14. Copy section"<<endl;
    cout<<"15. Assign to second section"<<endl;
    cout<<"16. Get section info"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Choose desired operation by its number: "<<endl;
}

bool Test::checking_first_value(string input)
{
    for (int i = 0; i<input.size();i++)
    {
        if(!isdigit(input[i]))
        {
            cout<<"Choose number of operation from list!"<<endl;
            return false;
        }
    }
    return true;
}

bool Test::checking_second_value(string input)
{
    for (int i = 0; i<input.size();i++)
    {
        if(!isdigit(input[i]))
        {
            cout<<"Value shoud be an intiger!"<<endl;
            return false;
        }
    }
    return true;
}   


void Test::test()
{
    Section Fantasy;
    Section Biography;
    while (x < 0)
    {
        this->start_menu();
        getline(cin, input_1);
        check_1 = this->checking_first_value(input_1);
        if (check_1 == false)
        {
            continue;
        }
        else
        {
            input_1_new = atoi(input_1.c_str());
        }
        switch (input_1_new)
        {
            case fantasy:
            case biography:
                this->main_menu();
                getline(cin, input_2);
                check_2 = this->checking_first_value(input_2);
                if (check_2 == false)
                {
                    continue;
                }
                else
                {
                    input_2_new = atoi(input_2.c_str());       
                }
                switch (input_2_new)
                {
                    case get_name:
                        if (input_1_new == fantasy)
                            {
                                cout <<"Name: " <<Fantasy.get_name()<<endl;
                            }
                        else if (input_1_new == biography)
                            {
                                cout <<"Name: " <<Biography.get_name()<<endl;
                            }
                        break;
                    case get_description:
                        if (input_1_new == fantasy)
                            {
                                cout <<"Description: "<<Fantasy.get_description()<<endl;
                            }
                        else if (input_1_new == biography)
                            {
                                cout <<"Description: "<<Biography.get_description()<<endl;
                            }
                        break;
                    case get_position:
                        if (input_1_new == fantasy)
                            {
                                cout <<"Position: "<< Fantasy.get_position()<<endl;
                            }
                        else if (input_1_new == biography)
                            {
                                cout <<"Position: "<< Biography.get_position()<<endl;
                            }
                        break;
                    case get_bookcase:
                        if (input_1_new == fantasy)
                            {
                                cout <<"Bookcases: "<< Fantasy.get_bookcase_num()<<endl;
                            }
                        else if (input_1_new == biography)
                            {
                                cout <<"Bookcases: "<< Biography.get_bookcase_num()<<endl;
                            }
                        break;
                    case get_symbol:
                        if (input_1_new == fantasy)
                            {
                                cout <<"Symbol: "<< Fantasy.get_symbol()<<endl;
                            }
                        else if (input_1_new == biography)
                            {
                                cout <<"Symbol: "<< Biography.get_symbol()<<endl;
                            }
                        break;
                    case get_titles:
                        if (input_1_new == fantasy)
                            {
                                Fantasy.get_books();
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.get_books();
                            }
                        break;
                    case change_name:
                            cout << "Choose new name: ";
                            getline(cin, choice_str);
                        if (input_1_new == fantasy)
                            {
                                Fantasy.change_name(choice_str);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.change_name(choice_str);
                            }
                        break;
                    case change_description:
                            cout << "Choose new description: ";
                            getline(cin, choice_str);
                        if (input_1_new == fantasy)
                            {
                                Fantasy.change_description(choice_str);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.change_description(choice_str);
                            }
                        break;
                    case change_position:
                            cout << "Choose new position: ";
                            getline(cin, choice_str);
                        if (input_1_new == fantasy)
                            {
                                Fantasy.change_position(choice_str);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.change_position(choice_str);
                            }
                        break;
                    case change_bookcase:
                            cout << "Choose new number of bookcases: ";
                            getline(cin, choice_int);
                            check_3 = this->checking_second_value(choice_int);
                            if (check_3 == false)
                            {
                                continue;
                            }
                            else
                            {
                                choice_int_new = atoi(choice_int.c_str());
                            }
                        if (input_1_new == fantasy)
                            {
                                Fantasy.change_bookcase_num(choice_int_new);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.change_bookcase_num(choice_int_new);
                            }
                        break;
                    case change_symbol:
                            cout << "Choose new symbol: ";
                            getline(cin, choice_char);
                        if (input_1_new == fantasy)
                            {
                                Fantasy.change_symbol(choice_char);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.change_symbol(choice_char);
                            }
                        break;
                    case add:
                            cout << "Enter title of the book you want to add: ";
                            getline(cin, choice_str);
                        if (input_1_new == fantasy)
                            {
                                Fantasy.add_book(choice_str);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.add_book(choice_str);
                            }
                        break;
                    case del:
                            cout << "Enter title of the book you want to delete: ";
                            getline(cin, choice_str);
                        if (input_1_new == fantasy)
                            {
                                Fantasy.del_book(choice_str);
                            }
                        else if (input_1_new == biography)
                            {
                                Biography.del_book(choice_str);
                            }
                        break;
                    case copy:
                        cout << "Enter name of section that will be a copy: ";
                        getline(cin, choice_str);
                        if (input_1_new == fantasy)
                            {
                                Section choice_str = Section(Fantasy);
                            }
                        else if (input_1_new == biography)
                            {
                                Section choice_str = Section(Biography);
                            }
                        break;
                    case assign:
                        if (input_1_new == fantasy)
                            {
                                Biography = Fantasy;
                            }
                        else if (input_1_new == biography)
                            {
                                Fantasy = Biography;
                            }
                        break;
                    case exit:
                        x = 1;
                        break;
                    case info:
                        if (input_1_new == fantasy)
                            {
                                cout<<Fantasy<<endl;
                            }
                        else if (input_1_new == biography)
                            {
                                cout<<Biography<<endl;
                            }
                    default:
                        cout<<"Choose number of operation from list!"<<endl;
                    
                
                }
                break;
                break;
            case compare:
                Fantasy == Biography;
                break;
            case exit:
                x = 1;
                break;
            default:
                cout<<"Choose number of operation from list!"<<endl;

        }

    }
}

