/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms53:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.06
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/



#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
using namespace std;

namespace seneca {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0u);
        ostream& write(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);
        operator unsigned int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
    };
    // Helper functions for << and >> prototypes
    ostream& operator<<(ostream& ostr, const Time& T);
    istream& operator>>(istream& istr, Time& T);
}
#endif // !SENECA_TIME_H
