#ifndef Q1_H
#define Q1_H

namespace q1
{
    template <typename T, typename Func>
    double gradient_descent(T initialValue, T stepSize, Func f = Func{})
    {
        /**
         * @brief gradient descent algorithm
         *
         * @param initialValue initial value of the variable
         * @param stepSize step size of the algorithm
         * @param f function to minimize
         * 
         * @return T minimum value of the function
         */

        // Defining the variables
        T x{initialValue};
        T fx{f(x)};

        while (true)
        {
            // Checking the orientation of the gradient
            if (fx > f(x + stepSize))
                x += stepSize;
            else if (fx > f(x - stepSize))
                x -= stepSize;
            else
                break;

            fx = f(x);
        }

        return x;
    }
}

#endif // Q1_H