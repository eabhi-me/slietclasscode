#include<iostream>
using namespace std;
// ICPC questuon 1 solving
// wrong it as it has to understand about it..
int sumGcd(int n){
    int a = 1;
    int b = 1;
    int c = 1;
    int d = n-(a+b+c);
    bool checkgcd;
    if(gcd_optmised(a,c)==lcm_of_num(c,d)){
        checkgcd = true;
    }
    return 0;
}
int gcd_optmised(int a, int b){
    if(b==0){
        return a;
    }
    else
        return gcd_optmised(b,a%b);
}

int lcm_of_num(int a, int b){
    int product = a*b;
    int gcdres = gcd_optmised(a,b);
    return product/gcdres; 
}

void split(int x, int n)
{
 
// If we cannot split the 
// number into exactly 'N' parts
if(x < n)
cout<<"-1"<<" ";
 
         
 
    // If x % n == 0 then the minimum 
    // difference is 0 and all 
    // numbers are x / n
    else if (x % n == 0)
    {
        for(int i=0;i<n;i++)
        cout<<(x/n)<<" ";
    }
    else
    {
 
        // upto n-(x % n) the values 
        // will be x / n 
        // after that the values 
        // will be x / n + 1
        int zp = n - (x % n);
        int pp = x/n;
        for(int i=0;i<n;i++) 
        {
 
            if(i>= zp)
            cout<<(pp + 1)<<" ";
            else
            cout<<pp<<" ";
        }
    }
}

int main(){
    cout << gcd_optmised(4,5);
    cout << lcm_of_num(4,5);
}