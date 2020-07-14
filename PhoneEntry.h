//phoneentry.h

#ifndef _PHONEENTRY_H

#define _PHONEENTRY_H
#include<iostream>

class PhoneEntry
{
    private:

        std::string name;

        std::string number;

    public:

        std::string getName() const;

        std::string getNumber() const;

        void setName(std::string newName);

        void setNumber(std::string newNumber);

        const PhoneEntry& operator=(const PhoneEntry &rhs);

        bool operator==(const PhoneEntry &rhs) const;

        bool operator<(const PhoneEntry &rhs) const;

        bool operator<=(const PhoneEntry &rhs) const;

        bool operator>(const PhoneEntry &rhs) const;

        bool operator>=(const PhoneEntry &rhs) const;

        bool operator!=(const PhoneEntry &rhs) const;

        PhoneEntry(); //defualt constructor

        PhoneEntry(const PhoneEntry &other); //copy constructor

        PhoneEntry(std::string newName, std::string newNumber); //a two argument constructor

        virtual ~PhoneEntry(); //destructor
};
std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs); //standalone function for output




#endif
