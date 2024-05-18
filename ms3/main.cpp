/***********************************************************************
// OOP244 Project ms3
//
// File  main.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Patient.h"
using namespace std;
namespace seneca {
   class WalkinPatient : public Patient {
   public:
      WalkinPatient(int ticketNumber = 0) :
         Patient(ticketNumber) { }
      char type()const {
         return 'W';
      }
      std::ostream& write(std::ostream& ostr)const {
         return Patient::write(ostr);
      }
      std::istream& read(std::istream& istr) {
         Patient::read(istr);
         if (&istr != &std::cin) {
            istr.ignore(10000, '\n');
         }
         return istr;
      }
      bool operator>(const WalkinPatient& wp)const {
         return  U.strcmp(*this, wp) > 0;
      }
   };
}
using namespace seneca;
void displayFile(const char* filename) {
   ifstream file(filename);
   std::cout << filename << "-----------------------" << endl;
   char ch;
   while (file.get(ch) && std::cout << ch);
   std::cout << "---------------------------------" << endl;
}
void testOperatorsCastAndNumber(const Patient& A, const Patient& B);
void sortPatients(WalkinPatient wp[], size_t num);
void dallocate(Patient* p);
void displayAll(const Patient* p, size_t num);

int main() {
   seneca::debug = true;
   ifstream csvfile("ms3.csv");
   ofstream csvoutfile("ms3out.csv");
   WalkinPatient* p = new WalkinPatient[6]{ 24 };
   WalkinPatient W = 24;

   cout << "Enter The following:" << endl <<
      "-------------------\nJohn Doe\nabc\n"
      "100\n123123123\n-------------------" << endl;
   cin >> W;
   W.setArrivalTime();
   cout << "Sections 1 and 2 should match:" << endl << endl;
   cout << "1- Your output on screen:" << endl << W;
   cout << "2- The output should be:" << endl <<
      "Ticket No: 24, Issued at: 08:00\n"
      "John Doe, OHIP: 123123123" << endl << endl;
   cerr << "1- Your comma separated and linear ouput:" << endl << W << endl;
   clog << W << endl;
   cout << "2- The comma-separated and linear ouput should be:" << endl <<
      "W,John Doe,123123123,24,08:00" << endl <<
      "John Doe.............................................123123123   24 08:00" << endl << endl;

   cout << "Reading the first csv from the data file" << endl;
   csvfile >> W;
   cout << "Sections 1 and 2 should match: " << endl << endl;
   cout << "1- Your output on screen:" << endl;
   cout << W << endl;
   cout << "2- The output should be:" << endl;
   cout << "Ticket No: 14, Issued at: 12:54\n"
      "A name that is way way way way way way way way way, OHIP: 444444444" << endl << endl;
   cout << "Reading the remaining 4 and save it in ms3out.csv:" << endl;
   int i = 0;
   while (csvfile >> W) {
      p[i++] = W;
      csvoutfile << W << endl;
   }
   cout << "Sorting based on patient's name" << endl;
   sortPatients(p, 4);
   cout << "Displaying sorted patient records" << endl;
   displayAll(p, 5);
   csvoutfile.close();
   displayFile("ms3out.csv");
   testOperatorsCastAndNumber(p[2], p[1]);
   dallocate(p);
   return 0;
}
void testOperatorsCastAndNumber(const Patient& A, const Patient& B) {
   cout << "Testing operator== overloads: " << endl;
   cout << (A == 'W' ? "Success!" : "Failed!") << endl;
   cout << (A == B ? "Success!" : "Failed!") << endl;
   cout << "Testing Ticket time and number: " << endl;
   cout << "W, Ticket Time: " << A.time() << endl;
   cout << "W, Ticket number: " << A.number() << endl;
}

void sortPatients(WalkinPatient wp[], size_t num) {
   for (size_t i = 0; i < num - 1; i++) {
      for (size_t j = 0; j < num - i - 1; j++) {
         if ((wp[j] && !wp[j + 1]) || (wp[j] && wp[j + 1] && wp[j] > wp[j + 1])) {
            WalkinPatient temp = wp[j];
            wp[j] = wp[j + 1];
            wp[j + 1] = temp;
         }
      }
   }
}
void dallocate(Patient* p) {
   delete[] p;
}
void displayAll(const Patient* p, size_t num) {
   cout << "Printing " << num << " patients:" << endl;
   for (size_t i = 0; i < num; i++) {
      cout << p[i] << endl;
   }
   cout << "---------------------------------" << endl << endl;
}