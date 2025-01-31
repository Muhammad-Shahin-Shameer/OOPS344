
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
#include "logger.h"


namespace seneca {

Logger::Logger() {
 //also can be done using single line 
//Logger::Logger() : m_events(nullptr), m_size(0), m_capacity(0) {}
m_events=nullptr;
m_capacity=0;
m_size=0;
}

Logger::~Logger(){
    delete[] m_events;//delete the dynamically allocated memmory
}

Logger::Logger(Logger&& other) noexcept : m_events(other.m_events),m_size(other.m_size),m_capacity(other.m_capacity)
{
    //^Move all from the temporary object(other.OBJ) to this(main obj) object  

    // After moving the data, the other object is left in a valid but unspecified state.
    // This ensures that no resources are deallocated or left dangling after the move.
other.m_events=nullptr; // set safe value
other.m_capacity=0;
other.m_size=0;
}

Logger& Logger::operator=(Logger&& other) noexcept{

if (this!=&other)   {// check is this try to assign same copy 
//if not clear the currect copy
/*m_events is dynamically allocated (probably using new[]), 
 must deallocate it before assigning a new value or moving
  data into it*/
delete[] m_events; 

 // Transfer ownership of resources from other
        m_events = other.m_events;
        m_size = other.m_size;
    m_capacity = other.m_capacity;

// Call the default constructor to reset `other`
            //other = Logger(); 
            other.m_events=nullptr; // set safe value
            other.m_capacity=0;
            other.m_size=0;


} 
return *this;
}



// Add event to the logger
void Logger::addEvent(const Event& event) {
    // check the array is full or not
    if (m_size >= m_capacity) {
        // Resize the array if necessary
        size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        resizeArray(newCapacity); //  calling fuction to resize arry 
    }
    m_events[m_size++] = event; // Add the event 
   
}

// Resize the array if necessary //privite function
void Logger::resizeArray(size_t newCapacity) {
    Event* newArray = new Event[newCapacity];// createing a newAry of event with the extected size 

// Copy existing events
    for (size_t i = 0; i < m_size; ++i) {
        newArray[i] = m_events[i]; 
    }
    delete[] m_events; // dealoocate old memory 
    m_events = newArray; // assign pointer to pointer 
    m_capacity = newCapacity;//Update the capacity to the new size for size checking
}


// Friend function to insert all events into the output stream
std::ostream& operator<<(std::ostream& os, const Logger& logger) {
    for (size_t i = 0; i < logger.m_size; ++i) {
        os << logger.m_events[i] << std::endl; // Output each event
    }
    return os;
}
}
    