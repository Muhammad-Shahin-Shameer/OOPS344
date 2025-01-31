
//////////////////////////////////////////////////////////////////////////*/
//Name  :Muhammad Shahin Shameer
//Student ID#:166626234
//Email      :msshameer@myseneca.ca
//Section    :NGG

//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "settings.h"

namespace seneca {

class Event{

    std::string m_eventName; // Nma of the event
    std::chrono::nanoseconds m_duration; //duration of the event 

    public:
   
   // Default constructor
    Event();

    // Parameterized constructor
    Event(const char* name, const std::chrono::nanoseconds& duration);

    // Friend operator<< for output
    friend std::ostream& operator<<(std::ostream& os, const Event& event);

};

std::ostream& operator<<(std::ostream& os, const Event& event);
}
#endif