#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01
double func(double x){
	return x*x*x - x*x + 2;
}
void bisection(double a, double b){   // Prints root of func(x) with error of EPSILON
	if (func(a) * func(b) >= 0){
		cout << "You have not assumed right a and b\n";
		return;
	}
	int count = 0;
	double c = a;
	while ((b-a) >= EPSILON){
		c = (a+b)/2;  // Find middle point
		count++;
		cout << count << " Iteration c = "<< c << endl;
		if (func(c) == 0.0)   // Check if middle point is root
			break;
		else if (func(c)*func(a) < 0)   // Decide the side to repeat the steps
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}
int main(){
	double a =-200, b = 300;   // Initial values assumed
	cout << "Bisection Method"<<endl;
	cout << "f(x) = x*x*x - x*x + 2" << endl;
	cout << "Value of a: " << a << " Value of b is " << b <<endl;
	bisection(a, b);
	return 0;
}
