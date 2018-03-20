#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char **argv)
{
    // underflow, these have equal result
    cout << 25u - 50 << endl;
    cout << UINT_MAX - 24<< endl;

    cout << "INT:" << endl;
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;

    cout << "UINT:" << endl;
    cout << UINT_MAX << endl;

    cout << "LONG:" << endl;
    cout << LONG_MIN << endl;
    cout << LONG_MAX<< endl;
    return 0;
}
