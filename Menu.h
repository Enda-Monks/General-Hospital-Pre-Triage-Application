/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Kathleen Monks
Revision History
-----------------------------------------------------------
Date         Reason
2021/Jun/27  Preliminary release
2021/Jul/11  Debugged
2021/Aug/02  Finalized
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds
{
	class Menu
	{
        // Data Members
        // ============
        char* m_text; 
        int m_noOfSel; 

        // Member Functions
        // ================
        void display()const;
        void setEmpty();  
        void setContent(const char* content);  
    public:
        // ===============================================
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        // =============
        int& operator>>(int& Selection);
        Menu(const Menu& copy);   // safe copies
        void operator=(const Menu&) = delete; // prevent object assign
	};
}
#endif // !SDDS_MENU_H_

