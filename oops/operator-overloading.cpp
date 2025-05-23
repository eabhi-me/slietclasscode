#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0){
        real = r;
        imag = i;
    }

    Complex operator+(Complex const& obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};

int main(){
    Complex c1(5, 5), c2(4, 4);
    c1.print();
    c2.print();
    Complex c3 = c1 + c2;
    Complex c4 = c1.operator+(c3);
    c3.print();
    c4.print();
}
