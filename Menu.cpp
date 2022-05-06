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
#include <iostream>

#include "Menu.h"
#include "utils.h"
#include "Time.h"
#include "IOAble.h"

using namespace std;
namespace sdds
{
	const char* exitText = "0- Exit";
	
	void Menu::display()const
	{

		//header and sels
		cout << m_text; 
		cout << endl;

		//exit sel
		cout << exitText;
		cout << endl;
	}

	void Menu::setEmpty()
	{
		m_text = nullptr; 
		m_noOfSel = 0;
	}

	void Menu::setContent(const char* content)
	{
		delete[] m_text;
		m_text = new char[strLen(content) + 1];
		strCpy(m_text, content);
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		setEmpty();

		if (isValidCString(MenuContent) && NoOfSelections > 0)
		{
			setContent(MenuContent);
			m_noOfSel = NoOfSelections;
		}
		else
		{
			cout << "Invalid Attempt to Construct Menu Object" << endl;
		}
	}
	Menu::~Menu()
	{
		delete[] m_text; 
		m_text = nullptr;
	}

	Menu::Menu(const Menu& copy)
	{
		setEmpty();

		if (isValidCString(copy.m_text) && copy.m_noOfSel > 0)
		{
			setContent(copy.m_text);
			m_noOfSel = copy.m_noOfSel;
		}
		else
		{
			cout << "Invalid Attempt to Construct Menu Copy" << endl;
		}
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);

		return Selection;
	}
}
