
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


#ifndef SENECA_IOABLE_H_
#define SENECA_IOABLE_H_
#include <iostream>

namespace seneca {
    class IOAble {
    public:
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual ~IOAble() = default;
    };

    // Helper insertion and extraction operators
    std::ostream& operator<<(std::ostream& ostr, const IOAble& I);
    std::istream& operator>>(std::istream& istr, IOAble& I);
}

#endif // !SENECA_IOABLE_H_
