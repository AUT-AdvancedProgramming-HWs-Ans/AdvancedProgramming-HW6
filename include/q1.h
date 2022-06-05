#ifndef Q1_H
#define Q1_H

namespace q1 {

template <typename T, typename Func>
T derivation(T x0, Func f, T epsilon)
{
    /**
     * @brief calculate the derivative of a function
     *
     * @param x0 initial value
     * @param f function
     * @param epsilon epsilon
     *
     * @return T
     */

    return (f(x0 + epsilon) - f(x0)) / epsilon;
}

template <typename T, typename Func>
double gradient_descent(T initialValue, T stepSize, Func f = Func {})
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
    T x { initialValue };
    T fx { f(x) };

    T valueOfError { 0.001 };
    T func_dot {};

    // Iterating until the error is smaller than valueOfError
    do {
        // Calculating the derivative
        func_dot = derivation(x, f, valueOfError);
        x -= stepSize * func_dot;

    } while (std::abs(func_dot) > valueOfError);

    // Method 2:
    /*
        while (true) {
            // Checking the orientation of the gradient
            if (fx > f(x + stepSize))
                x += stepSize;
            else if (fx > f(x - stepSize))
                x -= stepSize;
            else
                break;
    
            fx = f(x);
        }
    */

    return x;
}

} // namespace q1

#endif // Q1_H