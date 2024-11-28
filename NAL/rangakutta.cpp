#include <iostream>
#include <cmath>
using namespace std;

// Define the ODE: dy/dx = f(x, y)
double f(double x, double y) {
    return (y * y - x * x) / (y * y + x * x);
}

// Runge-Kutta 4th order method
void rungeKutta4(double x0, double y0, double xn, int n) {
    double h = (xn - x0) / n;
    double k1, k2, k3, k4, y = y0;
    cout << "x\t\t" << "y" << endl;
    
    for (int i = 0; i <= n; i++) {
        cout << x0 << "\t\t" << y << endl;
        if (i < n) {
            k1 = h * f(x0, y);
            k2 = h * f(x0 + h / 2, y + k1 / 2);
            k3 = h * f(x0 + h / 2, y + k2 / 2);
            k4 = h * f(x0 + h, y + k3);
            y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
            x0 += h;
        }
    }
    cout << "Final answer is: "<<endl;
    cout << xn << "\t\t" << y << endl;
  
}
int main() {
    double x0 = 0, y0 = 1, xn = 0.6, n = 3;
    rungeKutta4(x0, y0, xn, n);
    return 0;
}
