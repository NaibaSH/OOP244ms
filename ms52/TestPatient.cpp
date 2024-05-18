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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TestPatient.h"

using namespace std;

namespace seneca {
	int nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(nextTestTicket++) {
	}

	char TestPatient::type() const {
		return 'C';
	}

	ostream& TestPatient::write(ostream& os) const {
		if (&os == &cout) {
			os << "Contagion TEST" << endl;
		}
		Patient::write(os);
		return os;
	}

	istream& TestPatient::read(istream& is) {
		Patient::read(is);
		if (&is != &cin) {
			nextTestTicket = this->number() + 1;
		}
		return is;
	}
}
