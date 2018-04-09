#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int cmp(int a, int b) {
    return b < a;
}
// --std=c++11
int main() {
    vector<int> vec = {1,3,5,7,2,4,6,8};
    cout << "before: ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());
    cout << "ascending: ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end(), cmp);
    cout << "descending: ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
