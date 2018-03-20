#include <iostream>
#include <typeinfo>
#include <stdio.h>

using namespace std;

class Base {
public:
    virtual void talk() { cout << __PRETTY_FUNCTION__ << endl; }
    void talk2() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Derived : public Base {
public:
    void talk() { cout << __PRETTY_FUNCTION__ << endl; }
    void talk2() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main(int argc, char **argv)
{
    int a = 1;
    string b = "s";
    double c = 1.0;
    double *d = &c;
    //cout << typeid(a).hash_code() << endl; // c++11
    cout << "int:" << typeid(a).name() << endl;
    cout << "string:" << typeid(b).name() << endl;
    cout << "double:" << typeid(c).name() << endl;
    cout << "double *:" << typeid(d).name() << endl;

    cout << "comparison:" << (typeid(c) == typeid(a)) << endl;
    const type_info &r1 = typeid(cout << a << endl);
    cout << r1.name() << endl;
    cout << typeid(printf("%d\n", a)).name() << endl;
    Base *base = NULL;
    cout << "*base:" << typeid(base).name() << endl;
    try {
        cout << typeid(*base).name() << endl;
    }
    catch(bad_typeid e) {
        cout << "catch bad_typed" << endl;
    }
    return 0;
}
