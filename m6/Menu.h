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

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
	class Menu {
		char* m_text{};
		int m_numOptions{};
		int m_numIndentationTabls{};
		int selectedOption{};
	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		virtual ~Menu();
		void display() const;
		int& operator>>(int& Selection);
	};
}
#endif