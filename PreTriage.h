/* Citation and Sources...
Final Project Milestone 5
Module         : PreTriage
Filename       : PreTriage.h
Original Author: Unspecified Prof
Source         : Project Instructions 
Mods & Comments: Kathleen Monks
-----------------------------------------------------------*/
#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_

#include "Menu.h"
#include "Time.h"
#include "Patient.h"

namespace sdds
{
    const int maxNoOfPatients = 100; // max lineup amount
    class PreTriage
    {   
        // Data Members
		// ============
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{}; 
        char* m_dataFilename = nullptr; 
        int m_lineupSize = 0; 
        Menu
            m_appMenu, 
            m_pMenu;  

        // Member Functions
        // ================
        bool setFilename(const char* fname); // kathleen's prototype aug/01/2021
        void setLineupSize(); //  kathleen's prototype aug/01/2022
        void saveFile(const char* fname)const; // kathleen's prototype aug/01/2021
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        // =================================
        PreTriage(const char* dataFilename);
        ~PreTriage();
        // ==========
        void run(void); // app menu

        // Class Constraints
        // =================
        const char delim = ','; // csv file
        char covidType = 'C'; 
        char triageType = 'T';

    };
}
#endif // !SDDS_PRETRIAGE_H_
