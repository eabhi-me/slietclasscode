#include<iostream>
using namespace std;

class Person{
    private:
        int age;
        int phoneno;
        string address;

    public:
        string name; 
        // Constructor
        Person(int a, string n){
            this->name = n;
            this->age = a;
        } 
        // Constructor Overloading
        Person(int a, string n, int phno, string add){
            this->age = a;
            this->name = n;
            this->phoneno = phno;
            this->address = add;
        }
        // Function overloading
        void introduce(){
            cout << "My name is " << name << " my age is " << age << endl;
        }
        void introduce(bool details){
            if(details){
               cout << "My name is " << name << " my age is " << age << " my Phone No is "<< phoneno << " my address is "<< address <<endl;
            }
            else{
                introduce();
            }
        }
        void sayhello(){
            cout << name << " say hello"<<endl;
        }
        void sayhello(string n){
            cout << name << " say hello to " << n << endl;
        }
        void sayhello(string n, int m){

            cout << name << "say hello to " << n << " " << m << " " << "times"<<endl;;
        }
        
};

int main(){
    Person p1(20,"Hero");
    p1.introduce();
    p1.sayhello();
    p1.sayhello("Raina");
    p1.sayhello("Jadav",5);

    Person p2(19,"Ramesh",457895523,"02 Hard Prak, Sangrur");
    p2.introduce(1);
    return 0;
}