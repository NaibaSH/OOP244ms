/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms52:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.07
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
    const size_t MAX_DYNAMIC_READ = 4096u;
    int Utils::getTime() {
        int mins = -1;
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // end provided code

    // code provided in Utils.cpp of Prof's notes
    size_t Utils::strlen(const char* str) {
        size_t len{};
        while (str[len]) {
            len++;
        }
        return len;
    }

    char* Utils::strcpy(char* des, const char* src) {
        size_t i;
        for (i = 0; src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0;
        return des;
    }

    void Utils::aloCopy(char*& des, const char* src) {
        delete[] des;
        des = nullptr;
        if (src && src[0]) {
            des = new char[U.strlen(src) + 1];
            U.strcpy(des, src);
        }
    }

    int Utils::getInt() {
        int val{};
        cin >> val;
        while (cin.fail()) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> val;
        }
        cin.ignore(10000, '\n'); // wipe keyboard clean
        return val;
    }

    void Utils::getCstr(char* str, size_t len) {
        cin.getline(str, len + 1);
        // same as cin.getline( str, len + 1, '\n' );
        while (cin.fail()) {
            cout << "Maximum of " << len << " chars, retry\n> ";
            cin.clear();
            cin.ignore(100000, '\n');
            cin.getline(str, len + 1);
        }
    }
}
