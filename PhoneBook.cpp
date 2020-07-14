/*

PhoneBook.cpp

*/


#include"PhoneBook.h"

#include"PhoneEntry.h"

#include<iostream>

/*
The default Phone book constructor will dynamically allocate new phoneEntry array with
,maximum size of 10
*/

PhoneBook::PhoneBook()
{
    entries = new PhoneEntry[10];

    maxSize = 10;

    entrySize = 0;


}

/*
Phone book constructor will dynamically allocate new phoneEntry array with
,maximum entries size
*/

PhoneBook::PhoneBook(int maxEntries)
{
    entries = new PhoneEntry[maxEntries];

    maxSize = maxEntries;

    entrySize = 0;


}

/*
This constructor will assign pointer of this to phone book reference
*/

PhoneBook::PhoneBook(const PhoneBook &otherBook)
{
    *this = otherBook;

}

/*
The phone book constructor deletes the dynamically allocated array
and assigns it to nullptr
*/

PhoneBook::~PhoneBook()
{
    delete [] entries;
    entries = nullptr;

    entrySize = 0;

    maxSize = 0;

}

/*
fill in the next available PhoneEntry with the passed in name and number.
If there are no more available entries the function it return
and not add the name and number to the phone book.
*/

void PhoneBook::add(std::string name, std::string number)
{
    if(entrySize >= maxSize)
    {
        return;
    }
    else
    {
        entries[entrySize].setName(name);

        entries[entrySize].setNumber(number);

        entrySize++;


    }

}


//this function will return the index of the first entry with the specified name
// and returns -1 if not found

int PhoneBook::findFirstByName(const std::string &name) const
{
    int index = -1;
    bool isFound = false;
    int i = 0;
    do{
            if(entries[i].getName() == name)
            {
                index = i;
             isFound = true;

            }
            i++;

    }while(!isFound && i < maxSize);

    return index;

}

//this function function will return the index of the first entry with the
//specified number and returns -1 if not found

int PhoneBook::findFirstByNumber(const std::string &number) const
{
    int index = -1;
    bool isFound = false;
    int i = 0;
    do{
            if(entries[i].getNumber() == number)
            {
                index = i;
             isFound = true;

            }
            i++;

    }while(!isFound && i < maxSize);

    return index;



}


//this function will return the index of the first
//entry with the specified PhoneEntry values

int PhoneBook::findFirst(const PhoneEntry &entry) const
{
    int index = -1;
    bool isFound = false;
    int i = 0;
    do{
            if(entries[i].getName() == entry.getName() &&
               entries[i].getNumber() == entry.getNumber())
           {
                index = i;
                isFound = true;

             }

            i++;

    }while(!isFound && i < maxSize);

    return index;


}


// this function will remove the first entry in the phone book it finds
//that has a name that matches the passed in parameter.

void PhoneBook::removeByName(std::string name)
{
    for(int i = 0;i < entrySize;i++)
    {
        if(entries[i].getName() == name)
        {
            for(int j = 0; j< entrySize; j++)
            {
                entries[i].setName(entries[j+1].getName());
                entries[i].setNumber(entries[j+1].getNumber());
            }

            entrySize--;

        }

    }
}

//this function removes the first entry in the phone book that contains the number specified by the input parameter.
//it return and do nothing if the number is not found.

void PhoneBook::removeByNumber(std::string number)
{
    for(int i = 0;i < entrySize;i++)
    {
        if(entries[i].getNumber() == number)
        {
            for(int j = 0; j< entrySize; j++)
            {
                entries[i].setName(entries[j+1].getName());
                entries[i].setNumber(entries[j+1].getNumber());
            }

            entrySize--;


        }

    }

}

//this  function removes the first entry in the phone book where the name and number match
//the value of the passing in PhoneEntry.

void PhoneBook::remove(const PhoneEntry &entry)
{
    for(int i = 0;i < entrySize;i++)
    {
        if(entry.getNumber() == entries[i].getNumber() && entry.getName() == entries[i].getName())
        {
            remove(entries[i]);

        }

    }

}

//returns returns the number of entries currently in use

int PhoneBook::getCapacity() const
{
    return maxSize;

}

//returns the maximum number of entries the phone book can support

int PhoneBook::getSize() const
{

    return entrySize;

}

//functions return the current entry at the index passed to the function
//via the position parameter


PhoneEntry& PhoneBook::at(int position)
{
    if(position >= maxSize)
    {
        return entries[entrySize-1];
    }

        return entries[position];



}

const PhoneEntry& PhoneBook::at(int position) const
{
       return (*this)[position];
}

//functions return the current entry at the index passed to
//the function via the position parameter

PhoneEntry& PhoneBook::operator[](int position)
{
    if(position >= maxSize)
    {
        return entries[entrySize-1];
    }

        return entries[position];




}

const PhoneEntry& PhoneBook::operator[](int position) const
{
     return (*this)[position];

}

//this function deletes the lhs array and creates a new one copy the values
//from the right hand side to the left hand side.

const PhoneBook& PhoneBook::operator=(const PhoneBook &rhs)
{
    if(this== &rhs)
    {
        return *this;
    }
    maxSize = rhs.maxSize;

    delete[]entries; //deleting the lhs array

    entries = new PhoneEntry[maxSize]; // creating a new array

    entrySize = rhs.entrySize;

    for(int i = 0; i < entrySize; i++)
    {
        entries[i] = rhs.entries[i]; //copying value from rhs to lhs
    }
    return *this;

}

