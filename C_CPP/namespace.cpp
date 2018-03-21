#include <iostream>

using namespace std;

namespace a {
    namespace b {
        int x = 87;
    };
};

namespace my {
    class MyClass {
        public:
            void talk() {
                cout << "kwkwkw" << endl;
            };
    };
};

using namespace my;

int main(int argc, char **argv)
{
    MyClass c;
    c.talk();
    cout << a::b::x << endl;
    return 0;
}

