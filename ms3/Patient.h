
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

#ifndef PATIENT_H
#define PATIENT_H

#include "Ticket.h"
#include "IOAble.h"
#include "Time.h"
#include <iostream>

namespace seneca {
    class Patient : public IOAble {
        Ticket m_ticket; // Patient's ticket
        int m_OHIP; // OHIP number
        char* m_name; // Patient's name
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

#endif // PATIENT_H


