
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
#include "timeMonitor.h"
#include <stdexcept>

using namespace std;
namespace seneca {

    //constructor
TimeMonitor::TimeMonitor():m_eventName(""),m_startTime(){};



void TimeMonitor::startEvent(const char* name){

 
// assign the name of the event
    m_eventName=name;
    //assign the curret time
    m_startTime=std::chrono::high_resolution_clock::now();
    
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

}