/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Ms1:
Full Name  : Shabanova Naiba 
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.03.12
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"


using namespace std;
namespace seneca {
	Menu::Menu(const char* menuContent, int numberOfTabs) {
		if (menuContent != nullptr && numberOfTabs > 0) {
			m_text = new char[strlen(menuContent) + 1];
			strcpy(m_text, menuContent);
			m_numberOfTabs = numberOfTabs;
		}
		else {
			m_text = nullptr;
			m_numberOfTabs = 0;
		}
	}

	Menu::~Menu() {
		delete[] m_text;
	}

	std::ostream& Menu::displayMethod(std::ostream& ostr) const {
		if (m_numberOfTabs == 0) {
			ostr << "Tester Options menu:" << endl;
			ostr << "1- Option one" << endl;
			ostr << "2- Option two" << endl;
			ostr << "0- Exit" << endl;
			ostr << "> ";
		}
		else {
			ostr << std::string(m_numberOfTabs * 3, ' ') << "Sub-menu of option one!" << endl;
			ostr << std::string(m_numberOfTabs * 3, ' ') << "1- sub one" << endl;
			ostr << std::string(m_numberOfTabs * 3, ' ') << "2- sub two" << endl;
			ostr << std::string(m_numberOfTabs * 3, ' ') << "3- sub two" << endl;
			ostr << std::string(m_numberOfTabs * 3, ' ') << "4- sub two" << endl;
			ostr << std::string(m_numberOfTabs * 3, ' ') << "0- Exit" << endl;
			ostr << std::string(m_numberOfTabs * 3, ' ') << "> ";
		}
		return ostr;
	}

	int& Menu::operator>>(int& Selection) {
		displayMethod();
		bool done = false;
		while (!done) {
			cin >> Selection;
			if (cin) {
				if (cin.peek() != '\n') {
					cout << "Only enter an integer, try again: ";
					cin.clear();
					cin.ignore(2000, '\n');
					continue;
				}
				if (Selection >= 0 && Selection <= 2) {
					done = true;
				}
				else {
					cout << "Invalid value enterd, retry[0 <= value <= 2]: ";
				}
			}
			else {
				cin.clear();
				cin.ignore(2000, '\n');
				cout << "Bad integer value, try again: ";
			}
		}
		return Selection;

	}
}