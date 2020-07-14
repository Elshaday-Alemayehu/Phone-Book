//Phonebook.h

#include"PhoneEntry.h"

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#include<iostream>

class PhoneBook
{
    private:
        int maxSize; //max size of phonebook

        PhoneEntry *entries; //pointer of phone entry class

        int entrySize; //current entry size

    public:
        PhoneBook(); //default constructor

        PhoneBook(int maxEntries); //constructor

        PhoneBook(const PhoneBook &otherBook);

        virtual ~PhoneBook(); //destructor with dynamic binding

        void add(std::string name, std::string number);

        int findFirstByName(const std::string &name) const;

        int findFirstByNumber(const std::string &number) const;

        int findFirst(const PhoneEntry &entry) const;

        void removeByName(std::string name);

        void removeByNumber(std::string number);

        void remove(const PhoneEntry &entry);

        int getCapacity() const;

        int getSize() const;

        PhoneEntry& at(int position);

        const PhoneEntry& at(int position) const;

        PhoneEntry& operator[](int position);

        const PhoneEntry& operator[](int position) const;

        const PhoneBook& operator=(const PhoneBook &rhs);


};





#endif
