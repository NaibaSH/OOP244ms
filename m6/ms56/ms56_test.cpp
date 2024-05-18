/***********************************************************************
// OOP244 Project
//
// File  ms56_test.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
***********************************************************************/
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
#include <fstream>
#include "PreTriage.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
void copyFile(const char* des, const char* src) {
   ifstream infile(src);
   ofstream outfile(des);
   if (outfile) {
      char ch;
      while (infile.get(ch)) {
         outfile.put(ch);
      }
   }
}
void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void theFullLine( ) {
   PreTriage P( "bigdata.csv" );
   P.run( );
}
void theApp( ) {
   PreTriage P( "smalldata.csv" );
   P.run( );
}
int main() {
   copyFile( "bigdata.csv", "bigdata.csv.bak" );
   copyFile( "smalldata.csv", "smalldata.csv.bak" );
   seneca::debug = true;
   U.setDebugTime(8, 41);
   theFullLine( );
   theApp();
   displayFile( "smalldata.csv" );
   displayFile( "bigdata.csv" );
   return 0;
}


