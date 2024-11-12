#include <bits/stdc++.h>
using namespace std;
float f(float x){
	float f = pow(x, 3) + x - 1; // we are taking equation as x^3+x-1
	return f;
}
void secant(float x1, float x2, float E){
	float n = 0, xm, x0, c;
	if (f(x1) * f(x2) < 0) {
		do {
			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));// calculate the intermediate value
			c = f(x1) * f(x0);  // check if x0 is root of equation or not
			x1 = x2;  // update the value of interval
			x2 = x0;
			n++;  // update number of iteration
			// if x0 is the root of equation then break the loop
			if (c == 0)
				break;
			xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
			cout <<n << " iteration " << x0 << endl;
		} while (fabs(xm - x0) >= E); // repeat the loop
								// until the convergence

		cout << "After "<<n<<" iterations  "<<"Root of the given equation is "<<x0<<endl;
	} else
		cout << "Cannot find a root in the given interval";
}
int main(){
	// initializing the values
	cout << "Secant Method"<<endl;
	cout << "f(x) = pow(x, 3) + x - 1" <<endl;
	float x1 = 0, x2 = 1, E = 0.0001;
	cout << "The value of x1: " << x1 << " and  value of x2: " << x2 << endl; 
	secant(x1, x2, E);
	return 0;
}
