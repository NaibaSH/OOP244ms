/***********************************************************************
// OOP244 Project ms2
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
                         OOP244 Ms2:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.06.12
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <fstream>
#include "IOAble.h"
using namespace std;
using namespace seneca;
void displayFile(const char* filename) {
    ifstream file(filename);
    cout << filename << "---------------------" << endl;
    char ch;
    while (file.get(ch) && cout << ch);
    cout << "---------------------------------" << endl;
}
class Box :public IOAble {
    int m_hieght, m_width;
public:
    Box() :m_hieght(0), m_width(0) {
        cout << "defaulting Box" << endl;
    };
    ostream& write(ostream& ostr)const {
        if (&ostr != &cout) {
            ostr << m_hieght << "," << m_width;
        }
        else {
            int i;
            for (int j = 0; j < m_hieght; j++) {
                for (i = 0; i < m_width * 2; i++, ostr << "*");
                ostr << endl;
            }
        }
        return ostr;
    }
    istream& read(istream& istr) {
        if (&istr != &cin) {
            istr >> m_hieght;
            istr.ignore();
            istr >> m_width;
            istr.ignore();
            return istr;
        }
        else {
            cout << "Height: ";
            istr >> m_hieght;
            cout << "Width: ";
            istr >> m_width;
        }
        return istr;
    }
    ~Box() {
        cout << "Box(" << m_hieght << "," << m_width << ") is gone!" << endl;
    }
};
int main() {
    Box B;
    cout << "Enter the following values:\n10\n20\n----------------------------" << endl;
    cout << "Getting information of an IOAble box from console: " << endl;
    cin >> B;
    cout << "Display the IOAble box on console: " << endl;
    cout << B << endl;
    ifstream fboxes("boxes.txt");
    if (fboxes) {
        Box* Bp;
        ofstream bout("boxesOut.txt");
        clog << "Saving " << B << " in the output file." << endl;
        bout << B << endl;
        cout << "Dynamically allocating a Box and holding it in an IOAble pointer..." << endl;
        IOAble* iop = Bp = new Box();
        cout << "Reading dimenstions from file using the IOAlbe pointer" << endl;;
        fboxes >> *iop;
        cout << "Dimentions: " << endl;
        clog << *iop << endl;
        cout << "What it looks like on screen:" << endl << *iop << endl;
        cout << "Now save it in the file..." << endl;
        bout << *iop << endl;
        cout << "Reading the next dimenstions from file using the IOAble pointer" << endl;;
        fboxes >> *iop;
        cout << "Dimentions: " << endl;
        clog << *iop << endl;
        cout << "What it looks like on screen:" << endl << *iop << endl;
        cout << "Save this one in the output file too..." << endl;
        bout << *iop << endl;
        cout << "Close the file and display it..." << endl;
        bout.close();
        cout << "Content of \"boxesOut.txt\" file" << endl;
        displayFile("boxesOut.txt");
        cout << "Removing the box from memory using the IOAble pointer..." << endl;
        delete Bp;
        bout.close();
    }
    else {
        cout << "Could not find the file \"boxes.txt\"." << endl;
    }
    return 0;
}