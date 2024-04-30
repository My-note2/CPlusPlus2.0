#include <iostream>

using namespace std;

// final关键字用于两个地方
// 第一个用在类，用于说明该类是继承体系下最后的一个类，不要其它类继承我，如果有继承时会报错
class Base final {
    public:
        Base() {}

        virtual void Func() {}
};

//void Derivered : public Base { // ERROR!!!
//}

// 第二个用在虚函数，表示这个虚函数不能再被override了，不然会报错
class Base1 {
    public:
        Base1() {}

        virtual void Func() final {}
};

class Derivered1 : public Base1 {
    // virtual void Func() {}  // ERROR!!!
};

int main()
{
    return 0;
}