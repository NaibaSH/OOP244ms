/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms54:
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
#include "Ticket.h"
using namespace std;
namespace seneca {
   Ticket::Ticket(int number) {
      m_number = number;
   }
   Time Ticket::time() const
   {
      return m_time;
   }
   int Ticket::number() const {
      return m_number;
   }
   void Ticket::resetTime() {
      m_time.reset();
   }
   std::ostream& Ticket::write(std::ostream& ostr) const {
      if (&ostr != &cout) {
         ostr << m_number << "," << m_time;
      }
      else {
         ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
      }
      return  ostr;
   }
   std::istream& Ticket::read(std::istream& istr) {
      istr >> m_number;
      istr.ignore();
      return istr >> m_time;
   }
}
