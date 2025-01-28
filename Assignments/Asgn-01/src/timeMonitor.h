#ifndef TIMEMONITOR_H
#define TIMEMONITOR_H

#include<iostream>
#include <chrono>
#include <string>
#include "Event.h"
#include "logger.h"


class TimeMonitor{

private:

    std::string m_eventName; // Name of the current event
    std::chrono::high_resolution_clock::time_point m_startTime; // Time when the event started
    bool m_isEventActive = false; // Flag to indicate if an event is currently active


public:
    TimeMonitor();
   // Start a new event with a name
    void startEvent(const char* name);
 // Stop the current event, calculate duration, and return it as an Event object
    Event stopEvent();

};







#endif