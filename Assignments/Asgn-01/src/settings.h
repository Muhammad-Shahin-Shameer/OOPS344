#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

struct Settings {

    bool m_show_all = false;
    bool m_verbose = false;
    std::string m_time_units = "nanoseconds";


};

extern Settings g_settings;

#endif 