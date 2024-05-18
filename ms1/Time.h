/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms1:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.12
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_
#include <iostream>
#include "Utils.h"
namespace seneca {
    class Time {
        int minutes;

    public:
        Time& reset();
        Time(unsigned int min = 0u);
        std::ostream& writeMethod(std::ostream& ostr = std::cout) const;
        std::istream& readMethod(std::istream& istr = std::cin);
        operator unsigned int()const;
        Time& operator*= (int val);
        Time& operator-= (const Time& D);
        Time operator-(const Time& T)const;
    };
     std::ostream& operator<<(std::ostream& ostr, const Time& time);
     std::istream& operator>>(std::istream& istr, Time& time);
}
#endif // !SENECA_UTILS_H_


