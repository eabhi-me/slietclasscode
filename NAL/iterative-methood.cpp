#include<iostream>
#include<math.h>
#include<iomanip>
# define EPSLION 0.001
using namespace std;
double f(double x){
    // rotts Lie in [0,3];
    double f = x*x*x-x-11;
    return f; 
}
float g(float x){
    float g = pow(x+11,1.0/3);
    // double g2 = (x*x*x-11);
    // double g3 = pow((11/(x-1)),1/2);
    // as g1'(0) < 1; and roots lie in [0,3] this is less than 1 in this
    return g;
}

void iterarive(double a){
    double a0 = g(0); // putting value 0
    double h = a-a0;
    int count = 0;
    while(abs(h)>=EPSLION){
        a = g(a0);
        // upadte to next iter
        h = a - a0;
        a0 = a;
        count++;
    }
    cout << "After " << count << " Iteration roots are " << a << endl;
    cout << "After re putiing the roots in f(x) =  " << f(a) << endl;
}

int main(){
    iterarive(1.2);
    return 0;
}