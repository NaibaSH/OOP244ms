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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
#include "Utils.h"

using namespace std;

namespace seneca {

	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket++) {
		symptoms = nullptr;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	ostream& TriagePatient::write(ostream& os) const {
		if (&os == &cout) { // If the output is the console
			os << "TRIAGE" << endl;
			Patient::write(os);
			os << "Symptoms: " << symptoms << endl;
		}
		else if (&os == &clog) { // If the output is the log
			Patient::write(os);
		}
		else { // If the output is a file
			Patient::write(os);
			os << ',' << symptoms;
		}
		return os;
	}

	istream& TriagePatient::read(istream& is) {
		delete[] symptoms;
		Patient::read(is);
		char temp[512];
		if (&is == &std::cin) {
			std::cout << "Symptoms: ";
			is.getline(temp, 512);
		}
		else {
			is.ignore(2000, ',');
			is.getline(temp, 512);
			nextTriageTicket = number() + 1;
		}
		symptoms = new char[U.strlen(temp) + 1];
		U.strcpy(symptoms, temp);
		if (is.fail()) {
			delete[] symptoms;
			symptoms = nullptr;
		}
		return is;
	}

	TriagePatient::~TriagePatient() {
		delete[] symptoms;
	}

}
