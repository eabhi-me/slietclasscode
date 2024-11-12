#include<iostream>
#include<string>
using namespace std;
class myStr{
    string str;
    public:
        void getStr(const string &data =""){
            str = data;
        }
        myStr operator+(myStr &obj){
            myStr newStrObj;
            newStrObj.str = str + obj.str;
            return newStrObj;
        }
        myStr operator+(const string& data){
            myStr newObj;
            newObj.str = str + data;
            return newObj;

        }
        void dispaly(){
            cout << str;
        }
};
int main(){
    myStr A,B,D;
    A.getStr("hello ");
    B.getStr("World");
    myStr C = A + B;
    D = C + " noooooo";
    C.dispaly();
    cout << endl;
    D.dispaly();
    return 0;
}