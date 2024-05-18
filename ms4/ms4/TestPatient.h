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

#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H

#include <iostream>
#include "Patient.h"

namespace seneca {
	class TestPatient : public Patient {
	public:
		TestPatient();
		char type() const;
		std::ostream& write(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);
	};
}

#endif


