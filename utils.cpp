/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
Version 1.0
Author	Kathleen Monks
Revision History
-----------------------------------------------------------
Date         Reason
2021/Jun/27  Preliminary release
2021/Jul/02  Debugged
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
   
	// Time Utils
	// ===========
	// returns the time of day in minutes 
    int getTime() { // < --given by prof
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

    // Input Utils
    // ===========
    int getInt(const char* prompt)
   {
	   int intValue = 0;
	   bool success = false;

	   if (prompt != nullptr)
	   {
		   std::cout << prompt;
	   }

	   do
	   {
		   std::cin >> intValue;

		   if (std::cin.fail())
		   {
			   std::cout << "Bad integer value, try again: ";
			   std::cin.clear();
			   std::cin.ignore(2000, '\n');
		   }
		   else if (char(std::cin.get()) != '\n') 
		   {
			   std::cout << "Enter only an integer, try again: ";
			   std::cin.ignore(2000, '\n');
		   }
		   else
		   {
			   success = true;
		   }

	   } while (!success);

	   return intValue;
   }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {

	   int intValue = 0;
	   bool success = false;

	   if (prompt != nullptr)
	   {
		   std::cout << prompt;
	   }

	   do
	   {
		   std::cin >> intValue;

		   if (std::cin.fail()) 
		   {
			   std::cout << "Bad integer value, try again: ";
			   std::cin.clear();
			   std::cin.ignore(2000, '\n');
		   }
		   else if (char(std::cin.get()) != '\n') 
		   {
			   std::cout << "Enter only an integer, try again: ";
			   std::cin.ignore(2000, '\n');
		   }
		   else
		   {
			   if (isValidIntFromRange(intValue, min, max))
			   {
				   success = true;
			   }
			   else
			   {
				   if (isValidCString(errorMessage))
				   {
					   std::cout << errorMessage;
					   if (showRangeAtError)
					   {
						   std::cout << "[" << min << " <= value <= " << max << "]: ";
					   }
				   }
			   }

		   }

	   } while (!success);

	   return intValue;
   }

    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
	   char* newStr = nullptr;
	   std::string input;

	   if (prompt != nullptr)
	   {
		   std::cout << prompt;
	   }

	   std::getline(istr, input, delimiter);

	   newStr = new char[input.length() + 1];
	   strCpy(newStr, input.c_str());

	   return newStr;

   }


    // Validation Utils
    // ================
    bool isValidIntFromRange(const int subject, const int minLimit, const int maxLimit)
   {
	   return (subject >= minLimit) && (subject <= maxLimit);
   }
    bool isValidCString(const char* string)
   {
	   return (string[0] != '\0' && string) ? true : false;
   }
	bool isPositiveIntOrZero(const int arg)
	{
		return (arg >= 0);
	}
	bool isValidFilename(const char* fname) //csv
	{
		int extIndex = 0;
		bool result = false;

		if (isValidCString(fname))
		{
			if (strLen(fname) > 4)
			{
				extIndex = strLen(fname) - 4;
			}

			if (fname[extIndex++] == '.' &&
				fname[extIndex++] == 'c' &&
				fname[extIndex++] == 's' &&
				fname[extIndex] == 'v')
			{
				result = true;
			}
		}

		return result;
	}

    // C-String Utils
    // ==============
    int strLen(const char* s)
   {
	   int len = 0;

	   while (s[len])
	   {
		   len++;
	   };

	   return len;
   }
    void strCpy(char* des, const char* src)
   {
	   int i;

	   for (i = 0; src[i] != '\0'; i++) // danger: possible stack overflow, if des < src
	   {
		   des[i] = src[i];
	   }

	   des[i] = '\0';
   }
}