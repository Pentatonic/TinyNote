#include <iostream>

void fun(int x) {
    std::cout << "fun" << x << std::endl;
}

int main() {
    std::cout << main << std::endl;

    // pointer
    {
        char c1= 'x';
        const char c2 = 'x';

        const char *pA = &c2;
        char * const pB = &c1;
        char const *pC = &c2;
        const char* const pD = &c2;

        pA = &c1;
        pA = &c2;
        //pB = NULL; // error
        pC = &c1;
        pC = &c2;
        //pD = NULL; // error
    }

    // function pointer
    {
        void (*p)(int);
        p = fun;
        // both works
        (*fun)(1);
        fun(2);
    }
    return 0;
}

