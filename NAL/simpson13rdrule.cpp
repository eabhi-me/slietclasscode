#include <iostream>
#include <cmath>
#include <functional>
using namespace std;
double simpsonsRule(function<double(double)> func, double a, double b, int n) {
    if (n % 2 != 0) {
        cerr << "Number of intervals must be even." << endl;
        return -1;
    }
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * func(x);
        } else {
            sum += 4 * func(x);
        }
    }
    return (h / 3) * sum;
}
int main() {
    auto func = [](double x) -> double { return sqrt(cos(x)); }; // Example function:
    double a = 0.0; // Lower limit
    double b = M_PI/2; // Upper limit
    int n = 6; // Number of intervals (must be even)
    double result = simpsonsRule(func, a, b, n);
    if (result != -1) {
        cout << "The integral is: " << result << endl;}
    return 0;
}