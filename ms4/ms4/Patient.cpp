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
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Patient.h"
using namespace std;
namespace seneca {
	Patient::Patient(int ticketNumber) : m_name(nullptr), m_ohipNumber(0), m_ticket(ticketNumber) {

	}

	Patient::Patient(const Patient& otherPatient)
	{
		operator=(otherPatient);
	}

	Patient& Patient::operator=(const Patient& otherPatient)
	{
		if (this != &otherPatient) {
			delete[] m_name;
			m_name = new char[strlen(otherPatient.m_name) + 1];
			strcpy(m_name, otherPatient.m_name);
			m_ohipNumber = otherPatient.m_ohipNumber;
			m_ticket = otherPatient.m_ticket;
		}
		return *this;
	}

	bool Patient::operator==(const char ch) const
	{
		return this->type() == ch;
	}
	bool Patient::operator==(const Patient& otherPatient) const
	{
		return this->type() == otherPatient.type();
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Time Patient::time() const {
		return m_ticket.time();
	}

	unsigned int Patient::number() const
	{
		return m_ticket.number();
	}

	Patient::operator bool() const
	{
		if (m_name != nullptr && m_name[0] != '\0' && m_ohipNumber > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	Patient::operator const char* () const
	{
		return m_name;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		if (&ostr == &clog) {
			if (m_name && m_name[0] && m_ohipNumber > 0) {
				ostr << std::setw(53) << std::left << std::setfill('.') << m_name
					<< m_ohipNumber << std::setfill(' ') << std::setw(5) << std::right
					<< m_ticket.number() << " " << m_ticket.time();
			}
			else {
				ostr << "Invalid Patient Record";
			}
		}
		else if (&ostr == &cout) {
			if (m_name != nullptr && m_name[0] != '\0' && m_ohipNumber > 0) {
				ostr << m_ticket << endl;
				ostr << m_name << ", OHIP: " << m_ohipNumber << std::endl;
				return ostr;
			}
			else {
				ostr << "Invalid Patient Record" << endl;
			}
		}
		else {
			ostr << this->type() << ',' << m_name << ',' << m_ohipNumber << ',';
			m_ticket.write(ostr);
		}
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		delete[] m_name;
		m_name = nullptr;
		char patientName[100]{};
		if (&istr == &cin) {
			int ohipNumber = 0;
			bool done = false;
			cout << "Name: ";
			istr.get(patientName, 51, '\n');
			m_name = new char[strlen(patientName) + 1];
			strcpy(m_name, patientName);
			cout << "OHIP: ";
			do {
				istr >> ohipNumber;
				if (istr) {
					if (ohipNumber >= 100000000 && ohipNumber <= 999999999) {
						done = true;
						m_ohipNumber = ohipNumber;
					}
					else {
						cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
					}
					istr.clear();
					istr.ignore(1000, '\n');
				}
				else {
					istr.clear();
					istr.ignore(200, '\n');
					cout << "Bad integer value, try again: ";
				}
			} while (!done);
			return istr;
		}
		else {
			if (istr) {
				istr.clear();
				istr.get(patientName, 51, ',');
				istr.ignore(2000, ',');
				m_name = new char[strlen(patientName) + 1];
				strcpy(m_name, patientName);
				istr >> m_ohipNumber;
				istr.ignore(300, ',');
				m_ticket.read(istr);
			}
			else {
				delete[] m_name;
				m_name = nullptr;
			}
		}
		return istr;
	}

	seneca::Patient::~Patient()
	{
		delete[] m_name;
		m_name = nullptr;
	}
}
