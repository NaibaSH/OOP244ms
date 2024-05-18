/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms4:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.29
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca {
    class Time {
        int m_minutes{};

    public:
        Time& reset();
        Time(unsigned int min = 0u);
        std::ostream& displayMethod(std::ostream& ostr = std::cout) const;
        std::istream& readMethod(std::istream& istr = std::cin);
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
        virtual ~Time() = default;
    };

    std::ostream& operator<<(std::ostream& ostr, const Time& time);
    std::istream& operator>>(std::istream& istr, Time& time);
} // namespace seneca

#endif


