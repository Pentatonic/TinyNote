#include <iostream>

using namespace std;

class C
{
public:
    void foo() const
    {
        x = 1; // modify in a const member function
        cout << __PRETTY_FUNCTION__ << endl;
    };

    mutable int x;
    //int x;
};

const struct
{
    int x1;
    mutable int x2; // mutable member in a const object
} x = {0, 0};

int main(int argc, char **argv)
{
    C c;
    c.foo();

    //x.x1 = 1; // error, cannot modify
    x.x2 = 2;
    return 0;
}

