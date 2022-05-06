/* Citation and Sources...
Final Project Milestone 1
Module: Time (class)
Filename: Time.h
Version: 1.0
Author:	Kathleen Monks
Revision History
-----------------------------------------------------------
Date         Reason
2021/Jun/27  Preliminary release
2021/Jul/06  Debugged
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
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
namespace sdds {
   class Time {
      // Data Members
      // ============
      unsigned int m_min;
   public:
      // Member Functions
      // ================
      Time& setToNow();
      // ========================
      Time(unsigned int min = 0);
      // ========================
      std::ostream& write(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);

      Time& operator-=(const Time& D);
      Time operator-(const Time& D)const;
      Time& operator+=(const Time& D);
      Time operator+(const Time& D)const;

      Time& operator=(unsigned int val);
      Time& operator *= (unsigned int val);
      Time& operator /= (unsigned int val);
      Time operator *(unsigned int val)const;
      Time operator /(unsigned int val)const;

      operator unsigned int()const;
      operator int()const;

   };

   // Insertion Extraction Helpers
   // ============================
   std::ostream& operator<<(std::ostream& ostr, const Time& D);
   std::istream& operator>>(std::istream& istr, Time& D);

   // Conversion Clock Helpers:
   // =========================
   int getHourClock(const int totMins);
   int getMinClock(const int totMins); 
   int getTotMinsFromClock(const int mins, const int hour); 
}

#endif // !SDDS_TIME_H

