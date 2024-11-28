#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Define the function f(x, y) = dy/dx
double f(double x, double y) {
    return x + y; // Example function, you can change it as needed
}
// Euler's Modified Method to solve ODE
void eulersModifiedMethod(double x0, double y0, double xn, double h) {
    double x = x0;
    double y = y0;
    int n = (int)((xn - x0) / h);

    cout << fixed << setprecision(4);
    cout << "x\t y\n";
    cout << x << "\t" << y << "\n";

    for (int i = 0; i < n; ++i) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y = y + 0.5 * (k1 + k2);
        x = x + h;
        cout << x << "\t" << y << "\n";
    }
    cout << "Final result is : x = " << x << " y = " << y << endl; 
}
int main() {
    double x0 = 0.0; // Initial value of x
    double y0 = 1.0; // Initial value of y
    double xn = 2.0; // Value of x at which y is required
    double h = 0.2;  // Step size

    eulersModifiedMethod(x0, y0, xn, h);

    return 0;
}