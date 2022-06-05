#ifndef Q4_H
#define Q4_H

// Importing the libraries
#include <numeric>

namespace q4 {

struct Vector2D {
    Vector2D(double _x, double _y)
        : x(_x)
        , y(_y)
    {
        /**
         * @brief Vector2D constructor
         *
         * @param _x x coordinate
         * @param _y y coordinate
         */
    }

    double x {};
    double y {};
};

struct Sensor {
    Sensor(Vector2D _pos, double _accuracy)
        : pos(_pos)
        , accuracy(_accuracy)
    {
        /**
         * @brief Sensor constructor
         *
         * @param _pos position of the sensor
         * @param _accuracy accuracy of the sensor
         */
    }

    Vector2D pos;
    double accuracy;
};

inline auto accuracySum {
    [](double sum, Sensor& sensor) {
        return sum + sensor.accuracy;
    }
};

inline auto weighted_X {
    [](double sum, Sensor& sensor) {
        return sum + sensor.pos.x * sensor.accuracy;
    }
};

inline auto weighted_Y {
    [](double sum, Sensor& sensor) {
        return sum + sensor.pos.y * sensor.accuracy;
    }
};

inline Vector2D kalman_filter(std::vector<Sensor> sensors)
{
    /**
     * @brief Kalman filter
     *
     * @param sensors vector of sensors
     *
     * @return Vector2D
     */

    // Calculating the sum of the accuracies
    double sumOfAccuracies {
        std::accumulate(sensors.begin(),
            sensors.end(),
            0.0,
            accuracySum)
    };

    // Calculating the weighted X coordinate
    double filtered_x_position {
        std::accumulate(sensors.begin(),
            sensors.end(),
            0.0,
            weighted_X)
        / sumOfAccuracies
    };

    // Calculating the weighted Y coordinate
    double filtered_y_position {
        std::accumulate(sensors.begin(),
            sensors.end(),
            0.0,
            weighted_Y)
        / sumOfAccuracies
    };

    return Vector2D { filtered_x_position, filtered_y_position };
}

} // namespace q4

#endif // Q4_H