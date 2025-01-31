
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
#include "event.h"
#include <iomanip>
using namespace std;
namespace seneca {
    // Default constructor
    Event::Event() : m_eventName(""), m_duration(0) {}

    // Parameterized constructor
    Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_eventName(name), m_duration(duration) {}

    // Friend operator<< for output
    std::ostream& operator<<(std::ostream& os, const Event& event) {
        static int counter = 0; // Local static counter to store the count even the fuction ends
        counter++;

        static int fieldSize = 0;

         double format = 1.0;

         if (g_settings.m_time_units == "seconds")
    {
      fieldSize = 2;
      format = 0.000000001;
    }
    else if (g_settings.m_time_units == "milliseconds")
    {
      fieldSize = 5;
      format = 0.000001;
    }
    else if (g_settings.m_time_units == "microseconds")
    {
      fieldSize = 8;
      format = 0.001;
    }
    else if (g_settings.m_time_units == "nanoseconds")
    {
      fieldSize = 11;
    }
    double duration = format * static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(event.m_duration).count());
os << std::right << std::setw(2) << counter << ": "
   << std::right << std::setw(40) << event.m_eventName
   << " -> " << std::right << std::setw(fieldSize) 
   << std::fixed << std::setprecision(0) << duration << " " << g_settings.m_time_units;



        return os;
    }
}