/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms2:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.16
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
namespace seneca {
    class IOAble {
    public:
        virtual std::ostream& write(std::ostream& ostr)const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual ~IOAble() {};
    };
    std::ostream& operator<<(std::ostream& ostr, const IOAble& I);
    std::istream& operator>>(std::istream& istr, IOAble& I);
}
#endif // !IOABLE_H
