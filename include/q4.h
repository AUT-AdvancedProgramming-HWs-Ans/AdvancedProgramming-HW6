#ifndef Q4_H
#define Q4_H

// Importing the libraries

namespace q4
{

    struct Vector2D
    {
        Vector2D(double _x, double _y)
            : x(_x), y(_y)
        {
            /**
             * @brief Vector2D constructor
             *
             * @param _x x coordinate
             * @param _y y coordinate
             */
        }

        double x{};
        double y{};
    };

    struct Sensor
    {
        Sensor(Vector2D _pos, double _accuracy)
            : pos(_pos), accuracy(_accuracy)
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

    

}

#endif // Q4_H