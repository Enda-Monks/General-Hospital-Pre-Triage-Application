/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.h
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
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {
   
	extern bool debug; 

    // Time Utils
    // ===========
	int getTime(); // <-- provided in instructions

    // Input Utils
	// ===========
    int getInt(const char* prompt = nullptr);
    int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);
    char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');

    // Validation Utils
    // ================
    bool isValidIntFromRange(const int subject, const int minLimit, const int maxLimit); // kathleen's prototype
    bool isValidCString(const char* string); // kathleen's protytype
    bool isPositiveIntOrZero(const int arg); // kathleen's protytype
    bool isValidFilename(const char* fname); // csv ext. , kathleen's prototype

    // C-String Utils
    // ==============
    int strLen(const char* s); // via workshop 1
    void strCpy(char* des, const char* src); // via workshop 1

    // Templates
    // =========
    template <typename type> 
    void removeDynamicElement(type* array[], int index, int& size) // <-- provided in instructions
    {
        delete array[index];
        for (int j = index; j < size; j++)
        {
            array[j] = array[j + 1];
        }
        size--;
    }
}
#endif // !SDDS_UTILS_H_

