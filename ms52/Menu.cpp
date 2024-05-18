/*/////////////////////////////////////////////////////////////////////////
                         OOP244 Ms52:
Full Name  : Shabanova Naiba
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024.04.07
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

namespace seneca {
    bool Menu::isValid(int menuChoice) const
    {
        return menuChoice >= 0 && menuChoice <= m_noOfSel;
    }

    Menu::Menu(const char* text)
    {
        this->menuOptions(text);
        this->setNoOfSelections(2);
    }
    
Menu::Menu(const char* text, int NoOfSelections) {
        // Allocate memory for m_text and copy the input text
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);

        m_noOfSel = NoOfSelections;
    }

    void Menu::menuOptions(const char* text)
    {
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);
    }

    void Menu::setNoOfSelections(int numOfSel)
    {
        m_noOfSel = numOfSel;
    }

    Menu::~Menu()
    {
        delete[] m_text;
    }

std::ostream& Menu::display(std::ostream& ostr) const {
    // Determine if this is the lineup menu based on the content of m_text
    bool isLineupMenu = std::strstr(m_text, "Select The Lineup:") != nullptr;

    // Use a string stream to process each line of the menu text
    std::istringstream iss(m_text);
    std::string line;
    while (std::getline(iss, line)) {
        // Add indentation if this is the lineup menu
        if (isLineupMenu) {
            ostr << "   "; // Add three spaces
        }
        ostr << line << "\n";
    }
    
    // If this is the lineup menu, add the exit option and prompt with indentation
    if (isLineupMenu) {
        ostr << "   0- Exit\n";
        ostr << "   > ";
    } else {
        // For the main menu, print the exit option and prompt without indentation
        ostr << "0- Exit\n";
        ostr << "> ";
    }

    return ostr;
}





    int Menu::userMenuChoice() const
    {
        bool validEntry = true;
        int selection = 1000;
        do {
 
            std::cin >> selection;
            if (std::cin.fail() )
            {
                std::cin.clear();
                std::cin.ignore(5000, '\n');
                std::cout << "Bad integer value, try again: ";
                validEntry = false;
            }
            else
                if ( std::cin.peek() == ' ')
                {
                    std::cin.clear();
                    std::cin.ignore(5000, '\n');
                    std::cout << "Only enter an integer, try again: ";
                    validEntry = false;
                }
                else{
                if (!isValid(selection))
                {
                    std::cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
                    validEntry = false;
                }
                else
                {
                    validEntry = true;
                }
            }
        } while (!validEntry);
        return selection;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        Selection = userMenuChoice();
        return Selection;
    }
}
