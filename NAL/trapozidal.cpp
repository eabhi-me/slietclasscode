#include <iostream>
#include <cmath>

// Function to be integrated
double f(double x) {
    return std::sin(x); // Example function, you can change it as needed
}

// Trapezoidal rule function
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }

    return sum * h;
}

int main() {
    double a = 0.0; // Lower limit
    double b = M_PI/2; // Upper limit
    int n = 10; // Number of subintervals

    double result = trapezoidalRule(a, b, n);
    std::cout << "The value of a: "<<a << " The Value of b: " << b <<std::endl;
    std::cout << "Number of term is " << n << "function is: sin(x) " <<std::endl;
    std::cout << "The integral is approximately: " << result << std::endl;

    return 0;
}