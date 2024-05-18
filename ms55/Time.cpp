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
#include <iostream>
#include "Time.h"
#include "Utils.h"

using namespace std;

namespace seneca {

	Time& Time::reset() {
		m_min = U.getTime();
		return *this;
	}

	// Set the time to zero by default
	Time::Time(unsigned int min) {
		m_min = min;
	}

	// Writes the time into a stream in HH:MM format
	ostream& Time::write(ostream& ostr) const {
		int hour = m_min / 60;
		int minute = m_min % 60;

		ostr.fill('0');
		ostr.width(2);
		ostr << hour << ":";
		ostr.width(2);
		ostr << minute;

		return ostr;
	}

	istream& Time::read(istream& istr) {
		int hours = 0;
		int mins = 0;
		char delimiter = '\0';

		// Reads the integer for the hours using istream.
		istr >> hours;

		// If the input fails, set the failbit and return the stream.
		if (istr.fail()) {
			istr.setstate(ios::failbit);
		}

		// Read the next character
		istr.get(delimiter);

		// If the next character is not a colon, set the failbit and return the stream.
		if (delimiter != ':') {
			istr.putback(delimiter);
			istr.setstate(ios::failbit);
		}

		// Otherwise, read the integer for the minutes.
		else {
			istr >> mins;
			if (istr.fail())
				istr.setstate(ios::failbit);
			else {
				m_min = hours * 60 + mins;
			}
		}
		return istr;
	}


	Time::operator unsigned int()const {
		return m_min;
	}

	Time& Time::operator*= (int val) {
		return *this = Time(m_min * val);
	}

	Time& Time::operator-= (const Time& D) {
		int timeDiff = -1;
		if (m_min < D.m_min) {
			timeDiff = (m_min + (24 * 60)) - D.m_min;
		}
		else {
			timeDiff = m_min - D.m_min;
		}
		m_min = timeDiff;
		return *this;
	}

	Time Time::operator-(const Time& T) const {
		int minDiff = m_min - T.m_min;
		if (minDiff < 0) {
			minDiff += 24 * 60;
		}
		return Time(minDiff);
	}

	ostream& operator<<(ostream& ostr, const Time& T) {
		return T.write(ostr);
	}

	istream& operator>>(istream& istr, Time& T) {
		return T.read(istr);
	}
}
