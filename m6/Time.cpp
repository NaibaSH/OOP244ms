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

#include <iostream>
#include "Time.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	Time& Time::reset()
	{
		m_numMins = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		if (min > 0) {
			m_numMins = min;
		}
	}

	// Display method to write the time into the ostream in the HH:MM Format.
	ostream& Time::displayMethod(ostream& ostr) const
	{
		ostr.width(2);
		ostr.fill('0');
		ostr.setf(ios::right);
		ostr << m_numMins / 60 << ":";
		ostr.width(2);
		ostr.fill('0');
		ostr << m_numMins % 60;
		ostr.unsetf(ios::right);
		return ostr;
	}

	// Display method to read the time from the istream in H:M Format, ensuring H and M are separated by ':'.
	istream& Time::readMethod(istream& istr) {
		int hours{};
		char delimiter{};
		int mins{};

		istr >> hours;

		if (!istr || hours < 0) {
			istr.setstate(ios::failbit);
		}
		// Checking if Enter key was pressed after entering hours
		else if (istr.peek() == '\n') {
			istr.setstate(ios::failbit);
		}
		// Trying to read the next character, and if unsuccessful or not equal to ':', set failbit
		else if (!(istr >> delimiter) || delimiter != ':') {
			istr.setstate(ios::failbit);
		}
		// Trying to read minutes, and if unsuccessful or negative, set failbit
		else if (!(istr >> mins) || mins < 0) {
			istr.setstate(ios::failbit);
		}
		else {
			// Converting the user input of Hours and Minutes into seconds and storing it into the 'm_numMins' member variable
			m_numMins = (hours * 60) + mins;
		}

		return istr;
	}

	Time::operator unsigned int() const
	{
		return m_numMins;
	}

	Time& Time::operator*=(int val)
	{
		if (val > 0) m_numMins *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_numMins > D.m_numMins) {
			m_numMins -= D.m_numMins;
		}
		else {
			m_numMins = m_numMins + 1440 - D.m_numMins;
		}
		return *this;
	}

	Time Time::operator-(const Time& T) const
	{
		Time t;
		if (m_numMins > T.m_numMins) {
			t.m_numMins = m_numMins - T.m_numMins;
		}
		else {
			t.m_numMins = m_numMins + 1440 - T.m_numMins;
		}
		return t;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& T)
	{
		return T.displayMethod(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& T)
	{
		return T.readMethod(istr);
	}
}