/***********************************************************************
// OOP244 Project ms4
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
#include <fstream>
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
void CPTest(ifstream& input);
void TPTest(ifstream& input);

int main() {
    cout << "Milestone 4 tester" << endl;
    ifstream input("input.txt");
    CPTest(input);
    TPTest(input);
    return 0;
}

void CPTest(ifstream& input) {
    U.setDebugTime(12, 34);
    TestPatient A, B;
    cout << "Testing TestPatient:" << endl
        << "Enter the following values when prompted:" << endl
        << "aaa" << endl
        << "123123123" << endl
        << "------------------------" << endl << endl;
    A.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> A;
    cout << endl << "Enter the following values when prompted:" << endl
        << "bbb" << endl
        << "234234234" << endl
        << "------------------------" << endl << endl;
    B.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> B;
    cout << endl << "Patients information entered:" << endl;
    cout << A << endl << B << endl;
    cout << "CSV output:" << endl;
    cerr << A << endl << B << endl << endl;
    cout << "Linear output:" << endl;
    clog << A << endl << B << endl << endl;
    cout << "Testing CSV input;" << endl
        << "   Reading \"ccc,333333333,10,23:45\" from input.txt." << endl;
    input >> A;
    input.ignore(100, '\n');
    cout << endl << "Data read:" << endl;
    cout << A << endl;
    U.setDebugTime(23, 55);
    cout << "Testing global ticket number variable:" << endl
        << "Enter the following values when prompted:" << endl
        << "ddd" << endl
        << "345345345" << endl
        << "------------------------" << endl << endl;
    TestPatient C;
    C.setArrivalTime();
    cin >> C;
    cout << "Patient information entered:" << endl;
    cout << C << endl;
}
void TPTest(ifstream& input) {
    U.setDebugTime(12, 34);
    TriagePatient A, B;
    cout << "Testing TriagePatient:" << endl;
    cout << "Enter the following values when prompted:" << endl
        << "aaa" << endl
        << "123123123" << endl
        << "aaa aaa aaa" << endl
        << "------------------------" << endl << endl;
    A.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> A;
    cout << endl << "Enter the following values when prompted:" << endl
        << "bbb" << endl
        << "234234234" << endl
        << "bbb bbb bbb" << endl
        << "------------------------" << endl << endl;
    B.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> B;
    cout << endl << "Patients information entered:" << endl;
    cout << A << endl << B << endl;
    cout << "CSV output: " << endl;
    cerr << A << endl << B << endl << endl;
    cout << "Linear output:" << endl;
    clog << A << endl << B << endl << endl;
    cout << "Testing CSV input;" << endl
        << "   Reading \"ccc,333333333,10,23:45,ccc ccc ccc\" from input.txt." << endl;
    input >> A;
    input.ignore(100, '\n');
    cout << endl << "Data read:" << endl;
    cout << A << endl;
    U.setDebugTime(23, 55);
    cout << "Testing global ticket number variable:" << endl
        << "Enter the following values when prompted:" << endl
        << "ddd" << endl
        << "444444444" << endl
        << "ddd ddd ddd" << endl
        << "------------------------" << endl << endl;
    TriagePatient C;
    C.setArrivalTime();
    cin >> C;
    cout << endl << "Patient information entered:" << endl;
    cout << C << endl;
}