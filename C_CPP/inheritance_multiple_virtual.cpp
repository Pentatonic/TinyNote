#include <iostream>

using namespace std;

class Bear {
    public:
        void talk() {
            cout << __PRETTY_FUNCTION__ << endl;
        };
};

class BlackBear : virtual public Bear {
};


class WhiteBear : virtual public Bear {
};



class Panda : public WhiteBear, public BlackBear {
};

int main(int argc, char **argv)
{
    Bear bear;
    BlackBear bBear;
    WhiteBear wBear;

    // Diamond inheritance
    // DDD problem (Dreadful Diamond on Derivation)

    // add virtual will find the correct method
    Panda panda;
    panda.talk();
    return 0;
}
