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
    
    auto l = lower_bound(vec.begin(), vec.end(), 2);
    cout << "lower_bound binary search 2 and insert -1 before 2, found " << *l << endl;
    vec.insert(l, -1);
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    auto u = upper_bound(vec.begin(), vec.end(), 2);
    cout << "upper_bound binary search 2 and insert -2 after 2, found " << *u << endl;
    cout << *u << endl;
    vec.insert(u, -2);
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

