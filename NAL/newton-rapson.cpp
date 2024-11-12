#include<iostream>
#include<iomanip>
#include<math.h>
#define EPSILON  0.0001
using namespace std;
double f(double x){   // roots lie between 0-3
	double f = x*x*x-x-11;
	return f;
}
double f1(double x){   //Derivative
    double f1 = 3*x*x-1;
    return f1;
}
void NewtonRaspon(double a){
    double x0 = a,x1;
    double h = f(x0)/f1(x0);
    int count = 0; 
    while(abs(h)>=EPSILON){
        if(f1(x0)==0){
            cout << "Derivative is Zero";
            break;
        }
        x1 = x0-h;
        x0 = x1; 
        h = f(x0)/f1(x0);
        count++;
        cout << count << " iteration " << x1 << endl;
    }
    cout<<"After the "<< count  << " Iteration the root is " << x1; 
}
int main(){
    cout << "Newton Rapson Method"<<endl;
    cout << "f(x) = x*x*x-x-11 " << endl;
    cout << "Initial Guess is 0.5" << endl;
    NewtonRaspon(0.5);
    return 0;
}
