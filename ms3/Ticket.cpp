/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms3:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.22
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
   
   Time Ticket::time() const {
      return m_time;
   }

   int Ticket::number() const {
      return m_number;
   }

   void Ticket::resetTime() {
      m_time.reset();
   }

   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
       // Write the ticket in a CSV format: number,time
       ostr << m_number <<" "<< m_time;
       return ostr;
   }

   std::istream& Ticket::csvRead(std::istream& istr) {
       // Read the ticket in a CSV format: number,time
       char delimiter;
       istr >> m_number >> delimiter >> m_time;
       return istr;
   }

  std::ostream& Ticket::write(std::ostream& ostr) const {
    if (&ostr == &std::cout) {
        ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
    } else if (&ostr == &std::clog) {
        ostr << m_number << " " << m_time;
    } else {
        ostr << m_number << "," << m_time;
    }
    return ostr;
}


   std::istream& Ticket::read(std::istream& istr) {
      istr >> m_number;
      istr.ignore(); 
      return istr >> m_time;
   }
}
