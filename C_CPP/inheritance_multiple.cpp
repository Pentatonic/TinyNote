#include <iostream>
#include <climits>

using namespace std;

class Bear {
    public:
        void talk() {
            cout << __PRETTY_FUNCTION__ << endl;
        };
};

class BlackBear : public Bear {
    public:
        void talk() {
            cout << __PRETTY_FUNCTION__ << endl;
        };
};


class WhiteBear : public Bear {
    public:
        void talk() {
            cout << __PRETTY_FUNCTION__ << endl;
        };
};



class Panda : public WhiteBear, public BlackBear {
    public:
        /*
           void talk() {
           cout << __PRETTY_FUNCTION__ << endl;
           };
         */
};

int main(int argc, char **argv)
{
    Bear bear;
    BlackBear bBear;
    WhiteBear wBear;
    bear.talk();
    bBear.talk();
    wBear.talk();
    // Diamond inheritance
    // Ambiguos, cannot compile.
    Panda panda;
    panda.talk();
    return 0;
}
