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
            people.insert(typename map<unsigned int, L>::value_type(cardId, c));
        }
        else {
        cout << "Such a person already exists" << endl;
        }

    }
    void delete_person(unsigned int id)
    {
        typename map<unsigned int, L>::iterator it = people.find(id);
        if (it != people.end()) {
            people.erase(it);
        }
        else {
            cout << "Such a person does not exist" << endl;
        }
    }

    int get_size() const
    {
        return people.size();
    }

    L& get_person(unsigned int id)
    {
        //typename map<unsigned int,L>::iterator it = people.find(id);
        // return it->second;
        return people.at(id);
    }
//https://www.cplusplus.com/reference/map/map/at/

//https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class

    void show_all()
    {
        cout<<"people: "<<endl;
        typename map<unsigned int, L>::iterator it;
        for(it = people.begin(); it != people.end(); it++) {
            cout << it->second.to_string()<<endl;
        }
    }

    bool has_id(unsigned int id) const
    {
        return people.find(id) != people.end();
    }

    bool empty() const
    {
        return people.empty();
    }

    const map<unsigned int, L>& get_people() const
    {
        return people;
    }

private:
        map<unsigned int, L> people;
};

#endif
