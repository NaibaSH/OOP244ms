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

#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
      Ticket(int number);
      Time time()const;
      int number()const;
      void resetTime();
      std::ostream& write(std::ostream& ostr )const;
      std::istream& read(std::istream& istr);
      std::ostream& csvWrite(std::ostream& ostr) const;
      std::istream& csvRead(std::istream& istr);
   };
}
#endif // !SENECA_TICKET_H_
