/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
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

#include "IOAble.h"
#include "utils.h"
#include "Time.h" 

using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const IOAble& interf)
	{
		interf.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, IOAble& interf)
	{
		interf.read(istr);
		return istr;
	}

}
