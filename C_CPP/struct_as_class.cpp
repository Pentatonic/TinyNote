#include <iostream>

using namespace std;

struct B
{
    static const int val = 87;
    virtual void talk() { cout << __PRETTY_FUNCTION__ << endl; };
};

struct D : public B
{
    void talk() { cout << __PRETTY_FUNCTION__ << endl; };
};

int main(int argc, char **argv)
{
    B *b = new D();
    b->talk();

    cout << D::val << endl;
    return 0;
}
