#include "Event.h"
#include <iomanip>

// Default constructor
Event::Event() : m_eventName(""), m_duration(0) {}

// Parameterized constructor
Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_eventName(name), m_duration(duration) {}

// Friend operator<< for output
std::ostream& operator<<(std::ostream& os, const Event& event) {
    static int counter = 0; // Local static counter to store the count even the fuction ends
    counter++;
     int fieldSize;
     std::string TIME_UNITS;



if (event.m_duration >= std::chrono::seconds(1)) {
    // If the duration is 1 second or more
    TIME_UNITS = "seconds";
    fieldSize = 2;
} else if (event.m_duration >= std::chrono::milliseconds(1)) {
    // If the duration is 1 millisecond or more but less than 1 second
    TIME_UNITS = "milliseconds";
    fieldSize = 5;
} else if (event.m_duration >= std::chrono::microseconds(1)) {
    // If the duration is 1 microsecond or more but less than 1 millisecond
    TIME_UNITS = "microseconds";
    fieldSize = 8;
} else {
    // If the duration is less than 1 microsecond, it's in nanoseconds
    TIME_UNITS = "nanoseconds";
    fieldSize = 11;
}


os <<std::setw(2)<<counter<<":"
   <<std::setw(40)<<event.m_eventName<<" -> "
   <<std::setw(fieldSize) << event.m_duration.count()<< " "<<TIME_UNITS;
    return os;
}