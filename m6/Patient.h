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

#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {
	class Patient :public IOAble {
		char* m_patientName{};
		int m_OHIP{};
		Ticket m_t = 0;
	public:
		// Constructor
		Patient(int number);
		// Copy-Constructor
		Patient(const Patient& other);
		// Copy Assignment
		Patient& operator=(const Patient& otherPatient);
		// Pure virtual function incapable of modifying the current object
		virtual char type()const = 0;
		// Operator overloads
		virtual bool operator==(const char ch)const;
		virtual bool operator==(const Patient& otherPatient)const;
		// Modifiers
		void setArrivalTime();
		// Queries
		Time time() const;
		unsigned int number() const;
		// Cast Overloads
		operator bool()const;
		operator const char* ()const;

		// Implementation of Virtual Functions
		virtual std::ostream& write(std::ostream& ostr = std::cout) const override;
		virtual std::istream& read(std::istream& istr = std::cin)override;
		// Destructor
		virtual ~Patient();
	};
}
#endif