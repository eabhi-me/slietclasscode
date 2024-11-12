#include<iostream>
using namespace std;
class living{

private:
    string name;
    int age;
    string sound;
    
public:
    string type;
    string species;
    void sayhello(){
        cout << sound;
    }

};
class dog: public living{
public:
    string sound = "bho bho";
};
int main(){
    dog ronny;
    ronny.type = "Indian";
    ronny.species = "Animal";
    ronny.sayhello();
    return 0;  
}