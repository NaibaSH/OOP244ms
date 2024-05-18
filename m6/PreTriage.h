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

#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Patient.h"
#include "Time.h"
namespace seneca {
	class PreTriage
	{
		// Keep track of the average wait time of the Contaigen test (TestPatient.cpp) and Triage Patient (TriagePatient.cpp)
		Time m_ContagionWaitTime{};
		Time m_TriageWaitTime{};
		Patient* m_lineup[100] = { nullptr }; // Holds the actual number of patients in the lineup.
		char m_dataFilename[256]{};
		int m_numPatients{};

		// Private member functions
		// Queries

		/// <summary>
		/// Receives a constant Patient Reference and returns the total estimated wait time 
		/// for that type of Patient (contagion or Triage) as follows:
		/// 1. Finds the number of Patients in the lineup that match the type of the received Patient Reference.
		/// 2. Returns the product of estimated wait time(for that type of patient) to the number of patients found.
		/// </summary>
		/// <param name="patient"></param>
		/// <returns></returns>
		Time getWaitTime(const Patient& patient)const; 

		/// <summary>
		/// Receives a character representing the type of patient (C for Contaigen, T for Triage).
		/// Finds the index of the first patient in line that matches a specified type.
		/// </summary>
		/// <param name="type"></param>
		/// <returns></returns>
		int indexOfFirstInLine(char type) const;

		/// <summary>
		/// Saving the data into the file before deleting it from the memory
		/// </summary>
		void save() const;

		/// <summary>
		/// Prints a report on patients currently in the lineup.
		/// </summary>
		void lineup() const;

		// Modifiers

		/// <summary>
		/// Receives the reference of the admitting patient and adjusts the average wait time 
		/// of that type of patient based on the admittance time of the patient.
		/// Formula to be USED:
		/// CT: Current Time
	    /// PTT: Patient's Ticket Time
		/// AWT : Average Wait Time(Contagion or Triage)
		/// PTN : Patient's Ticket Number
		/// AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
		/// </summary>
		/// <param name="patient"></param>
		void setAverageWaitTime(Patient& patient); 

		/// <summary>
		/// Loads the average wait times and the patient records from the data file and stores them in the lineup array of pointers.
		/// </summary>
		void load();

		/// <summary>
		/// Registers a new patient.
		/// </summary>
		void registerPatient();

		/// <summary>
		/// Calls the next patient in line to be admitted to the contagion test centre or Triage centre.
		/// </summary>
		void admit();

	public:
		/// <summary>
		/// 1 Argument Constructor
		/// Used to initialize the 'm_dataFilename' data member for load and save purposes, 
		/// initializes the average wait time to 15 and 5 default values respectively for Contagion and Triage Patient
		/// and loads all the data to the file
		/// </summary>
		/// <param name="dataFilename">File name</param>
		PreTriage(const char* fileName);
		
		/// <summary>
		/// Destructor
		/// 1. Saves the data
		/// 2. Iterates through the patient lineup and deletes the elements one by one.
		/// 3. If there are any other dynamically allocated memory, it will delete them as well.
		/// </summary>
		virtual ~PreTriage();

		/// <summary>
		/// Runs the PreTriage main application.
		/// </summary>
		void run();
	};
}
#endif