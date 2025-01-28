#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "settings.h"



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

#endif