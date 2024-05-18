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

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace seneca {
	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj)
	{
		return obj.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, IOAble& obj)
	{
		return obj.read(istr);
	}
}