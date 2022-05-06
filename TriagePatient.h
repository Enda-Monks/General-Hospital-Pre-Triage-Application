/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
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
#ifndef SDDS_TRIAGEPATIENT_H_
#define SDDS_TRIAGEPATIENT_H_
#include "Patient.h"
namespace sdds
{

	class TriagePatient: public Patient
	{
	private:
		// Data Members
		// ============
		const char* m_symptomList;
		
	public:
		// ===========
		TriagePatient(); 
		~TriagePatient();
		// ============

		// Member Functions
		// ================
		char type()const; 
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream & ostr)const;
		std::istream& read(std::istream & istr);
		
		// Class Constraints
		// =================
		char triageType = 'T';
		const char delim = ',';
	};
}
#endif // !SDDS_TRIAGEPATIENT_H_

