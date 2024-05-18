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

#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>
namespace seneca {

	class IOAble {
	public:
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual ~IOAble() = default;
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
	std::istream& operator>>(std::istream& istr, IOAble& obj);
}
#endif // !SENECA_IOABLE_


