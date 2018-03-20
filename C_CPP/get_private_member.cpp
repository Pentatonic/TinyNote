#include <string>
#include <iostream>

class Something {
    public:
        Something() {
            topSecretValue = 42;
        }
        bool somePublicBool;
        int somePublicInt;
        std::string somePublicString;
    private:
        int topSecretValue;
};

class Replica {
    public:
        int getTopSecretValue() {
            return topSecretValue;
        }
        bool somePublicBool;
        int somePublicInt;
        std::string somePublicString;
    private:
        int topSecretValue;
};

int main() {
    Something thing;
    Replica *rep = reinterpret_cast<Replica *>(&thing);
    std::cout << rep->getTopSecretValue() << std::endl;
}
