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


#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H

#include <iostream>
#include "Patient.h"
#include "Utils.h"

using namespace std;

namespace seneca {
	extern int nextTriageTicket;

	class TriagePatient : public Patient {
	private:
		char* symptoms;
	public:
		TriagePatient();

		virtual char type() const;

		ostream& write(ostream& os) const override;

		istream& read(istream& is) override;

		virtual ~TriagePatient();

	};
}
#endif //!SENECA_TRIAGEPATIENT_H
