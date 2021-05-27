#ifndef PERSON_COL_H
#define PERSON_COL_H

#include <map>
#include <algorithm>

using namespace std;

//Class PersonCol which is a template for storing elements of specified types
//Contains private variable - people

template <typename L>
class PersonCol {
public:

//methods for adding and removing elements from collection
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

//getters
    int get_size() const
    {
        return people.size();
    }

    L& get_person(unsigned int id)
    {
        return people.at(id);
    }

     const map<unsigned int, L>& get_people() const
    {
        return people;
    }

//method for printing informations about all elements
    void show_all()
    {
        cout<<"People: "<<endl;
        typename map<unsigned int, L>::iterator it;
        for(it = people.begin(); it != people.end(); it++) {
            cout << it->second.to_string()<<endl;
        }
    }

//methods for for checking if collection is empty or if person with specified id is in the collection
    bool has_id(unsigned int id) const
    {
        return people.find(id) != people.end();
    }

    bool empty() const
    {
        return people.empty();
    }

private:
        map<unsigned int, L> people;
};

#endif
