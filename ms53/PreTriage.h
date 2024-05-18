/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms53:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.06
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/




#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H


#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include "Time.h"
#include "Utils.h"

namespace seneca {

    const int maxPatients = 100;

    class PreTriage {
    private:
        Time m_avgContaigenWaitTime;
        Time m_avgTriageWaitTime;
        Patient* patientLineup[maxPatients];
        char* m_dataFileName;
        int m_numOfPatients;

        void load();
        void save();
        void regPatient();
        void admit();
        void lineup();
        const Time getWaitTime(const Patient& P) const;
        void setAverageWaitTime(const Patient& P);
        int indexOfFirstInLine(char type) const;

    public:
        PreTriage(const char* dataFileName);
        ~PreTriage();
        void run();
    };
}

#endif // SENECA_PRETRIAGE_H

