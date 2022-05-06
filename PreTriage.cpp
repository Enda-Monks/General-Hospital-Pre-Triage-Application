/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Kathleen Monks
Revision History
-----------------------------------------------------------
Date         Reason
2021/Jun/27  Preliminary release
2021/Aug/02  Debugged
2021/Aug/03  Finalized
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
#include <fstream>
#include <string>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "Patient.h"

namespace sdds
{
	// Default Initializers
	// ====================
	const char* appMenu = "General Hospital Pre-Triage Application\n1- Register\n2- Admit";
	const int appNo = 2;
	const char* pMenu = "Select Type of Admittance:\n1- Covid Test\n2- Triage";
	const int pNo = 2;
	const int covidWait = 15;
	const int triageWait = 5;

	bool PreTriage::setFilename(const char* fname)
	{
		bool success = true;


		if (isValidFilename(fname)) // utils function
		{

			m_dataFilename = new char[strLen(fname) + 1];
			m_dataFilename[0] = '\0';
			strCpy(m_dataFilename, fname);

		}
		else
		{
			std::cout << "invalid file name, could not load" << std::endl;
			success = false;
		}

		return success;
	}

	void PreTriage::setLineupSize()
	{
		std::ifstream ifstr;

		ifstr.open(m_dataFilename);
		while (ifstr)
		{
			if (ifstr.get() == '\n')
			{
				m_lineupSize++;
			}
		}
		if (m_lineupSize > 0)
		{
			m_lineupSize--; // accounts for first line of unrelated data

		}
	}

	void PreTriage::saveFile(const char* fname)const
	{
		std::ofstream ofstr;
		int i;
		ofstr.open(fname);
		if (ofstr.is_open())
		{
			// to file
			ofstr << m_averCovidWait << delim << m_averTriageWait << std::endl;

			// to console
			std::cout << "Saving Average Wait Times," << std::endl;
			std::cout << "   COVID Test: " << m_averCovidWait << std::endl;
			std::cout << "   Triage: " << m_averTriageWait << std::endl;

			if (m_lineupSize > 0)
			{
				std::cout << "Saving m_lineup..." << std::endl;

				for (i = 0; i < m_lineupSize; i++)
				{
					// to file
					m_lineup[i]->csvWrite(ofstr);
					ofstr << std::endl;

					// to console
					std::cout << i + 1 << "- ";
					m_lineup[i]->csvWrite(std::cout);
					std::cout << std::endl;
				}
			}
			
		}
	}

	PreTriage::PreTriage(const char* dataFilename) : m_appMenu(appMenu, appNo), m_pMenu(pMenu, pNo)
	{
		m_averCovidWait = covidWait;
		m_averTriageWait = triageWait;

		if (setFilename(dataFilename))
		{

			setLineupSize(); // m_lineupSize
			load(); // reads from file to the m_lineup[] Patient array
			std::cout << std::endl;

		}
	}

	PreTriage::~PreTriage()
	{
		int i;
		
		saveFile(m_dataFilename);

		for (i = 0; i < m_lineupSize; i++)
		{

			delete m_lineup[i];
		}

		delete[]  m_dataFilename;


		std::cout << "done!" << std::endl;
	}

	void PreTriage::run(void)
	{
		bool exit = false;
		int sel;
		do
		{
			switch (m_appMenu >> sel)
			{

			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			case 0:
				exit = true;
				break;

			}

		} while (!exit);
	}

	void PreTriage::reg()
	{
		int sel = 0;
		bool exit = false;

		if (m_lineupSize == maxNoOfPatients)
		{

			std::cout << "Line up full!" << std::endl;

		}
		else
		{
			switch (m_pMenu >> sel) 
			{ 

			case 1:
				m_lineup[m_lineupSize] = new CovidPatient; // instantiate a Covid Patient
				break;
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient; // instantiate a Triage Patient
				break;
			case 0:
				exit = true;
				break;

			}

			if (!exit)
			{
				m_lineup[m_lineupSize]->setArrivalTime();
				std::cout << "Please enter patient information: " << std::endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(std::cin); 
				std::cout << std::endl;
				std::cout << "******************************************" << std::endl;
				m_lineup[m_lineupSize]->write(std::cout); 
				std::cout << "Estimated Wait Time: ";
				std::cout << getWaitTime(*m_lineup[m_lineupSize]) << std::endl;
				std::cout << "******************************************" << std::endl;
				std::cout << std::endl;
				m_lineupSize++;
			}
		}
	}
	void PreTriage::admit()
	{
		char type = '\0';
		int sel, first = -1;

		switch (m_pMenu >> sel) 
		{

		case 1:
			type = covidType;
			break;
		case 2:
			type = triageType;
			break;
		case 0:
			break;

		}

		if (type)
		{
			first = indexOfFirstInLine(type);
		}

		if (first >= 0)
		{
			std::cout << std::endl;
			std::cout << "******************************************" << std::endl;
			m_lineup[first]->fileIO(false);
			std::cout << "Calling for ";
			m_lineup[first]->write(std::cout);
			std::cout << "******************************************" << std::endl;
			std::cout << std::endl;
			setAverageWaitTime(*m_lineup[first]);
			removePatientFromLineup(first);
		}
	}
	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		int counter = 0, i;
		Time result = 0;

		for (i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
			{
				counter++;
			}
		}

		result += counter;
		
		if (m_lineup[i]->type() == covidType)
		{
			result *= m_averCovidWait;
		}
		else if (m_lineup[i]->type() == triageType)
		{
			result *= m_averTriageWait;
		}

		return result;
	}
	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == covidType)
		{
			m_averCovidWait =   ((getTime() - (int)(Time)p) + 
								((int)m_averCovidWait * (p.number() - 1))) / p.number();
		}
		else if (p.type() == triageType)
		{
			m_averTriageWait =  ((getTime() - (int)(Time)p) + 
								((int)m_averCovidWait * (p.number() - 1))) / p.number();
		}
	}
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize); // utils template

	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int i, indexFound = -1;

		for (i = 0; i < m_lineupSize && indexFound == -1; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				indexFound = i;
			}
		}

		return indexFound;
	}
	void PreTriage::load()
	{
		std::ifstream ifstr;
		std::string cstr;
		char type = '\0';
		Patient* pTemp = nullptr;
		int i;

		std::cout << "Loading data..." << std::endl;

		if (m_lineupSize > maxNoOfPatients)
		{

			std::cout << "Warning: number of records exceeded " << maxNoOfPatients << std::endl;
			m_lineupSize = maxNoOfPatients;
		}
		else if (m_lineupSize < 1)
		{

			std::cout << "No data or bad data file!" << std::endl;

		}

		if(m_lineupSize <= maxNoOfPatients) // inclusive of case "# of records exceeded"
		{

			ifstr.open(m_dataFilename);

			ifstr >> m_averCovidWait;
			ifstr.ignore(2000, delim);
			ifstr >> m_averTriageWait;
			ifstr.ignore(2000, '\n');

			for (i = 0; i < m_lineupSize; i++)
			{

				ifstr >> type;
				ifstr.ignore(2000, delim);

				if (type == covidType)
				{
					pTemp = new CovidPatient; // instantiate a Covid Patient
				}
				else if (type == triageType)
				{
					pTemp = new TriagePatient; // instantiate a Triage Patient
				}

				if (pTemp != nullptr)
				{
					pTemp->fileIO(true);
					pTemp->read(ifstr);
					pTemp->fileIO(false);
					m_lineup[i] = pTemp;
					type = '\0';
				}
			}

			if (m_lineupSize > 0)
			{
				std::cout << m_lineupSize << " Records imported..." << std::endl;
			}
		}

	}
}