#include <iostream>
#include <iomanip>
using namespace std;
// Function to calculate divided differences and store them in a table
void dividedDifferenceTable(double x[], double y[], double table[][10], int n) {
    // Initialize the first column with the given y values
    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];}
    // Fill the divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);}}
}
// Function to apply Newton's Divided Difference formula
double newtonInterpolation(double x[], double table[][10], double value, int n) {
    double result = table[0][0];  // Start with f[x0]
    // Apply the formula iteratively
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (value - x[i - 1]);
        result += term * table[0][i];}
    return result;
}
int main() {
    const int n = 4;
    double x[n] = {1, 3, 4, 6};
    double y[n] = {2, 6, 24, 48};
    // Table to store divided differences
    double table[n][10] = {0};
    // Fill the divided difference table
    dividedDifferenceTable(x, y, table, n);
    // Display the divided difference table
    cout << "Divided Difference Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << setw(10) << table[i][j] << "\t";}
        cout << endl;}
    // Value to interpolate
    double value;
    cout << "\nEnter the value to interpolate: ";
    cin >> value;
    // Interpolated result
    double result = newtonInterpolation(x, table, value, n);
    cout << "The interpolated value at " << value << " is " << result << endl; return 0;
}
