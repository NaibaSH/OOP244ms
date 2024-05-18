/***********************************************************************
// OOP244 Project
//
// File  ms52_test.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
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
void theApp() {
   PreTriage P("smalldata.csv");
   P.run();
}
int main() {
   copyFile("smalldata.csv", "smalldata.csv.bak");
   seneca::debug = true;
   U.setDebugTime(14, 40);
   theApp();
   displayFile("smalldata.csv");
   return 0;
}


