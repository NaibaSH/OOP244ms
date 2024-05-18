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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    const int MAX_PATIENT_NUM = 100;

    PreTriage::PreTriage(const char* dataFilename) :m_ContagionWaitTime{ 15 },m_TriageWaitTime{5}
	{
        if (dataFilename && dataFilename[0]) {
            strcpy(m_dataFilename, dataFilename);
            m_numPatients = 0;
            // Loads all the data from the data file
            load();
        }
	}

    PreTriage::~PreTriage()
    {
        // Saves the data
        save();
        // Iterates through the patient lineup and deletes the element one by one.
        for (int i = 0; i < m_numPatients; ++i) {
            delete m_lineup[i];
        }
    }

    Time PreTriage::getWaitTime(const Patient& patient) const {
        char type = patient.type();
        int count = 0;
        for (int i = 0; i < m_numPatients; ++i) {
            if (m_lineup[i]->type() == type)
                ++count;
        }
        Time waitTime = (type == 'C') ? m_ContagionWaitTime : m_TriageWaitTime;
        waitTime *= count;
        return waitTime;
    }

    void PreTriage::setAverageWaitTime(Patient& patient) {
        Time currentTime = U.getTime(); // Fetching the current time using the utility get Time method
        Time patientTicketTime = patient.time(); // Fetching the patients ticket time and storing it in a local variable
        Time& averageWaitTime = (patient.type() == 'C') ? m_ContagionWaitTime : m_TriageWaitTime; //  Storing the current avg. wait time based on the type of patient
        int ticketNumber = patient.number();

        // Calculating the new average wait time using the provided formula 
        averageWaitTime = ((currentTime - patientTicketTime) + (averageWaitTime * (ticketNumber - 1))) / ticketNumber;
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        int retVal = -1;
        // Loops through all the patient in the line to find the 1st patient of the same type as the function parameter and return it's index
        for (int i = 0; i < m_numPatients && retVal == -1; ++i) {
            if (m_lineup[i]->type() == type)
                retVal = i; // Patient found and it's index stored
        }
        return retVal;
    }

    void PreTriage::load() {
        bool retVal = true;
        ifstream file(m_dataFilename);

        cout << "Loading data..." << endl;

        if (!file.is_open()) {
            cerr << "No data or bad data file!\n\n";
            return;
        }

        file >> m_ContagionWaitTime; // reading the contagion test average wait time from the data file
        file.ignore(); // ignoring the comma
        file >> m_TriageWaitTime; // reading the triage average wait time from the data file
        file.ignore(); // ignoring the newline

        char type;
        while (m_numPatients < MAX_PATIENT_NUM && file >> type) { // Reading from the file until it reaches the max-limit of (100 patients) 
            file.ignore(); // Ignoring the comma after fetching the Type

            Patient* patient = nullptr; // Creating a local patient-pointer
            // Allocating memory based on the Patient type
            if (type == 'C') {
                patient = new TestPatient;
            }
            else if (type == 'T') {
                patient = new TriagePatient;
            }

            if (patient) {
                patient->read(file); // Using the read funciton of the Triage/Contagion
                m_lineup[m_numPatients++] = patient;
            }
        }

        // Displaying an error message if the m_numPatients exceeded 100 and the file did not end.
        if (m_numPatients == MAX_PATIENT_NUM && file.peek() != EOF) {
            cout << "Warning: number of records exceeded " << MAX_PATIENT_NUM << endl;
        }

        // Displaying No Data Presence if the number of patients is 0 (empty file or bad data).
        if (m_numPatients == 0) {
            cout << "No data or bad data file!\n\n";
            retVal = false;
        }

        // Displaying the total number of records imported if no error occured
        if(retVal == true) cout << m_numPatients << " Records imported..." << endl << endl;
    }

    void PreTriage::registerPatient()
    {
        Menu m("Select Type of Registration:\n1- Contagion Test\n2- Triage",1);
        int choice;

        if (m_numPatients < 100){
            m.display();

            cin >> choice;
            cin.ignore(1000, '\n');
            switch (choice) {
            case 0:
                break;
            case 1:
                    m_lineup[m_numPatients] = new TestPatient;
                    cout << "Please enter patient information: " << endl;
                    cin.clear();
                    cin >> *m_lineup[m_numPatients];
                    m_lineup[m_numPatients]->setArrivalTime();

                    cout << "\n******************************************\n";
                    cout << *m_lineup[m_numPatients];
                    cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_numPatients]);
                    cout << "\n******************************************\n\n";
                    ++m_numPatients;
                    break;

            case 2:
                    m_lineup[m_numPatients] = new TriagePatient;
                    cout << "Please enter patient information: " << endl;
                    cin.clear();
                    cin >> *m_lineup[m_numPatients];
                    m_lineup[m_numPatients]->setArrivalTime();

                    cout << "\n******************************************\n";
                    cout << *m_lineup[m_numPatients];
                    cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_numPatients]);
                    cout << "\n******************************************\n\n";
                    ++m_numPatients;

                break;
            }
        }
        else {
            cout << "Line up full!\n";
        }
    }

    void PreTriage::admit()
    {
        int choice,idx;
        Menu m("Select Type of Admittance:\n1- Contagion Test\n2- Triage",1);
        Time t = U.getTime();
        m.display();
        cin >> choice;
        cout << "\n******************************************\n";
        switch (choice) {
        case 0:
            break;
        case 1:
            idx = indexOfFirstInLine('C');
            if (idx != -1) {
                cout << "Call time: [" << t << "]" << endl;
                cout << "Calling at for "<< *m_lineup[idx];
                setAverageWaitTime(*m_lineup[idx]);
                removeDynamicElement(m_lineup, idx, m_numPatients);
            }
            else {
                cout << "Lineup is empty!\n";
            }
            break;

        case 2:
            idx = indexOfFirstInLine('T');
            if (idx != -1) {
                cout << "Call time: [" << t << "]" << endl;
                cout << "Calling at for " << *m_lineup[idx];
                setAverageWaitTime(*m_lineup[idx]);
                removeDynamicElement(m_lineup, idx, m_numPatients);
            }
            else {
                cout << "Lineup is empty!\n";
            }
            break;
        }
        cout << "******************************************\n\n";
    }

    void PreTriage::save() const {
        ofstream file(m_dataFilename);

        cout << "Saving lineup...\n";
        
        // Throwing an error message if the file did not open
        if (!file.is_open()) {
            cerr << "Failed to open file for saving data!" << endl;
            return;
        }

        file << m_ContagionWaitTime << "," << m_TriageWaitTime << endl; // Insert average wait times into the data file

        int numContagion = 0, numTriage = 0;
        for (int i = 0; i < m_numPatients; ++i) {
            file << *m_lineup[i] << endl; // Insert patient records into the data file

            // Counting the number of patient type for displaying the total number of records saved for each of them
            if (m_lineup[i]->type() == 'C') ++numContagion;
            else if (m_lineup[i]->type() == 'T') ++numTriage;
        }

        // Displaying the total number of records saved
        cout << numContagion << " Contagion Tests and " << numTriage << " Triage records were saved!" << endl;
    }

    void PreTriage::lineup() const
    {
        Menu m("Select The Lineup:\n1- Contagion Test\n2- Triage",1);
        int choice, counter = 1;
            
            m.display();

            cin >> choice;
            cout << "Row - Patient name                                          OHIP     Tk #  Time\n";
            cout << "-------------------------------------------------------------------------------\n";

            switch (choice) {
            case 0:
                break;

            case 1:
                for (int i = 0; i < m_numPatients && m_numPatients; ++i) {
                    if (m_lineup[i]->type() == 'C') {
                        clog.fill(' ');
                        clog.width(4);
                        clog.setf(ios::left);
                        clog << counter++;
                        clog.unsetf(ios::left);

                        clog << "- ";

                        m_lineup[i]->write(clog);
                        cout << endl;
                    }
                }
                if (m_numPatients == 0) clog << "Line up is empty!\n";

                break;

            case 2:
                for (int i = 0; i < m_numPatients && m_numPatients; ++i) {
                    if (m_lineup[i]->type() == 'T') {
                        clog.fill(' ');
                        clog.width(4);
                        clog.setf(ios::left);
                        clog << counter++;
                        clog.unsetf(ios::left);
                        clog << "- ";

                        m_lineup[i]->write(clog);
                        clog << endl;
                    }
                }
                if (m_numPatients == 0) clog << "Line up is empty!\n";
                break;
            }
        
        cout << "-------------------------------------------------------------------------------\n";

    }

    void PreTriage::run() {
        int choice;
        while (true) {
            Menu m("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
            m.display();
            cin >> choice;

            switch (choice) {
            case 0:
                return; // Quit the method
            case 1:
                registerPatient();// Call the register method
                break;
            case 2:
                admit(); // Call the admit method
                break;
            case 3:
                lineup(); // Call the lineup method
                break;
            default:
                break;
            }
        }
    }
}
