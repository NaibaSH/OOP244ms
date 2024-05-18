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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
using namespace std;
namespace seneca {
	int nextTriageTicket = 1;

	seneca::TriagePatient::TriagePatient() :Patient(nextTriageTicket), m_symptoms{}
	{
		nextTriageTicket++;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (&ostr == &cout) {
			ostr << "TRIAGE\n";
		}
		Patient::write(ostr);
		if (&ostr == &cout) {
			ostr << "Symptoms: " << m_symptoms << endl;
		}
		if (&ostr != &clog && &ostr != &cout) {
			ostr << "," << m_symptoms;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		char comma;
		delete[] m_symptoms;
		m_symptoms = nullptr;

		Patient::read(istr);
		if (&istr != &cin) {
			istr >> comma;

			char tempSymptoms[512]; // Local buffer to store symptoms
			istr.getline(tempSymptoms, 511, '\n');

			// Allocate memory and copy the local symptoms Cstring into the allocated memory
			m_symptoms = new char[strlen(tempSymptoms) + 1];
			strcpy(m_symptoms, tempSymptoms);

			// Set the nextTriageTicket global variable
			nextTriageTicket = number() + 1;
		}
		else {
			// Prompt for symptoms
			cout << "Symptoms: ";

			// Read the symptoms into the local Cstring
			char tempSymptoms[511]; // Local buffer to store symptoms
			istr.getline(tempSymptoms, 511);

			// Allocate memory and copy the local symptoms Cstring into the allocated memory
			m_symptoms = new char[strlen(tempSymptoms) + 1];
			strcpy(m_symptoms, tempSymptoms);
		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}



}