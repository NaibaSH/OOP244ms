/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Ms52:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.07
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H	
#include <iostream>

using namespace std;

namespace seneca {
	class IOAble {
	public:
		virtual ostream& write(ostream& ostr) const = 0;
		virtual istream& read(istream& istr) = 0;
		virtual ~IOAble() {};
	};
	ostream& operator<<(ostream& ostr, const IOAble& ioable);
	istream& operator>>(istream& istr, IOAble& ioable);
}

#endif // !SENECA_IOABLE_H
