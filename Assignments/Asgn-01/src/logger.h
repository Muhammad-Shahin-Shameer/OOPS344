#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include <iostream>

#include "event.h"
namespace seneca {
  class Logger {

  private:

    Event* m_events;  // This is a pointer to a dynamically allocated array of Event objects.
    size_t m_size;    // This variable keeps track of the current number of events stored in the array.
    size_t m_capacity; // Maximum number of events the array can hold

    //  resize the array if necessary after checking the Max capacity
    void resizeArray(size_t newCapacity);

  public:
    // Default constructor
    Logger();

    // Destructor
    ~Logger();

    // Move constructor
    //The purpose is to transfer the data from the other object to the main logger object without creating a copy.
    Logger(Logger&& other) noexcept;

    // Move assignment operator
    /*
    When using the assignment operator (=) to assign an object, it first checks if the temporary
     object is valid. If valid, it assigns the value; otherwise, it handles the invalid case accordingly
    */
    Logger& operator=(Logger&& other) noexcept;

    // Disable copy constructor and copy assignment operator
    /*it's generally considered good practice to delete the copy constructor
     and copy assignment operator when you define a move constructor and move
      assignment operator
    */
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Method to add an event to the logger
    void addEvent(const Event& event);

    // Friend function to print all events using operator<<
    friend std::ostream& operator <<(std::ostream& os, const Logger& logger);
  };
}

#endif
