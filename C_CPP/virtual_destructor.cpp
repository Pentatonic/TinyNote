#include <iostream>

using namespace std;

class B1 {
public:
    B1(int x) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~B1() {
        cout << __PRETTY_FUNCTION__ << endl;
    };
};

class D1 : public B1 {
public:
    D1() : B1(0) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~D1() {
        cout << __PRETTY_FUNCTION__ << endl;
    };
};

class B2 {
public:
    B2(int x) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual ~B2() {
        cout << __PRETTY_FUNCTION__ << endl;
    };
};

class D2 : public B2 {
public:
    D2() : B2(0) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~D2() {
        cout << __PRETTY_FUNCTION__ << endl;
    };
};

int main(int argc, char **argv)
{
    // this won't call derived class's dectructor
    B1 *b1 = new D1();
    delete b1;

    cout << "=============" << endl;

    B2 *b2 = new D2();
    delete b2;

    return 0;
}

