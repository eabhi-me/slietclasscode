#include<iostream>
using namespace std;
class vehical{
    public:
        int typeno;
        string bodytype;
        bool isflyable =false;
};
// derived class of vehivcal
class eBike: public vehical{
    private:
        float price;
        string seller;

    public:
        string model;
        int batterycapacity;
        int runtime;
        void Showcase(){
            cout  << "Model: " << model <<",battery: " << batterycapacity << ", Runtime " << runtime <<endl;
        }
        void setbuy(){
            cout << "enter the seller and price";
            cin >> seller >> price;
        }
        void getbuy(){
            cout << "Seller: " << seller << " Price: " << price << endl;
        }
};
// Another base call
class pertoBike{
    public:
        int petrocapacity;
        int speed;
        void testdrive(){
            cout << "Run at speed at " << speed <<endl;
        }

};

//Muliple and Multilevel inheritence
class Bike: public eBike, public pertoBike{
    public:
        Bike(string modl,int battery, int runt, int petro, int spd){
            this->model = modl;
            this->batterycapacity = battery;
            this->runtime = runt;
            this->petrocapacity = petro;
            this->speed = spd;
        }
        void run(){
            cout <<"Model " <<  model  << " Battery : " <<  batterycapacity 
            << "MH " << "Chemical: " << petrocapacity 
            << "L run continouolsy " << runtime << "H at " << speed << "Kmph";
        }
};

int main(){
    Bike b1("By0jt",1200,10,8,50);
    b1.run();
    b1.Showcase();
    // b1.testdrive();
    b1.setbuy();
    b1.getbuy();
    // cout << "Fly: "<< b1.isflyable;
}