/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms5:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.05
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca {
    class Time {
        int m_numMins{};

    public:
        Time& reset();

        // Constructors and Destructors
        Time(unsigned int min = 0u);

        // Read and Write Functions
        std::ostream& displayMethod(std::ostream& ostr = std::cout) const;
        std::istream& readMethod(std::istream& istr = std::cin);

        // Operator Overloads
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
        virtual ~Time() = default;
    };

    std::ostream& operator<<(std::ostream& ostr, const Time& T);
    std::istream& operator>>(std::istream& istr, Time& T);
} // namespace seneca

#endif
