

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
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
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

    // Function to validate integer value by the user
    int Utils::getInt(int value) {
        int val{};
        char delimeter[100]{};
        cin >> val;
        while (cin.fail()) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;
            cin.getline(delimeter, 100);
        }
        while (delimeter[0]) {
            delimeter[0] = 0;
            cout << "Only enter an integer, try again: ";
            cin >> val;
            cin.getline(delimeter, 100);
        }
        while (val < 0 || val > value) {
            cout << "Invalid value enterd, retry[0 <= value <= " << value << "]: ";
            cin >> val;
            cin.clear();
            cin.ignore(100, '\n');
        };
        return val;
    }

    int Utils::getIntOHIP(int min, int max)
    {
        int input{};
        cin >> input;
        if (cin.fail()) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> input;
        }
        while (input < min || input > max) {
            input = 0;
            cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> input;
        }
        cin.ignore(100,'\n');
        return input;
    }
}