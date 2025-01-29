#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include<iostream>
#include <chrono>
#include <string>
#include "Event.h"
#include "logger.h"
namespace seneca {

    class TimeMonitor {

    private:

        std::string m_eventName; // Name of the current event
        std::chrono::high_resolution_clock::time_point m_startTime; // Time when the event started



    public:
        TimeMonitor();
        // Start a new event with a name
        void startEvent(const char* name);
        // Stop the current event, calculate duration, and return it as an Event object
        Event stopEvent();

    };






}
#endif
