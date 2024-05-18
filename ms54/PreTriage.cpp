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


#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"

using namespace std;

namespace seneca {
	PreTriage::PreTriage(const char* dataFileName) {
		m_dataFileName = new char[U.strlen(dataFileName) + 1];
		U.strcpy(m_dataFileName, dataFileName);
		m_avgContaigenWaitTime = 15;
		m_avgTriageWaitTime = 5;
		m_numOfPatients = 0;
		for (int i = 0; i < m_numOfPatients; i++) {
			patientLineup[i] = nullptr;
		}
		load();
	}

	PreTriage::~PreTriage() {
		save();

		for (int i = 0; i < m_numOfPatients; i++) {
			delete patientLineup[i];
		}

		delete[] m_dataFileName;
	}

	const Time PreTriage::getWaitTime(const Patient& P) const {
		int numOfMatchedPatient = 0;
		Time waitTime;
		for (int i = 0; i < m_numOfPatients; i++) {
			if (patientLineup[i] != nullptr && patientLineup[i]->type() == P.type()) {
				numOfMatchedPatient++;
			}
		}

		if (P.type() == 'C') {
			waitTime = m_avgContaigenWaitTime * numOfMatchedPatient;
		}
		else if (P.type() == 'T') {
			waitTime = m_avgTriageWaitTime * numOfMatchedPatient;
		}
		return waitTime;
	}

	void PreTriage::setAverageWaitTime(const Patient& P) {
		// Get patient information
		int PTN = P.number();
		Time CT = U.getTime();
		Time PTT = P.time();
		Time AWT;

		// Update average wait time based on patient type
		if (P.type() == 'C') {
			AWT = m_avgContaigenWaitTime;
			m_avgContaigenWaitTime = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		}
		else if (P.type() == 'T') {
			AWT = m_avgTriageWaitTime;
			m_avgTriageWaitTime = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		}
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		int index = -1;
		for (int i = 0; i < m_numOfPatients && index == -1; i++) {
			if (patientLineup[i]->type() == type) {
				index = i;
			}
		}
		return index;
	}

	void PreTriage::load() {
		ifstream dataFile(m_dataFileName);
		if (!dataFile) {
			cout << "Loading data...\nNo data or bad data file!\n\n";
			return;
		}

		std::cout << "Loading data...\n";

		// Read average wait times
		m_avgContaigenWaitTime.read(dataFile);
		dataFile.ignore();
		m_avgTriageWaitTime.read(dataFile);
		dataFile.ignore();

		// Read patient records
		char type;
		Patient* patient = nullptr;

		for (m_numOfPatients = 0; m_numOfPatients < maxPatients && dataFile >> type; m_numOfPatients++) {
			dataFile.ignore();

			if (type == 'C') {
				patient = new TestPatient();
			}
			else if (type == 'T') {
				patient = new TriagePatient();
			}

			if (patient) {
				patient->read(dataFile);
				patientLineup[m_numOfPatients] = patient;
			}
		}

		if (!dataFile.eof()) {
			cout << "Warning: number of records exceeded " << maxPatients << endl;
		}

		if (m_numOfPatients == 0) {
			cout << "No data or bad data file!" << endl << endl;
		}
		else {
			cout << m_numOfPatients << " Records imported..." << endl << endl;
		}
	}


	void PreTriage::save() {
		ofstream dataFile(m_dataFileName);
		int C_patient = 0, T_patient = 0;

		cout << "Saving lineup..." << endl;

		if (dataFile.is_open()) {
			dataFile << m_avgContaigenWaitTime;
			dataFile << ",";
			dataFile << m_avgTriageWaitTime;
			dataFile << endl;

			// Save the patient lineup
			for (int i = 0; i < m_numOfPatients; i++) {
				dataFile << *patientLineup[i] << endl;
				if (patientLineup[i]->type() == 'C') {
					C_patient++;
				}
				else if (patientLineup[i]->type() == 'T') {
					T_patient++;
				}
			}

			cout << C_patient << " Contagion Tests and " << T_patient << " Triage records were saved!" << endl;
			dataFile.close();
		}
	}

	void PreTriage::regPatient() {
		if (m_numOfPatients >= maxPatients) {
			cout << "Line up full!" << endl;
			return;
		}
		int selection = -1;
		Menu registerMenu("Select Type of Registration:\n1- Contagion Test\n2- Triage\n0- Exit\n> ", 1);
		registerMenu >> selection;

		switch (selection) {
		case 1:
			patientLineup[m_numOfPatients] = new TestPatient();
			break;
		case 2:
			patientLineup[m_numOfPatients] = new TriagePatient();
			break;
		case 0:
			break;
		default:
			break;
		}

		patientLineup[m_numOfPatients]->setArrivalTime();
		cout << "Please enter patient information: " << endl;
		patientLineup[m_numOfPatients]->read(cin);

		cout << endl << "******************************************" << endl;
		patientLineup[m_numOfPatients]->write(cout);
		cout << "Estimated Wait Time: " << getWaitTime(*patientLineup[m_numOfPatients]) << endl;
		cout << "******************************************" << endl << endl;

		m_numOfPatients++;
	}

	void PreTriage::admit() {
        Menu admitMenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage\n", 2);
		int selection = -1;
		admitMenu >> selection;
		char type = '\0';
		switch (selection) {
		case 1:
			type = 'C';
			break;
		case 2:
			type = 'T';
			break;
		case 0:
			break;
		default:
			break;
		}
		int index = indexOfFirstInLine(type);
		if (index == -1) {
			cout << "Lineup is empty!\n";
		}
		else {
			cout << endl << "******************************************" << endl;
			cout << "Call time: [" << Time(U.getTime()) << "]" << endl;
			cout << "Calling at for ";
			cout << *patientLineup[index];
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*patientLineup[index]);
			removeDynamicElement(patientLineup, index, m_numOfPatients);
		}
	}

	void PreTriage::lineup() {
        Menu lineupMenu("Select The Lineup:\n1- Contagion Test\n2- Triage\n", 2);
          int selection = -1;
          char type = '\0';

          lineupMenu >> selection; // This calls Menu::display which appends "0- Exit" and the prompt
          switch (selection) {
              case 1:
                  type = 'C';
                  break;
              case 2:
                  type = 'T';
                  break;
              default:
                  break;
          }

		int count = 0;
		for (int i = 0; i < m_numOfPatients; i++) {
			if (patientLineup[i]->type() == type) {
				count++;
			}
		}

		if (count == 0) {
			cout << "Line up is empty!" << endl;
		}
		else {
			cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;

			bool patientsFound = false; // Flag to track if any patients of the selected type are found
			int rowNumber = 1;

			for (int i = 0; i < m_numOfPatients; i++) {
				if (patientLineup[i]->type() == type) {
					clog.setf(ios::left); 
					clog.width(4); 
					clog.fill(' '); 
					clog << rowNumber;
					clog << "-";
					clog.unsetf(ios::left);
					clog << " ";
					patientsFound = true;
					patientLineup[i]->write(clog); // Call the write method
					clog << endl;
					rowNumber++;
				}
			}

			if (!patientsFound) {
				cout << "Line up is empty!" << endl;
			}

			cout << "-------------------------------------------------------------------------------" << endl;
		}
	}



void PreTriage::run() {
    int selection = -1;
    // Make sure there is no duplicate menu text here.
    Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup\n", 3);

    do {
        mainMenu >> selection;  // This should call the display method once

        switch (selection) {
        case 1:
            regPatient();
            break;
        case 2:
            admit();
            break;
        case 3:
            lineup();
            break;
        case 0:
            // Properly handle the exit.
            break;
        default:
            // Handle invalid input.
            break;
        }
    } while (selection != 0);
}

}
