/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms3:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.22
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "Time.h"
#include "Utils.h"  
using namespace std;

namespace seneca {

    Time::Time(unsigned int min) : m_min(min) {}

    Time& Time::reset() {
        // Use U.getTime() here if needed
        m_min = U.getTime();

        return *this;
    }
    ostream& Time::write(ostream& os) const {
        os << setw(2) << std::setfill('0') << m_min / 60 << ":"
            << setw(2) << std::setfill('0') << m_min % 60;
        return os;
    }

    istream& Time::read(istream& istr) {
        int hour = 0, min = 0;
        char colon;

        istr >> hour >> colon >> min;
        if (hour >= 0 && min >= 0 && colon == ':') {
            m_min = hour * 60 + min;
        }
        else {
            istr.setstate(ios::failbit);
        }

        return istr;
    }


    Time::operator unsigned int() const {
        return m_min;
    }
    // In Time.cpp

    ostream& operator<<(ostream& os, const Time& time) {

        return time.write(os);
    }
    // In Time.cpp

    istream& operator>>(istream& is, Time& time) {
        return  time.read(is);;
    }

    Time& Time::operator*=(int val) {
        m_min *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        int diff = m_min - D.m_min;
        if (diff < 0) {
            diff += 1440; // Add 24 hours if negative
        }
        m_min = diff;
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        int diff = m_min - T.m_min;
        if (diff < 0) {
            diff += 24 * 60; // Add 24 hours if negative
        }
        return Time(diff);
    }

}