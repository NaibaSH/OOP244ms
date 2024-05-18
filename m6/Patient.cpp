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
#include <fstream>
#include "Patient.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	const int OHIP_MIN = 100000000;
	const int OHIP_MAX = 999999999;
	Patient::Patient(int ticketNumber) : m_patientName{}, m_OHIP{}, m_t(ticketNumber)
	{}

	Patient::Patient(const Patient& P)
	{
		operator=(P);
	}

	Patient& Patient::operator=(const Patient& otherPatient)
	{
		if (this != &otherPatient) {
			delete[] m_patientName;
			m_patientName = new char[strlen(otherPatient.m_patientName) + 1];
			strcpy(m_patientName, otherPatient.m_patientName);
			m_OHIP = otherPatient.m_OHIP;
			m_t = otherPatient.m_t;
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
		m_t.resetTime();
	}

	Time Patient::time() const {
		return m_t.time();
	}

	unsigned int Patient::number() const
	{
		return m_t.number();
	}

	Patient::operator bool() const
	{
		return m_t.number() != 0;
	}

	Patient::operator const char* () const
	{
		return m_patientName;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		if (&ostr == &clog) {
			if (m_patientName && m_patientName[0] && m_OHIP >= 100000000 && m_OHIP <= 999999999) {
				ostr.width(53);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << m_patientName;
				ostr.unsetf(ios::left);
				ostr << m_OHIP;
				ostr.fill(' ');
				ostr.setf(ios::right);
				ostr.width(5);
				ostr << m_t.number() << " ";
				ostr.unsetf(ios::right);
				ostr << m_t.time();
			}
			else {
				ostr << "Invalid Patient Record" << endl;
			}
		}
		else if (&ostr == &cout) {
			if (m_patientName && m_patientName[0] && m_OHIP != 0) {
				ostr << m_t << "\n" << m_patientName << ", OHIP: " << m_OHIP << "\n";
			}
			else {
				ostr << "Invalid Patient Record" << endl;
			}
		}
		else {
			ostr << this->type() << "," << m_patientName << "," << m_OHIP << ",";
			m_t.write(ostr);
		}
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		delete[] m_patientName;
		m_patientName = nullptr;

		char ch[100]{};
		if (&istr == &cin) {
			istr.clear();
			cout << "Name: ";
			istr.get(ch, 51, '\n');
			istr.ignore(1000, '\n');
			m_patientName = new char[strlen(ch) + 1];
			strcpy(m_patientName, ch);
			cout << "OHIP: ";
			m_OHIP = U.getIntOHIP(OHIP_MIN, OHIP_MAX);
		}
		else {
			if (istr) {
				istr.clear();
				istr.get(ch, 51, ',');
				istr.ignore(1000, ',');
				m_patientName = new char[strlen(ch) + 1];
				strcpy(m_patientName, ch);
				istr >> m_OHIP;
				istr.ignore(100, ',');
				m_t.read(istr);
			}
			else {
				delete[] m_patientName;
				m_patientName = nullptr;
			}
		}
		return istr;
	}

	seneca::Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
	}
}
