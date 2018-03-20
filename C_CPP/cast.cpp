#include <iostream>
#include <typeinfo>
#include <new>
using namespace std;

class Base {
public:
    virtual void talk() { cout << __PRETTY_FUNCTION__ << endl; }
    //void talk() { cout << __PRETTY_FUNCTION__ << endl; }
    void talk2() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Derived : public Base {
public:
    void talk() { cout << __PRETTY_FUNCTION__ << endl; }
    void talk2() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main(int argc, char **argv)
{
    int i1 = 10;
    double d1 = 3.14;

    cout << i1 / 3 << endl;
    cout << (double) i1 / 3 << endl; // C-style
    cout << static_cast<double>(i1) / 3 << endl;

    Base *base = new Base();
    Derived *derived= new Derived();

    // static_cast
    // happens at compile time
    {
        cout << "static_cast:" << endl;
        derived->talk();
        derived->talk2();
        static_cast<Base *>(derived)->talk();
        static_cast<Base *>(derived)->talk2();
        // 
        static_cast<Derived *>(base)->talk();
        static_cast<Derived *>(base)->talk2();
        // !!!, simulate invoking static member,
        // this is undefined behavior, although g++ makes it works.
        // static_cast<Derived *>(NULL)->talk(); 
    }

    // dynamic_cast
    // happens at run-time
    {
        cout << "dynamic_cast:" << endl;
        cout << dynamic_cast<Base *>(derived) << endl;
        cout << dynamic_cast<Derived *>(base) << endl; // fail, return NULL
        try {
            Base bb = dynamic_cast<Base &>(*derived);
            cout << "Cast to base ok" << endl;
        }
        catch(bad_cast e) {
            cout << "Cast to base fail" << endl;
        }
        try {
            // fail
            // cast to reference will throw exception
            Derived dd = dynamic_cast<Derived &>(*base);
            cout << "Cast to derived ok" << endl;
        }
        catch(bad_cast e) {
            cout << "Cast to derived fail" << endl;
        }
    }

    // reinterpret_cast
    // happens at compile time
    {
        cout << "reinterpret_cast:" << endl;
        {
            /*
            static_casting a pointer to and from void*
            preserves the address. That is, in the following,
            a, b and c all point to the same address:
            */
            int* a = new int();
            void* b = static_cast<void*>(a);
            int* c = static_cast<int*>(b);
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout << "c: " << c << endl;
        }

        {
            int* a = new int();
            void* b = reinterpret_cast<void*>(a); // this may differ on other system
            int* c = reinterpret_cast<int*>(b);
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout << "c: " << c << endl;
        }
    }

    // const_cast
    {
    }
    delete base;
    delete derived;

    return 0;
}
