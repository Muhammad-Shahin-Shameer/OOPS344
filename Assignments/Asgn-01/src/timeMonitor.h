
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
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include<iostream>
#include <chrono>
#include <string>
#include "event.h"
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
