#include "Event.h"
#include <iomanip>

namespace seneca {
// Default constructor
Event::Event() : m_eventName(""), m_duration(0) {}

// Parameterized constructor
Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_eventName(name), m_duration(duration) {}

// Friend operator<< for output
std::ostream& operator<<(std::ostream& os, const Event& event) {
    static int counter = 0; // Local static counter to store the count even the fuction ends
    counter++;
     static int fieldSize=0;
     static std::string TIME_UNITS;

if (g_settings.m_time_units == "seconds") {
    // If the duration is 1 second or more
    TIME_UNITS = "seconds";
    fieldSize = 2;
} else if (g_settings.m_time_units == "milliseconds") {
    // If the duration is 1 millisecond or more but less than 1 second
    TIME_UNITS = "milliseconds";
    fieldSize = 5;
} else if (g_settings.m_time_units == "microseconds") {
    // If the duration is 1 microsecond or more but less than 1 millisecond
    TIME_UNITS = "microseconds";
    fieldSize = 8;
} else if (g_settings.m_time_units == "nanoseconds") {
    // If the duration is less than 1 microsecond, it's in nanoseconds
    TIME_UNITS = "nanoseconds";
    fieldSize = 11;
}

 
os <<std::setw(2)<<counter<<":"
   <<std::setw(40)<<event.m_eventName<<" -> "
   <<std::setw(fieldSize) << event.m_duration.count()<< " "<<TIME_UNITS;
    return os;
}
}