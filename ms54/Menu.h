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



#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>

namespace seneca {
    class Menu {
        char* m_text;
        int m_noOfSel;  // Add the declaration of m_noOfSel here

        bool isValid(int menuChoice) const;

    public:
        Menu(const char* text);
        Menu(const char* text, int NoOfSelections);
        ~Menu();  // Destructor

        // Rule of Three (or Five) - Copy operations
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);

        // Rule of Three (or Five) - Move operations
        Menu(Menu&& other) noexcept;
        Menu& operator=(Menu&& other) noexcept;

        std::ostream& display(std::ostream& ostr = std::cout) const;
        int& operator>>(int& selection);
        void menuOptions(const char* text);
        int userMenuChoice() const;
        void setNoOfSelections(int numOfSel);
    };
} // namespace seneca

#endif // SENECA_MENU_H_
