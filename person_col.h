#ifndef PERSON_COL_H
#define PERSON_COL_H

#include <map>
#include <algorithm>

using namespace std;

template <typename L>
class PersonCol {
    public:
        void add_person(L& c)
        {
            unsigned int cardId = c.getCardId();
            if (!has_id(cardId)) {
                persons.insert(typename map<unsigned int, L>::value_type(cardId, c));
            }
            else {
            cout << "Such a person already exists" << endl;
            }
        
        }
        void delete_person(unsigned int id)
        {
            typename map<unsigned int, L>::iterator it = persons.find(id);
            if (it != persons.end()) {
                persons.erase(it);
            }
            else {
                cout << "Such a person does not exist" << endl;
            }
        }
        L& get_person(unsigned int id)
        {
            return persons.find(id)->second;
        }
        void show_all()
        {
            cout<<"Persons: "<<endl;
            typename map<unsigned int, L>::iterator it;
            for(it = persons.begin(); it != persons.end(); it++) {
                cout << it->second.to_string()<<endl;
            }
        }

        bool has_id(unsigned int id)
        {
            return persons.find(id) != persons.end();
        }
        bool empty()
        {
            return persons.empty();
        }
        const map<unsigned int, L>& get_persons() const
        {
            return persons;
        }
    private:
        map<unsigned int, L> persons;
};

#endif
