//
//
// File:        logentry.cpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp"
#include "logentry.hpp"

//////////////////////////////////////////////////////////
// REQUIRES: A String object
// ENSURES: Turns string with # chars into an integer
int strToInt(String str) {
    int result = 0;

    for (int i = 0; i < str.length(); ++i) {
        result = (result * 10) + (str[i] - int('0'));
    }
    return result;
}

//////////////////////////////////////////////////////////
// REQUIRES: A String object
// ENSURES: String contains correct amount of elements when split by ' ', and stores it as a LogEntry
//
LogEntry::LogEntry(String s) : LogEntry() {
    std::vector<String> vec = s.split(' ');

    if (!(vec.size() < 10)) { //logEntry is correct size
        host = vec[0];
        
        //[18/Sep/2002:12:05:25 -0400]
        std::vector<String> timeVec = vec[3].split(':');
        int vecHour = strToInt(timeVec[1]);
        int vecMin = strToInt(timeVec[2]);
        int vecSec = strToInt(timeVec[3]);

        time = Time(vecHour, vecMin, vecSec);

        //[18/Sep/2002:12:05:25 -0400]
        std::vector<String> dateVec = vec[3].split('/');
        String vecDay(dateVec[0]);
        String vecMonth(dateVec[1]);
	std::vector<String> dateVec2 = dateVec[2].split(':');
	int vecYear = strToInt(dateVec2[0]);

        date = Date(vecDay, vecMonth, vecYear);

        //"GET /~darci/ HTTP/1.0"
        String req(vec[5] + vec[6] + vec[7]);
        request = req;
        
        String stat(vec[8]);
        status = stat;

        int num = strToInt(vec[9]);
        if (num >= 0) {
            number_of_bytes = num;
        } else {
            number_of_bytes = 0;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.month << " " << date.day << ", " << date.year;

    return out;
}

std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << time.hour << ":" << time.minute << ":" << time.second;

    return out;
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
    out << log.status << " " << log.host << " made request " << log.request << " at " << log.time << " on " << log.date << " and recieved " << log.number_of_bytes << " bytes.";

    return out;
}

//////////////////////////////////////////////////////////
// REQUIRES: Input stream
// ENSURES: A LogEntry object is created for each line in the file
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;

    char* temp = new char[200];

    while (!in.eof()) {
        in.getline(temp, 200);
        String s(temp);
        LogEntry l(s);
        result.push_back(l);
    }

    return result;
}

//////////////////////////////////////////////////////////
// REQUIRES: A vector of LogEntry
// ENSURES: All LogEntry objects are outputted
//
void output_all(std::ostream& out, const std::vector<LogEntry>& vec) {
    int size = vec.size();

    for (int i = 0; i < size; ++i) {
        if (vec[i].getStatus() != "") {
            out << vec[i] << std::endl;
        }
    }
}

//////////////////////////////////////////////////////////
// REQUIRES: A vector of LogEntry
// ENSURES: Host member of each LogEntry member printed out (one per line)
//
void by_host(std::ostream& out, const std::vector<LogEntry>& vec) {
    String host("");

    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        host = vec[i].getHost();
        out << host << std::endl;
    }
}

//////////////////////////////////////////////////////////
// REQUIRES: A vector of LogEntry
// ENSURES: Total number of bytes of all the LogEntry objects combined
//
int byte_count(const std::vector<LogEntry>& vec) {
    int result = 0;

    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        result += vec[i].getBytes();
    }

    return result;
}
