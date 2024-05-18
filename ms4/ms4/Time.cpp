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
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	Time& Time::reset()
	{
		m_minutes = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		if (min > 0) {
			m_minutes = min;
		}
		else {
			m_minutes = 0;
		}

	}

	ostream& Time::displayMethod(ostream& ostr) const
	{
		ostr << std::setfill('0') << std::setw(2) << (m_minutes / 60) << ":" << std::setw(2)
			<< (m_minutes % 60);
		return ostr;
	}

	istream& Time::readMethod(istream& istr) {
		int hour = 0;
		istr >> hour;

		if (istr.peek() != ':') {
			istr.setstate(std::ios::failbit);
			return istr;
		}
		else {
			istr.ignore();
		}
		istr >> m_minutes;
		if (istr) {
			m_minutes += hour * 60;
		}
		return istr;
	}

	Time::operator unsigned int() const
	{
		return m_minutes;
	}

	Time& Time::operator*=(int val)
	{
		if (val > 0) {
			m_minutes *= val;
		}
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		int difference = this->m_minutes - D.m_minutes;
		if (difference < 0) {
			difference += 1440;
		}
		m_minutes = difference;
		return *this;
	}

	Time Time::operator-(const Time& T) const
	{
		int difference = this->m_minutes - T.m_minutes;
		if (difference < 0) {
			difference += 1440;
		}
		return Time(difference);
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