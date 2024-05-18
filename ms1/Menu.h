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
#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_
#include <iostream>
namespace seneca {
    class Menu {
        char* m_text;
        int m_numberOfOption;
        int m_numberOfTabs;

    public:
        Menu(const char* menuContent, int numberOfTabs = 0);
        ~Menu();
        Menu& operator=(const Menu&) = delete;
        Menu(const Menu&) = delete;
        std::ostream& displayMethod(std::ostream& ostr = std::cout) const;
        int& operator>>(int& Selection);
    };
}
#endif 



