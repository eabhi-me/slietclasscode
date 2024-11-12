#include<iostream>
#include<vector>
using namespace std;
// this method fail when there are numbers that have more digit that is not divisible by it..
int fairNum(int n){
    vector<int> remVec;
    int rem, actNum = n;
    while(n>0){
        rem = n%10;
        n = n/10;
        if(rem!=0){
            remVec.push_back(rem);
        }
    }
    for(int i = 0; i < remVec.size(); i++ ){
        int divirem = actNum % remVec[i];
        if(divirem!=0){
            actNum = actNum + divirem;
        }
    }
    return actNum;
}
int main(){
    cout << fairNum(282);
}