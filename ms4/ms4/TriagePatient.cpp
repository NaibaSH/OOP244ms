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
#include "TriagePatient.h"
#include "Patient.h"

using namespace std;
namespace seneca {
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() : Patient(nextTriageTicket++), sympyoms(nullptr) {

	}

	char TriagePatient::type() const {
		return 'T';
	}

	TriagePatient::TriagePatient(const TriagePatient& rhs) : Patient(rhs){
		if (rhs.sympyoms != nullptr && rhs.sympyoms[0] != '\0') {
			delete sympyoms;
			sympyoms = new char[strlen(rhs.sympyoms) + 1];
			strcpy(sympyoms, rhs.sympyoms);
		}
		else {
			sympyoms = nullptr;
		}
	}

	TriagePatient& TriagePatient::operator =(const TriagePatient& rhs) {
		if (this != &rhs) {
			Patient::operator= (rhs);
			(Patient&)*this = rhs;
			delete[] sympyoms;
			if (rhs.sympyoms != nullptr && rhs.sympyoms[0] != '\0') {
				sympyoms = new char[strlen(rhs.sympyoms) + 1];
				strcpy(sympyoms, rhs.sympyoms);
			}
			else {
				sympyoms = nullptr;
			}
		}
		return *this;
	}

	TriagePatient::~TriagePatient() {
		delete[] sympyoms;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const {
		if (&ostr == &cout) {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << "Symptoms: ";
			ostr << sympyoms << endl;
		}
		else if (&ostr == &clog) {
			Patient::write(ostr);
		}
		else{
			Patient::write(ostr);
			ostr << "," << sympyoms;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr) {
		delete[] sympyoms;
		sympyoms = nullptr;
		Patient::read(istr);
		char temporary[600];
		if (&istr != &cin) {
			istr.clear();
			istr.ignore(200, ',');
			istr.get(temporary, 511, '\n');
			sympyoms = new char[strlen(temporary) + 1];
			strcpy(sympyoms, temporary);
			nextTriageTicket = number() + 1;
		}
		else {
			cout << "Symptoms: ";
			istr.get(temporary, 511);
			sympyoms = new char[strlen(temporary) + 1];
			strcpy(sympyoms, temporary);
			istr.clear();
			istr.ignore(1000, '\n');
		}
		if (istr.fail()) {
			delete[] sympyoms;
			sympyoms = nullptr;
		}
		return istr;
	}


} 