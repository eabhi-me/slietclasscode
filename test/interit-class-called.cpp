#include <iostream>

using namespace std;
class A{
    int z;
    public:
        A(){cout << "0\t";}
};

class B : public A {
    int x;
public:
    B() { cout << "1\t"; }
};

class D : public B {
    int y;
public:
    D() { cout << "2\t"; }
    D(int i) { cout << "3\t"; }
};
class Z{
    public:
        Z(){cout << "Y\t";}
};
class E : public A, public Z{
    public :
        E(){cout << "7\t";}
};

int main() {
    A a;
    cout << endl << "called" << endl;
    B b;
    cout <<endl<< "called" << endl;
    D d1;
    cout <<endl<< "called" << endl;
    D d2(1);
    cout <<endl<< "called" << endl;
    E e;
}
