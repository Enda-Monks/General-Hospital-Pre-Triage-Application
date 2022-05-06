/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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

#include "CovidPatient.h"
#include "utils.h"

namespace sdds
{
	// Global Variable
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient(): Patient(nextCovidTicket, true)
	{
		nextCovidTicket++;
	}

	char CovidPatient::type()const
	{
		return covidType; 
	}

	std::istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr); 
		nextCovidTicket = number() + 1; 
		istr.ignore(2000, '\n'); 
		return istr;
	}

	std::ostream& CovidPatient::write(std::ostream& ostr)const
	{
		if (fileIO() == true)
		{
			Patient:: csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << std::endl;
			Patient::write(ostr);
			ostr << std::endl;
		}
		return ostr;
	}


	std::istream& CovidPatient::read(std::istream& istr)
	{
		if (fileIO() == true)
		{
			csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}

		return istr;
	}
	
}