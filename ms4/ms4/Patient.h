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

#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {
	class Patient :public IOAble {
		char* m_name{};
		int m_ohipNumber{};
		Ticket m_ticket = 0;
	public:
		Patient(int ticketNumber);
		Patient(const Patient&);
		Patient& operator=(const Patient&);
		virtual char type()const = 0;
		virtual bool operator==(const char ch)const;
		virtual bool operator==(const Patient& otherPatient)const;
		void setArrivalTime();
		Time time() const;
		unsigned int number() const;
		operator bool()const;
		operator const char* ()const;
		std::ostream& write(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);
		virtual ~Patient();
	};
}
#endif
