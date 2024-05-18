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



#include "IOAble.h"
#include <iostream>

using namespace std;

namespace seneca {
	// pure virtual functions
	ostream& operator<<(ostream& ostr, const IOAble& ioable) {
		return ioable.write(ostr);
	}

	istream& operator>>(istream& istr, IOAble& ioable) {
		return ioable.read(istr);
	}
}
