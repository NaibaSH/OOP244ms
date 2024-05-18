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
#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H
#include "Patient.h"

namespace seneca {
	extern int nextTestTicket;
	class TestPatient :public Patient {
	public:
		// Default Constructor
		TestPatient();
		char type()const;
		std::ostream& write(std::ostream& ostr = std::cout) const override;
		std::istream& read(std::istream& istr = std::cin)override;
		virtual ~TestPatient() = default;
	};
}
#endif