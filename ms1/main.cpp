/***********************************************************************
// OOP244 Project ms1
//
// File  main.cpp
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
#include "Menu.h"
#include "Time.h"
#include "Utils.h"
using namespace seneca;
using namespace std; 
void menuTester();
void timeTester();
int main() {
   cout << "Menu tester -----------------------------------------" << endl;
   menuTester();
   cout << "Time tester -----------------------------------------" << endl;
   timeTester();
   return 0;
}


void menuTester() {
   Menu m("Tester Options menu:\n1- Option one\n2- Option two");
   int selection;
   cout << "Enter the following values:\nabc\n1 (with a space after 1)\n1\n0\n2\n3\n-1\n0\n----------------------------\n";
   while (m >> selection) {
      switch (selection) {
      case 1: {
         Menu sub_menu("Sub-menu of option one!\n1- sub one\n2- sub two\n3- sub two\n4- sub two", 1);
         switch (sub_menu >> selection) {
         case 1:
            cout << "   sub menu one selected" << endl << endl;
            break;
         case 2:
            cout << "   sub menu two selected" << endl << endl;
            break;
         case 0:
            cout << "   sub menu exit selected" << endl << endl;
            break;
         }
         break;
      }
      case 2:
         cout << "option two selected" << endl << endl;
         break;
      default:
         cout << "This will never happen!!!!" << endl;
         break;
      }
   }
   cout << "goodbye!" << endl;
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
void timeTester() {
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
}
