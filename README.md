# Project: General Hospital Pre-Triage Application

    MS1 V1.0
    MS2 V1.0
    MS3 V1.1
    V1.1: corrected minor problem in ms3tester.
    MS4 V1.1
    Corrected typo in csvRead, changed ostream to istream Here and Here
    MS5 V0.8 (Final Milestone)

Because of the pandemic and prevention of the spread of COVID19, hospitals need to screen the patients and separate those in need of COVID-test from others. This has to be done in an orderly fashion by letting the patients know what is the expected wait time and let them know when they can be admitted.

Your task is to help complete the implementation of the Pre-Triage application.
The Pre-Triage Application

The application starts by displaying a simple menu with three options:

    General Hospital Pre-Triage Application
    
    1- Register
    2- Admit
    0- Exit
    >

# Register

The register option is selected to screen patients before getting into the hospital. The user can select between a COVID Test or Triage.

COVID test is selected if the patient is at the hospital for a COVID Test. In this case, the patient's name and OHIP number is entered and then a ticket will be printed with a call number and estimated time of admission for the patient.

If Triage is selected then in addition to the patient's name and OHIP number, the symptoms of the patient are entered. Then a ticket for Triage is printed with an estimated time of admission.

# Admit

Admit is selected when the COVID Test area or the Triage section is ready to accept a patient. After selecting COVID or Triage, the patient with the next ticket in line will be called. Based on the time of the call, the average wait time for the next patient for that line up (COVID or Triage) will be updated.
Milestones and due dates

The project will be done in 4 or 5 milestones and each milestone will have its due date. The due date of each milestone will be announced when it is published, and it is based on the amount of work to be done for that milestone.
Citation, Sources

Compiling and Testing Your Program

All your code should be compiled using this command on matrix:

g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...

    -Wall: compiler will report all warnings
    -std=c++11: the code will be compiled using the C++11 standard
    -g: the executable file will contain debugging symbols, allowing valgrind to create better reports
    -o ws: the compiled application will be named ws

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is ws):

valgrind ws

To check the output, use a program that can compare text files. Search online for such a program for your platform, or use diff available on matrix.

    Note: All the code written in the project must be implemented in the sdds namespace.

# Project Implementation notes: Very Important, read carefully

    All the code written in this project should be within the namespace sdds.
    You are free and encouraged to add any member variables or member functions you find necessary to complete your code. If you are not sure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.
    A module called utils is added to the project with two functions that can be used in your implementation. As mentioned before, you can add any custom code of your own to the utils module to be used throughout the project. Also, because the application works with real system time, for debugging purposes a global sdds::debug flag is added to the utils module. (see Time module for more information)
    You are free to use this flag for your own debugging messages. utils.h will be included in all the testers of the milestones.
    Unless you are asked for a specific definition, name the variables, and functions yourself. Use proper names and follow the naming conventions instructed by your professor. Having meaningless and misleading names will attract a penalty.
    Throughout the project, if any class is capable of displaying or writing itself, the member function will always have the following signature: The function will return a reference of an ostream and will receive a reference of an "ostream" as an argument.
    Throughout the project, if any class is capable of reading or receiving its content from a stream, the member function will always have the following signature: The function will return a reference of an istream and will receive a reference on an istream as an argument.
    When creating methods (member functions) make sure to make them constant if in their logic, they are not modifying their class.
    When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.
    If an Empty state is required for an object, it is considered to be an “invalid” empty state, and objects in this state should be rendered unusable.

