/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Ms54:
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
#define MIN_OHIP_NUM 100000000
#define MAX_OHIP_NUM 999999999
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "Utils.h"


namespace seneca {
	Patient::Patient(int ticket_num) : m_ticket(ticket_num) {
		m_name = nullptr;
		m_ohipNum = 0;
	}

	Patient::Patient(const Patient& p2) : m_ticket(p2.m_ticket) {
		m_name = new char[strlen(p2.m_name) + 1];
		strcpy(m_name, p2.m_name);
		m_ohipNum = p2.m_ohipNum;
	}

	Patient& Patient::operator=(const Patient& p2) {
		if (this != &p2) {
			U.aloCopy(m_name, p2.m_name);
			m_ohipNum = p2.m_ohipNum;
			m_ticket = p2.m_ticket;

		}
		return *this;
	}

	Patient::~Patient() {
		delete[] m_name;
	}

	bool Patient::operator==(char c) const {
		return type() == c;
	}

	bool Patient::operator==(const Patient& p2) const {
		return type() == p2.type();
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Time Patient::time() const {
		return m_ticket.time();
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	Patient::operator bool() const {
		return m_name != nullptr && strlen(m_name) > 0 && m_ohipNum >= MIN_OHIP_NUM && m_ohipNum <= MAX_OHIP_NUM;
	}

	Patient::operator const char* () const {
		return m_name;
	}

	ostream& Patient::write(ostream& ostr) const {
		if (m_name == nullptr) {
			ostr << "Invalid Patient Record" << endl;
		}
		else {
			if (&ostr == &clog) {
				ostr.setf(ios::left);
				ostr.width(53);
				ostr.fill('.');
				ostr << m_name;
				ostr.unsetf(ios::left);
				ostr << m_ohipNum;
				ostr.setf(ios::right);
				ostr.width(5);
				ostr.fill(' ');
				ostr << m_ticket.number();
				ostr.unsetf(ios::right);
				ostr << ' ';
				ostr << m_ticket.time();
			}
			else if (&ostr == &cout) {
				m_ticket.write(ostr);
				ostr << endl;
				ostr << m_name << ", OHIP: " << m_ohipNum << endl;
			}
			else {
				ostr << type() << ',';
				ostr << m_name << ',';
				ostr << m_ohipNum << ',';
				m_ticket.write(ostr);
			}
		}
		return ostr;
	}

	istream& Patient::read(istream& istr) {
		char localName[51];
		if (&istr == &cin) {
			cout << "Name: ";
			U.getCstr(localName, 50);
			cout << "OHIP: ";
			m_ohipNum = U.getInt();
			while (m_ohipNum < MIN_OHIP_NUM || m_ohipNum > MAX_OHIP_NUM) {
				std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				m_ohipNum = U.getInt();
			}
		}
		else {
			istr.get(localName, 51, ',');
			istr.ignore(1000, ',');
			istr >> m_ohipNum;
			istr.ignore(1000, ',');
			m_ticket.read(istr);
		}
		U.aloCopy(m_name, localName);

		return istr;
	}
}
