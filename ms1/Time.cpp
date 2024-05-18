/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms1:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.12
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    Time& Time::reset() {
        if (debug) {
            minutes = U.getTime() % 1440;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            minutes = lt.tm_hour * 60 + lt.tm_min;
        }
        return *this;
    }
    Time::Time(unsigned int min) {
        if (min > 0) {
            minutes = min;
        }
        else {
            minutes = 0;
        }
    }
    std::ostream& Time::writeMethod(std::ostream& ostr) const {
        ostr << std::setfill('0') << std::setw(2) << (minutes / 60) << ":" << std::setw(2) << (minutes % 60);
        return ostr;
    }
    std::istream& Time::readMethod(std::istream& istr) {
        int hour = 0;
        istr >> hour;

        if (istr.peek() != ':') {
            istr.setstate(std::ios::failbit);
            return istr;
        }
        else {
            istr.ignore();
        }
        istr >> minutes;
        if (istr) {
            minutes += hour * 60;
        }
        return istr;
    }
    Time::operator unsigned int()const {
        return minutes;
    }
    Time& Time::operator*= (int val) {
        minutes *= val;
        return *this;
    }
    Time& Time::operator-= (const Time& D) {
        int difference = this->minutes - D.minutes;
        if (difference < 0) {
            difference += 1440;
        }
        minutes = difference;
        return *this;
    }
    Time Time::operator-(const Time& T)const {
        int difference = this->minutes - T.minutes;
        if (difference < 0) {
            difference += 1440;
        }
        return Time(difference);
    }
    std::ostream& operator <<(std::ostream& ostr, const Time& time) {
        time.writeMethod();
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Time& time) {
        time.readMethod();
        return istr;
    }

}