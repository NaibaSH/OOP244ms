/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms3:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.22
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef TIME_H
#define TIME_H
#include <iostream>

namespace seneca {
    class Time {
        unsigned int m_min;  // Stores time in minutes

    public:
        Time(unsigned int min = 0u);  // Constructor

        Time& reset();  // Resets time to current or simulated system time

        std::ostream& write(std::ostream& os) const;  // Writes time in HH:MM format

        std::istream& read(std::istream& istr);
        operator unsigned int() const;  // Cast to unsigned int

        Time& operator*=(int val);  // Multiplies minutes by val
        Time& operator-=(const Time& D);  // Subtracts Time object from current object
        Time operator-(const Time& T) const;  // Returns new Time object after subtraction

    };
    std::ostream& operator<<(std::ostream& os, const Time& time);
    std::istream& operator>>(std::istream& is, Time& time);
}

#endif // TIME_H
