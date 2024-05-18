
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

#define _CRT_SECURE_NO_WARNINGS

#include "Patient.h"
#include "Utils.h"
#include <cstring>
#include <iomanip> // For std::setw and std::setfill
#include <limits> 

namespace seneca {
    Patient::Patient(int ticketNumber) : m_OHIP(0), m_ticket(ticketNumber) {
        m_name = nullptr;
    }

    Patient::Patient(const Patient& other) : m_ticket(other.m_ticket) {
        if (other.m_name != nullptr) {
            m_name = new char[std::strlen(other.m_name) + 1];
            std::strcpy(m_name, other.m_name);
        }
        else {
            m_name = nullptr;
        }
        m_OHIP = other.m_OHIP;
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            delete[] m_name;
            if (other.m_name != nullptr) {
                m_name = new char[std::strlen(other.m_name) + 1];
                std::strcpy(m_name, other.m_name);
            }
            else {
                m_name = nullptr;
            }
            m_OHIP = other.m_OHIP;
            m_ticket = other.m_ticket;
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] m_name;
    }

    bool Patient::operator==(char ch) const {
        return type() == ch;
    }

    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }

    void Patient::setArrivalTime() {
        m_ticket.resetTime();
    }

    Time Patient::time() const {
        return m_ticket.time();
    }

    int Patient::number() const {
        return m_ticket.number();
    }

    Patient::operator bool() const {
        return m_name != nullptr && m_OHIP >= 100000000 && m_OHIP <= 999999999;
    }

    Patient::operator const char* () const {
        return m_name;
    }

    std::ostream& Patient::write(std::ostream& ostr) const {
        if (&ostr == &std::clog) {
            ostr << std::left << std::setw(53) << std::setfill('.') << m_name << std::right << m_OHIP << "   " << m_ticket.number() << " ";
            ostr << m_ticket.time();
        }
        else if (&ostr == &std::cout) {

            if (m_name != nullptr) {
                m_ticket.write(ostr) << std::endl;
                ostr << m_name << ", OHIP: " << m_OHIP << std::endl;
            }
            else {
                ostr << "Invalid Patient Record" << std::endl;
            }
        }
        else {
            ostr << type() << ',' << m_name << ',' << m_OHIP << ',';
            m_ticket.write(ostr);
        }
        return ostr;
    }

    std::istream& Patient::read(std::istream& istr) {
    if (&istr == &std::cin) {
        // Handle interactive input from the console
        char tempName[51]; // Temporary buffer for the name

        std::cout << "Name: ";
        istr.getline(tempName, 51); // Read up to 50 characters or until newline

        delete[] m_name;
        m_name = new char[std::strlen(tempName) + 1];
        std::strcpy(m_name, tempName);

        // OHIP number validation loop
        std::cout << "OHIP: ";
        while (true) {
            istr >> m_OHIP; // Attempt to read the OHIP number

            if (!istr) { // If the read failed due to non-integer input
                std::cout << "Bad integer value, try again: ";
                istr.clear(); // Clear the error state
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the line
            }
            else if (m_OHIP < 100000000 || m_OHIP > 999999999) {
                std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the line
            }
            else {
                break; // The input is valid, break out of the loop
            }
        }

        // Discard any trailing newline character
        istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
        // Handle non-interactive input, presumably from a file
        char tempName[101]; // Use a larger buffer for safety

        istr.getline(tempName, 101, ','); // Read the name up to a comma
        // Truncate the name if it's too long for your display requirements
        size_t nameLength = std::strlen(tempName);
        if (nameLength > 50) { // Assuming 50 characters is the maximum length you want
            tempName[50] = '\0'; // Truncate the string
        }

        delete[] m_name;
        m_name = new char[std::strlen(tempName) + 1];
        std::strcpy(m_name, tempName);
        

        istr >> m_OHIP; // Read the OHIP number
        istr.ignore(10000, ','); // Ignore up to the next comma

        if (!m_ticket.read(istr)) {
            // Handle error if ticket reading fails
            istr.setstate(std::ios::failbit);
        }
    }
    return istr;
    }

}
