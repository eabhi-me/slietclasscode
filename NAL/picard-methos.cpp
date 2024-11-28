#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

// Function to be integrated
double f(double x, double y) {
    return x + y;
}
// Picard iteration method
double picard(double x0, double y0, double x, int n) {
    double y = y0;
    double h = (x - x0) / n;
    for (int i = 0; i < n; ++i) {
        double x_i = x0 + i * h;
        double y_i = y0;
        for (int j = 0; j <= i; ++j) {
            y_i += h * f(x0 + j * h, y);
        }
        y = y_i;
    }
    return y;
}
int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double x = 1.0;
    int n = 10; // Number of iterations

    double result = picard(x0, y0, x, n);
    cout << "X0 = " << x0 <<", y0 = " << y0 << " The nubmber of term is : "<< n<<endl;
    cout << "The approximate solution at x = " << x << " is y = " << result << std::endl;

    return 0;
}