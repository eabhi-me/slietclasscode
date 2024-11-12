#include<bits/stdc++.h>
#define epsilon 0.00001
using namespace std;
/* 10x+y+z=12   -> x = (12-y-z)/10.0|2x+10y+z=13  -> y = (13-2*x-z)/10.0|2x+2y+10z=14  -> z = (14-2x-2*y)/10 .0 */
float xFun(float x, float y, float z){
    return ((12-y+z)/10.0);
}
float yFun(float x, float y, float z){
    return ((3-2*x-z)/10.0);
} 
float zFun(float x, float y, float z){
    return ((14-2*x-2*y)/10.0);
}
void JacobiMethod(){
    float x0 = 0, y0 = 0, z0 = 0; int count = 0;
    float xn = xFun(x0,y0,z0);
    float yn = yFun(x0,y0,z0);
    float zn = zFun(x0,y0,z0);
    while(fabs(x0-xn)>epsilon || fabs(y0-yn)>epsilon || fabs(z0-zn)>epsilon){
        x0 = xn; y0 = yn; z0 = zn;
        xn = xFun(x0,y0,z0);
        yn = yFun(x0,y0,z0);
        zn = zFun(x0,y0,z0);
        cout << "The value of X" << count<<" = " << xn << endl;
        cout << "The Valve of y" << count<<" = "<< yn << endl;
        cout << "The value of z" << count<<" = "<< zn << endl;cout << endl;count++;
    }
    cout << "Jacobi Method" << endl;
    cout << "After nth " << count  << " Iteration" << endl;
    cout << "The value of X = " << xn << endl;
    cout << "The Valve of y = " << yn << endl;
    cout << "The value of y = " << zn << endl;
}
int main(){
    JacobiMethod();
    return 0;
}