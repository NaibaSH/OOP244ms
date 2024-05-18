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


#include "IOAble.h"

namespace seneca {
    std::ostream& operator<<(std::ostream& ostr, const IOAble& I) {
        return I.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& I) {
        return I.read(istr);
    }
}
