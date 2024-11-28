#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Function to perform quadratic curve fitting
void quadraticCurveFitting(const vector<double>& x, const vector<double>& y, double& a, double& b, double& c) {
    int n = x.size();
    double sumX = 0, sumY = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0, sumXY = 0, sumX2Y = 0;
for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }
    double denominator = n * (sumX2 * sumX4 - sumX3 * sumX3) - sumX * (sumX * sumX4 - sumX2 * sumX3) 
        + sumX2 * (sumX * sumX3 - sumX2 * sumX2);
    a = (sumY * (sumX2 * sumX4 - sumX3 * sumX3) - sumX * (sumXY * sumX4 - sumX2Y * sumX3) 
        + sumX2 * (sumXY * sumX3 - sumX2Y * sumX2)) / denominator;
    b = (n * (sumXY * sumX4 - sumX2Y * sumX3) - sumY * (sumX * sumX4 - sumX2 * sumX3) 
        + sumX2 * (sumX * sumX2Y - sumY * sumX2)) / denominator;
    c = (n * (sumX2 * sumX2Y - sumX3 * sumXY) - sumX * (sumX * sumX2Y - sumY * sumX3) 
        + sumY * (sumX * sumX3 - sumX2 * sumX2)) / denominator;
}
int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2.2, 2.8, 3.6, 4.5, 5.1};

    double a, b, c;
    quadraticCurveFitting(x, y, a, b, c);
    cout << "X = {1, 2, 3, 4, 5}" <<endl;
    cout << "Y = {2.2, 2.8, 3.6, 4.5, 5.1}" <<endl;
    cout << "The quadratic curve fitting result is: y = " << a << " + " << b << "x + " << c << "x^2" << endl;
    return 0;
}