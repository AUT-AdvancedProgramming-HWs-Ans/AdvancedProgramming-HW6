#ifndef Q2_H
#define Q2_H

// Importing the libraries
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <iostream>

namespace q2
{
    struct Patient
    {
        Patient(std::string _name,
                size_t _age,
                size_t _smokes,
                size_t _area_q,
                size_t _alkhol) : name{_name},
                                  age{_age},
                                  smokes{_smokes},
                                  area_q{_area_q},
                                  alkhol{_alkhol}
        {

            /**
             * @brief constructor
             *
             * @param _name name of the patient
             * @param _age age of the patient
             * @param _smokes number of cigarettes smoked per day
             * @param _area_q area of quadrant
             * @param _alkhol number of years of alcohol consumed
             *
             * @return Patient
             */
        }
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };

    static std::vector<Patient> read_file(std::string filename)
    {
        /**
         * @brief read file and return a vector of patients
         *
         * @param filename name of the file
         *
         * @return std::vector<Patient>
         */

        std::ifstream file(filename);

        if (!file.is_open())
            throw std::runtime_error("Could not open file");

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string txt{buffer.str()};

        std::vector<Patient> patients{};

        std::regex pattern(R"((\w+) ?,(\w+) ?,(\d+),(\d+),(\d+),(\d+))");
        std::smatch match{};

        while (std::regex_search(txt, match, pattern))
        {
            patients.push_back(Patient{static_cast<std::string>(match[1]) +
                                           " " +
                                           static_cast<std::string>(match[2]),
                                       static_cast<size_t>(std::stoi(match[3])),
                                       static_cast<size_t>(std::stoi(match[4])),
                                       static_cast<size_t>(std::stoi(match[5])),
                                       static_cast<size_t>(std::stoi(match[6]))});
            txt = match.suffix().str();
        }

        return patients;
    }

}

#endif // Q2_H