/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Kathleen Monks
Revision History
-----------------------------------------------------------
Date         Reason
2021/Jun/27  Preliminary release
2021/Jul/24  Debugged
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

#include "TriagePatient.h"
#include "utils.h"

namespace sdds
{
	// Global Var
	// ==========
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient(): Patient(nextTriageTicket, true)
	{
	m_symptomList = nullptr;
	nextTriageTicket++;
	}
	
	TriagePatient::~TriagePatient()
	{
		delete[] m_symptomList;
		m_symptomList = nullptr;
	}

	char TriagePatient::type()const
	{
		return triageType;	
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const
	{
		Patient::csvWrite(ostr);
		ostr << delim;
		ostr << m_symptomList;
		return ostr;
	}


	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextTriageTicket = number() + 1;
		istr.ignore(2000, delim);
		delete[] m_symptomList;
		m_symptomList = getcstr(nullptr, istr, '\n');
		
		return istr;
	}
	


	std::ostream& TriagePatient::write(std::ostream& ostr)const
	{
		if(fileIO() == true)
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << std::endl;
			Patient::write(ostr);
			ostr << std::endl;
			ostr << "Symptoms: " << m_symptomList << std::endl;
		}

		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_symptomList;
			Patient::read(istr);
			std::cout << "Symptoms: ";
			m_symptomList = getcstr(nullptr, istr, '\n');
		}

		return istr;
	}

}
