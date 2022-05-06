/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "Ticket.h"
#include "IOAble.h"
namespace sdds
{
	class Patient:public IOAble
	{
	private:
		// Data Members
		// ============
		const char* m_name;
		int m_ohipNo;
		Ticket m_lineTicket;
		bool m_processing = true;
		void setEmpty(); // kathleen's prototype

	public:
		// ================================================
		Patient(int ticketNo = 0, bool processing = false);
		~Patient();
		Patient(const Patient&) = delete;
		// ==============================

		// Member Functions
		// ================
		void operator=(const Patient&) = delete; // prevent assigns
		virtual char type()const = 0; 
		bool fileIO()const;
		void fileIO(bool processing);
		bool operator==(const char ch)const;
		bool operator==(const Patient& arg)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

		// Class Constraints
		// ===========================
		const int ohipMin = 100000000;  // 9 digits
		const int ohipMax = 999999999;
		const char delim = ','; // csv file
		const char nameWriteMax = 25; // for display

	};

}
#endif // !SDDS_PATIENT_H_
