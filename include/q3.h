#ifndef Q3_H
#define Q3_H

// Importing the libraries
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <queue>

namespace q4
{

    struct Flight
    {

        Flight(std::string _flight_number,
               size_t _duration,
               size_t _connectioins,
               size_t _connection_times,
               size_t _price)
            : flight_number{_flight_number},
              duration{_duration},
              connections{_connectioins},
              connection_times{_connection_times},
              price{_price}
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

    inline auto comp{
        [](Flight flight1, Flight flight2)
        {
            return flight1.duration + flight1.connection_times + 3 * flight1.price >
                   flight2.duration + flight2.connection_times + 3 * flight2.price;
        }};

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

        std::smatch match{};
        std::regex pattern(R"((\d+)\h(\d+)?\m?)");
        std::regex_search(time, match, pattern);
        
        return static_cast<size_t>(std::stoi(match[1])) * 60 +
               (((static_cast<std::string>(match[2])).empty())
                    ? 0
                    : static_cast<size_t>(std::stoi(match[2])));
    }

} // namespace q4

#endif // Q3_H