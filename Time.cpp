/* Citation and Sources...
Final Project Milestone 1
Module: Time (class)
Filename: Time.cpp
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
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{

    // Classic Time Constraints
    // ========================
    const int hoursPerDay = 24;
    const int minsPerHour = 60;
    const char clockDelimiter = ':';

    
    Time& Time::setToNow()
    {
        
        this->m_min = getTime(); 

        return *this;
    }

    // Constructor
    Time::Time(unsigned int min)
    {
        this->m_min = 0; // set to empty;

        if (min > 0) // if valid arg
        {
            this->m_min = min; //set to arg
        }
    }


    std::ostream& Time::write(std::ostream& ostr) const
    {
        // display HH:MM format
        ostr.setf(ios::right); 
        ostr.width(2);
        ostr.fill('0');
        ostr << getHourClock(this->m_min) << clockDelimiter;

        ostr.width(2);
        ostr.fill('0'); 
        ostr << getMinClock(this->m_min);
        ostr.unsetf(ios::left);

        return ostr; 
    }

    std::istream& Time::read(std::istream& istr)
    {
        int hourClock = 0, minClock = 0;
        char delimiter = 'x'; // dummy value

        istr >> hourClock;
        istr >> delimiter;
        istr >> minClock;
      
        if (isPositiveIntOrZero(hourClock) == false ||
            delimiter != clockDelimiter ||
            isPositiveIntOrZero(minClock) == false)
        {
            istr.setstate(ios::failbit);
        }
        else
            this->m_min = getTotMinsFromClock(minClock, hourClock); // set current object to valid input in mins
        
        return istr;
    }

    // Binary Operators:
    Time& Time::operator-=(const Time& D)
    {

        int diffHour;
        int diffMin;

        // calc diff between currentTime and arg
        diffHour = getHourClock(this->m_min) - getHourClock(D.m_min); // convert to HH:MM format
        diffMin = getMinClock(this->m_min) - getMinClock(D.m_min);

        while (isPositiveIntOrZero(diffHour) == false)
        {
            diffHour += hoursPerDay; // to account for clock turning backwards
        }
        

        while (isPositiveIntOrZero(diffMin) == false)
        {
            diffMin += minsPerHour;
        }

        this ->m_min = getTotMinsFromClock(diffMin, diffHour);  // convert back to total mins

        return *this;

    }
    Time Time::operator-(const Time& D)const
    {
        
        Time result;

        int diffHour;
        int diffMin;


        diffHour = getHourClock(this->m_min) - getHourClock(D.m_min); // convert to HH:MM format
        diffMin = getMinClock(this->m_min) - getMinClock(D.m_min);

        while (isPositiveIntOrZero(diffHour) == false)
        {
            diffHour += hoursPerDay; // to account for clock turning backwards
        }


        while (isPositiveIntOrZero(diffMin) == false)
        {
            diffMin += minsPerHour;
        }

        result.m_min = getTotMinsFromClock(diffMin, diffHour); // convert back to total mins

        return result;
    }
    Time& Time::operator+=(const Time& D)
    {
        this->m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const
    {
        Time result;

        result.m_min = this->m_min + D.m_min;

        return result;
    }

    Time& Time::operator=(unsigned int val)
    {
        this->m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val)
    {
        this->m_min *= val;
        return *this;
    }
    Time& Time::operator /= (unsigned int val)
    {
        this->m_min /= val;

        return *this;
    }
    Time Time::operator *(unsigned int val)const
    {
        Time result;

        result.m_min = this->m_min * val;

        return result;
    }
    Time Time::operator /(unsigned int val)const
    {
        Time result;

        result.m_min = this->m_min / val;

        return result;
    }

    // Type Conversion Operators:
    Time::operator unsigned int()const
    {
        return m_min;
    }
    Time::operator int()const
    {
        unsigned int result;

        if (isPositiveIntOrZero(this->m_min))
        {
            result = this->m_min;
        }
        else
        {
            result = 0;
        }

        return result;
    }

    // Binary Helper Operators:
    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
       D.write(ostr);
       return ostr;
    }
    std::istream& operator>>(std::istream& istr, Time& D)
    {
       D.read(istr);
       return istr;
    }

    // Conversion Clock Helpers:

    int getHourClock(const int totMins)
    {
        int result;
        result = (totMins - (totMins % minsPerHour)) / minsPerHour;
        return result;
    }
    int getMinClock(const int totMins)
    {
        int result;
        result = totMins % minsPerHour;
        return result;
    }
    int getTotMinsFromClock(const int mins, const int hour)
    {
        int result;
        result = (hour * minsPerHour) + mins;
        return result;
    }


}