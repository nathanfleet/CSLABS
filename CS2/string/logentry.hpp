#ifndef LOGENTRY_HPP_
#define LOGENTRY_HPP_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp"

////////////////////////////////////////////////////////////
class Date {
public:
    Date() { day = ""; month = ""; year = 0; };
    Date(String d, String m, int y) { day = d; month = m; year = y; };

    void setDate(String d, String m, int y) { day = d, month = m, year = y; }; //mutator

    friend  std::ostream& operator<<(std::ostream&, const Date&);

private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
public:
    Time() { hour = 0; minute = 0; second = 0; };
    Time(int h, int m, int s) { hour = h; minute = m; second = s; };

    void setTime(int h, int m, int s) { hour = h; minute = m; second = s; }; //mutator

    friend  std::ostream& operator<<(std::ostream&, const Time&);

private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
    LogEntry() { host = ""; date.setDate("", "", 0); time.setTime(0, 0, 0); request = ""; status = ""; number_of_bytes = 0; };
    LogEntry(String);

    //accessor fn's
    String getHost()    const { return host; };
    Date   getDate()    const { return date; };
    Time   getTime()    const { return time; };
    String getRequest() const { return request; };
    String getStatus()  const { return status; };
    int    getBytes()   const { return number_of_bytes; }; 

    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};

////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse(std::istream&);
void                    output_all(std::ostream&, const std::vector<LogEntry>&);
void                    by_host(std::ostream&, const std::vector<LogEntry>&);
int                     byte_count(const std::vector<LogEntry>&);

int                     stringToInt(String);

#endif