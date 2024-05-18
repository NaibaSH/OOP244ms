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


#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include <iostream>
#include "Ticket.h"
#include "IOAble.h"

using namespace std;

namespace seneca {
	class Patient : public IOAble {
	private:
		char* m_name; // Dynamically allocated C-string
		int m_ohipNum;
		Ticket m_ticket;

	public:
		Patient(int ticket_no);
		Patient(const Patient& p2);
		Patient& operator=(const Patient& p2);
		virtual ~Patient();
		virtual char type() const = 0;
		bool operator==(char c) const;
		bool operator==(const Patient& p2) const;
		void setArrivalTime();
		Time time() const;
		int number() const;
		operator bool() const;
		operator const char* () const;
		ostream& write(ostream& ostr) const override;
		istream& read(istream& istr) override;
	};
}
#endif // !SENECA_PATIENT_H
