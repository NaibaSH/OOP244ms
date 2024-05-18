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
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	Menu::Menu(const char* menuContent, int numberOfTabs)
	{
		int counter{};
		if (menuContent) {
			delete[] m_text;
			m_text = new char[strlen(menuContent) + 1];
			strcpy(m_text, menuContent);

			for (size_t i = 0; i < strlen(m_text); i++) {
				if (m_text[i] == '\n') {
					counter++;
				}
			}

			m_numOptions = counter;
		}
		if (numberOfTabs) m_numIndentationTabls = numberOfTabs;
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	void Menu::display() const
	{
		if (m_numIndentationTabls > 0) {
			for (size_t i = 0; i < strlen(m_text); i++) {	
				if (i == 0) {
					for (int i = 0; i < m_numIndentationTabls; i++) {
						cout << "   ";
					}
					cout << m_text[i];
				}
				else if (m_text[i] == '\n') {
					cout << "\n";
					for (int i = 0; i < m_numIndentationTabls; i++) {
						cout << "   ";
					}
				}
				else {
					cout << m_text[i];
				}
			}
			cout << "\n";
			for (int i = 0; i < m_numIndentationTabls; i++) {
				cout << "   ";
			}
			cout << "0- Exit" << endl;
			for (int i = 0; i < m_numIndentationTabls; i++) {
				cout << "   ";
			}
			cout << "> ";
		}
		else {
			cout << m_text << endl;
			cout << "0- Exit\n> ";
		}
	}

	int& Menu::operator>>(int& Selection)
	{
		int val{};
		display();
		val =  U.getInt(m_numOptions);
		Selection = val;
		return Selection;
	}
}