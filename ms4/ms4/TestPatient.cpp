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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "TestPatient.h"
#include "Patient.h"

using namespace std;
namespace seneca {
	int nextTestTicket = 1;
	TestPatient::TestPatient() :Patient(nextTestTicket++) {
	}

	char TestPatient::type() const {
		return 'C';
	}

	ostream& TestPatient::write(std::ostream& ostr) const {
		if (&ostr == &cout) {
			ostr << "Contagion TEST" << endl;
		}
		Patient::write(ostr);
		return ostr;
	}

	std::istream& TestPatient::read(std::istream& istr) {
		Patient::read(istr);
		if (&istr != &cin) {
			nextTestTicket = number() + 1;
		}
		return istr;
	}
}