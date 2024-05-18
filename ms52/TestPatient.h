/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Ms52:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.07
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H
#include <iostream>
#include "Patient.h"
#include "Ticket.h"

using namespace std;

namespace seneca {
	extern int nextTestTicket;

	class TestPatient : public Patient {
	public:

		TestPatient();

		char type() const override;

		ostream& write(ostream& os) const override;

		istream& read(istream& is) override;

		virtual ~TestPatient() override = default;

	};
}
#endif //!SENECA_TESTPATIENT_H
