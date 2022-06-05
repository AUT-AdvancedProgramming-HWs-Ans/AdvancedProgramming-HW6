#ifndef Q3_H
#define Q3_H

// Importing the libraries
#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace q3 {

struct Flight {

    Flight(std::string _flight_number,
        size_t _duration,
        size_t _connectioins,
        size_t _connection_times,
        size_t _price)
        : flight_number { _flight_number }
        , duration { _duration }
        , connections { _connectioins }
        , connection_times { _connection_times }
        , price { _price }
    {

        /**
         * @brief constructor
         *
         * @param _flight_number flight number
         * @param _duration duration of the flight
         * @param _connectioins number of connections
         * @param _connection_times number of connection times
         * @param _price price of the flight
         *
         * @return Flight
         */
    }

    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};

inline auto comp {
    [](Flight flight1, Flight flight2) {
        return flight1.duration + flight1.connection_times + 3 * flight1.price
            > flight2.duration + flight2.connection_times + 3 * flight2.price;
    }
};

inline size_t timeToMinuteConverter(std::string time)
{
    /**
     * @brief convert time to minutes
     *
     * @param time time in format hh:mm
     *
     * @return size_t
     */

    if (time.empty())
        return 0;

    // finding the pattern
    std::smatch match {};
    std::regex pattern(R"((\d+)\h(\d+)?\m?)");
    std::regex_search(time, match, pattern);

    // Returning the time in minutes
    return static_cast<size_t>(std::stoi(match[1])) * 60
        + (((static_cast<std::string>(match[2])).empty())
                ? 0
                : static_cast<size_t>(std::stoi(match[2])));
}

inline auto gather_flights(std::string filename)
{
    /**
     * @brief read file and return arranged vector of flights
     *
     * @param filename name of the file
     *
     * @return std::vector<Flight>
     */

    // Working with the file
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    std::stringstream buffer {};
    buffer << file.rdbuf();
    std::string text { buffer.str() };

    std::priority_queue<Flight, std::vector<Flight>, decltype(comp)> flights { comp };

    // Defining the pattern
    std::regex pattern(R"(\w+\:(\w+) - \w+\:(\d+\h\d*\m*) - \w+\:(\d+) - \w+\:(\d+\h\d*\m*),?(\d+\h\d*\m*)?,?(\d+\h\d*\m*)? - \w+\:(\d+))");

    std::smatch match {};

    // Finding the pattern in the text and adding the flights to the queue
    while (std::regex_search(text, match, pattern)) {
        flights.push(Flight {
            match[1],
            timeToMinuteConverter(match[2]),
            static_cast<size_t>(std::stoi(match[3])),
            timeToMinuteConverter(match[4])
                + timeToMinuteConverter(match[5])
                + timeToMinuteConverter(match[6]),
            static_cast<size_t>(std::stoi(match[7])) });

        text = match.suffix().str();
    }

    return flights;
}

} // namespace q4

#endif // Q3_H