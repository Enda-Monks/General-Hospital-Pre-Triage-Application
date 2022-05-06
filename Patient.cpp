/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
Version 1.0
Author	Kathleen Monks
Revision History
-----------------------------------------------------------
Date         Reason
2021/Jun/27  Preliminary release
2021/Jul/19  Debugged
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
#include "Patient.h"
#include "utils.h"
namespace sdds
{
	void Patient::setEmpty()
	{
		m_name = nullptr;
		m_ohipNo = 0;
	}

	Patient::Patient(int ticketNo, bool processing): m_lineTicket(ticketNo)
	{
		setEmpty();
		m_processing = processing;
	}
	Patient::~Patient()
	{
		delete[] m_name,
		m_name = nullptr;
	}
	bool Patient::fileIO()const
	{
		return m_processing;
	}
	void Patient::fileIO(bool processing)
	{
		m_processing = processing;
	}
	bool Patient::operator==(const char ch)const
	{
		bool result = false;
		if (ch == this->type())
		{
			result = true;
		}
		return result;
	}

	bool Patient::operator==(const Patient& arg)const
	{
		bool result = false;

		if (arg.type() == type())
		{
			result = true;
		}
		return result;
	}
	void  Patient::setArrivalTime()
	{
		m_lineTicket.resetTime();
	}
	Patient::operator Time()const
	{
		return (Time)m_lineTicket;
	}
	int Patient::number()const
	{
		return m_lineTicket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr)const
	{

		ostr << type() << delim;
		ostr << m_name << delim;
		ostr << m_ohipNo << delim;

		m_lineTicket.csvWrite(ostr);

		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr)
	{
		delete[] m_name;
		m_name = getcstr(nullptr, istr, delim); 
		
		istr >> m_ohipNo;
		istr.ignore(2000, delim);
		
		m_lineTicket.csvRead(istr);
		
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const 
	{
		int i = 0;
		ostr << "Ticket No: " << number(); // returns ticketNo

		ostr << ", Issued at: " << (Time)m_lineTicket << std::endl; // returns ticketTime

		for (i = 0; i < nameWriteMax && i < strLen(m_name); i++) // ensures output cuttoff at 25 chars
		{
			ostr << m_name[i];
		}
		ostr << ", OHIP: " << m_ohipNo;

		return ostr;
	}
	std::istream& Patient::read(std::istream& istr)
	{
		delete[] m_name;
		m_name = getcstr("Name: ", istr, '\n');
		m_ohipNo = getInt(ohipMin, ohipMax, "OHIP: ", "Invalid OHIP Number, ", true);
		return istr;
	}

}