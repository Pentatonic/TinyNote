#include <iostream>
#include <climits>
#include <vector>

using namespace std;


class Ex {};

class A {
    public:
        A() {}
        ~A() {
            throw Ex();
        }
};

class B {
    public:
        B() {}
        ~B() {
            throw 42;
        }
};


int main(int argc, const char * argv[]) {
    try {
        A a;
        //throw 32;
    }
    catch(Ex e) {
        std::cout << "line:" << __LINE__ << ", Ex" << endl;
    }
    catch(int a) {
        std::cout << "line:" << __LINE__ << ": " <<  a << endl;
    }

    std::cout << "-------------" << endl;

    // this will crash, throw another exception during the exception handling 
    try {
        B b;
        throw 32;
    } catch(int a) {
        std::cout << "line:" << __LINE__ << ": " <<  a << endl;
    }
}

