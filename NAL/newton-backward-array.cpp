#include <iostream>
#include <cmath>
using namespace std;
// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;}
    return fact;
}
// Function to calculate the value using Newton Backward Interpolation
double newtonBackward(double x[], double y[], int n, double value) {
    double diffTable[n][n];
    // Initialize the difference table
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];}
    // Calculate the backward differences
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];} 
    }
    cout << "Backward Difference Table:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << diffTable[i][j] << "\t";}
        cout << endl;
    }
    // Calculate the value using Newton Backward Interpolation formula
    double result = diffTable[n - 1][0];
    double u = (value - x[n - 1]) / (x[1] - x[0]);
    double uTerm = 1;
    for (int i = 1; i < n; i++) {
        uTerm *= (u + i - 1);
        result += (uTerm * diffTable[n - 1][i]) / factorial(i);}
    return result;
}
int main() {
    const int n = 5;
    double x[n] = {1, 2, 3, 4, 5}; // Example x values
    double y[n] = {1, 4, 9, 16, 25}; // Example y values (y = x^2)
    double value = 2.5; // Value to interpolate
    double result = newtonBackward(x, y, n, value);
    cout << "The interpolated value at " << value << " is " << result << endl;
    return 0;
}