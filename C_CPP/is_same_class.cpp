#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// Using partial template specialization
template <typename A, typename B>
struct is_same
{
    static const bool value = false;
};

template <typename A>
struct is_same <A, A>
{
    static const bool value = true;
};


//template <typename A, typename B>
template <class A, class B>
bool IsSameClass()
{
    return is_same<A, B>::value;
}

class C1 {};
class C2 {};

int main(int argc, char **argv)
{

    cout << IsSameClass<C1, C2>() << endl;
    cout << IsSameClass<C1, C1>() << endl;
    cout << IsSameClass<C2, C2>() << endl;
    return 0;
}
