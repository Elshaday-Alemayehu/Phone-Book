//assignment3.cpp

#include"PhoneBook.h"

#include"PhoneEntry.h"

#include<iostream>

using namespace std;

/*
The main needs to create a PhoneBook, add entries to the PhoneBook, and remove entries from the PhoneBook.
it also loop through the entries in the PhoneBook by using the getSize and phoneEntryAt functions and loops though the entries in
the PhoneBook by using the getSize function and subscripts [] then display the name and number using the << operator you created.
*/

int main()
{
    PhoneBook pBook(50);

    pBook.add("Sarah Jane Smith", "555-555-1212");

    for (int i = 0; i < pBook.getSize(); i++)
    {
        //// Create a reference to the returned PhoneEntry

        const PhoneEntry &item = pBook.at(i);
         cout << item << endl;
    }
    for (int index = 0; index < pBook.getSize(); index++)
    {
        // Create a reference to the returned PhoneEntry

        const PhoneEntry &item = pBook[index];

        //display name and number

        cout << item << endl;

    }
    pBook.removeByName("John Smith");

    pBook.removeByNumber("555-555-2211");

    pBook.remove(PhoneEntry("John Smith", "555-555-2211"));



    return 0;
}

