/***********************************************************************
// OOP244 Project ms1
//
// File  timeTester.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

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
#include <iostream>
#include "Time.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
Time readTime();
int main() {
   seneca::debug = false;
   Time D(1385), C(65), E;
   cout << "E: " << E << endl;
   cout << "D: " << D << endl;
   cout << "C: " << C << endl;
   cout << endl << "operator-= ................." << endl;
   cout << "  D        C      D-=C" << endl;
   cout << D << " -= " << C << " = ";
   cout << (D -= C) << endl;
   cout << "  C        D      C-=D" << endl;
   cout << C << " -= " << D << " = ";
   cout << (C -= D) << endl;
   cout << endl << "operator- .................." << endl;
   cout << "  C       D      C-D" << endl;
   cout << C << " - " << D << " = ";
   cout << (C - D) << endl;
   cout << "  C        D" << endl;
   cout << C << "    " << D << endl;
   cout << endl << "operator*= ................." << endl;
   cout << "C: " << C << endl;
   cout << " C *= 2" << endl;
   cout << (C *= 2) << endl;
   cout << " C *= 12" << endl;
   cout << (C *= 12) << endl;
   cout << "\nEnter following values:\nabc\n12\n1.1\n1:1\n------------------------" << endl;
   cout << "you entered: " << readTime() << endl;
   cout << "\nEnter following value:\n30:0\n------------------------" << endl;
   cout << "you entered: " << readTime() << endl;
   cout << "\nEnter following value:\n1:1234\n------------------------" << endl;
   cout << "you entered: " << readTime() << endl;
   seneca::debug = true;
   cout << "Default dubugging start time: ";
   E.reset();
   cout << E << endl;
   cout << "Custome debugging start time: ";
   U.setDebugTime(15, 22);
   E.reset();
   cout << E << endl;
   seneca::debug = false;
   cout << "Actual system time is: " << Time().reset() << endl;
   return 0;
}

Time readTime() {
   Time E;
   bool done;
   cout << "Time\n> ";
   do {
      done = true;
      cin >> E;
      if (cin.fail()) {
         cin.clear();
         cin.ignore(1000, '\n');
         done = false;
         cout << "Bad time entry, retry (HH:MM): ";
      }
   } while (!done);
   return E;
}