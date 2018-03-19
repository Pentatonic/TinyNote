#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// https://stackoverflow.com/questions/39467087/implement-a-template-function-that-takes-two-classes-as-template-parameters-and

template<typename D, typename B>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };

    static Yes Test(B *);
    static No Test( ... );
public:
    enum {
        Is = sizeof(Test(static_cast<D *>(0))) == sizeof(Yes)
    };
};

template<class D, class B>
bool IsDerivedFrom()
{
    return IsDerivedFromHelper<D, B>::Is;
}

class Base {};
class Derived : public Base {};
class Another {};

int x(int);
char x(double);
long x();

int main(int argc, char **argv)
{
    // sizeof function return type
    cout << sizeof(x(1)) << endl;
    cout << sizeof(x(1.0)) << endl;
    cout << sizeof(x()) << endl;

    cout << "----------" << endl;

    cout << IsDerivedFrom<Derived, Base>() << endl;
    cout << IsDerivedFrom<Base, Derived>() << endl;
    cout << IsDerivedFrom<Another, Base>() << endl;
    return 0;
}
