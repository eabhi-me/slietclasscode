#include<iostream>
using namespace std;
//Polymorphism as complile time as function overriding  and runtime using virtural 
class parent{
    public: // function written
        void getAcess(){
            cout << "Have Full Ascess" <<endl;
        }
        // Function overriding usning virtual function during runtime
        virtual void say(){
            cout << "Hello Child" << endl;
        }
}; 
// derived Class of parent 
class child: public parent{
    public: // function overrides
        void getAcess(){
            cout << "Have limited ascess" << endl;
        }
        // Funtion overrides the virtual during runtime
        void say(){
            cout << "Hello parent" <<endl;
        }
};

int main(){
    parent p1; // parent object
    child c1; // child object
    c1.getAcess(); // calling the method as function as it is overrides in different level class
    p1.getAcess();
    p1.say();
    c1.say();
    return 0;
}
