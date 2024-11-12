#include<iostream>
using namespace std;
int sumNum(int n){
    int rem, sum=0;
    while(n>0){
        rem = n%10;
        sum = sum+rem;
        n = n/10;
    }
    return sum;
}

int main(){
    int count;
    cin >> count;
    int arr[count];
    for(int i = 0; i<count; i++){
        cin >> arr[i];
    }
    for(int j = 0; j <count; j++){
        cout << sumNum(arr[j]) << endl;
    }
    return 0;
}