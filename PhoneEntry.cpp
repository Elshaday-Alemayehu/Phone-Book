//PhoneEntry.cpp

#include"PhoneEntry.h"

#include"PhoneBook.h"

#include<iostream>


//default constructor

PhoneEntry::PhoneEntry()
{
    name = "";
    number = "";

}

//copy constructor copies name and number from rhs tp lhs

PhoneEntry::PhoneEntry(const PhoneEntry &other)
{
    if (this != &other)
	{
		name = other.getName();

		number = other.getNumber();
	}

}


//a two argument constructor

PhoneEntry::PhoneEntry(std::string newName, std::string newNumber)
{
    name = newName;

    number = newNumber;

}

//destructor

PhoneEntry:: ~PhoneEntry()
{

}

//returns name

std::string PhoneEntry::getName() const
{
    return name;

}

//returns number

std::string PhoneEntry::getNumber() const
{
    return number;

}

//sets name ti new name

void PhoneEntry::setName(std::string newName)
{
    name = newName;

}

//sets number to new number

void PhoneEntry::setNumber(std::string newNumber)
{
    number = newNumber;

}

//compares rhs this and lhs and copies name and number from rhs

const PhoneEntry& PhoneEntry::operator=(const PhoneEntry &rhs)
{
    if(this == &rhs)
    {
      return *this;
    }

    name = rhs.getName();
    number = rhs.getNumber();

    return *this;

}

//will return true only if both phone entries contain the same values for name,
//and the same values for number.

bool PhoneEntry::operator==(const PhoneEntry &rhs) const
{

   if(this->name == rhs.name && this->number == rhs.number )
   {
       return true;
   }


   return false;


}

//if the left hand side name and number is less than the right hand side name and number
// return true. else false

bool PhoneEntry::operator<(const PhoneEntry &rhs) const
{
    if(name < rhs.name || number < rhs.number)
    {
        return true;
    }

   return false;

}
//if the left hand side name and number is less than or equals to the right hand side name and number
// return true. else false

bool PhoneEntry::operator<=(const PhoneEntry &rhs) const
{
    if(name <= rhs.name && number <= rhs.number)
    {
        return true;
    }
    return false;

}

//if the left hand side name and number is greater than the right hand side name and number
// return true. else false

bool PhoneEntry::operator>(const PhoneEntry &rhs) const
{
    if(name > rhs.name || number > rhs.number)
    {
        return true;
    }
    return false;


}

//if the left hand side name and number is greater than or equals to the right hand side name and number
// return true. else false

bool PhoneEntry::operator>=(const PhoneEntry &rhs) const
{
    if(name >= rhs.name && number >= rhs.number)
    {
        return true;
    }
    return false;


}

//if the left hand side name and number is not equals to the right hand side name and number
// return true. else false

bool PhoneEntry::operator!=(const PhoneEntry &rhs) const
{
    if(name != rhs.name || number != rhs.number)
    {
        return true;
    }
    return false;


}

//output the contents of a phone entry to the output stream

std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs)
{
    out << "Name: " << rhs.getName();
    out << "Number: "<< rhs.getNumber();

    return out;
}



