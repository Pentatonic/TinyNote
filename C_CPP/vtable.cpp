#include <iostream>

//class A
struct A
{
//public:
    int data[2];

    A(int x, int y) : data{x, y} {}
    virtual void f() {}
};

//class B
struct B
{
//public:
    int data[2];

    B(int x, int y) : data{x, y} {}
    void f() {}
};

int main(int argc, char **argv)
{
    A a(22, 33);
    B b(22, 33);

    int *arr = (int *) &a;
    std::cout << "With vtable:" << std::endl;
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;
    std::cout << std::endl;


    arr= (int *) &b;
    std::cout << "Without vtable:" << std::endl;
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;

    return 0;
}
