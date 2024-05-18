
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

#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_

#include "IOAble.h"
#include "Ticket.h"
#include "Time.h" // Ensure you include the Time.h header if Time class is used

namespace seneca {
    class Patient : public IOAble {
        char* m_name; // Dynamically allocated C-string for patient name
        int m_OHIP; // OHIP number
        Ticket m_ticket; // Patient's ticket

    public:
        Patient(int ticketNumber = 0);
        Patient(const Patient& other); // Copy constructor
        Patient& operator=(const Patient& other); // Copy assignment operator
        virtual ~Patient(); // Destructor

        virtual char type() const = 0; // Pure virtual function

        // Overloaded operators
        bool operator==(char ch) const;
        bool operator==(const Patient& other) const;

        void setArrivalTime();
        Time time() const; // Change return type to Time
        int number() const;

        // Cast overloads
        operator bool() const;
        operator const char* () const;

        // IOAble pure virtual function overwrites
        std::ostream& write(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };
}

#endif // !SENECA_PATIENT_H_
