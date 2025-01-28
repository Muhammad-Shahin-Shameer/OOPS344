#include "TimeMonitor.h"
#include <stdexcept>

TimeMonitor::TimeMonitor():m_eventName(""),m_startTime(),m_isEventActive(false){};



void TimeMonitor::startEvent(const char* name){
// check the name is valid 
 if (name != nullptr && *name != '\0'){
// assign the name of the event
    m_eventName=name;
    //assign the curret time
    m_startTime=std::chrono::high_resolution_clock::now();
    }
        }

Event TimeMonitor::stopEvent(){
 auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - m_startTime);

    // Create and return the Event object using its parameterized constructor
    Event event(m_eventName.c_str(), duration);

    // Reset the current event state
    m_eventName.clear();

    return event;
}

    