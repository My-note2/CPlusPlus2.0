//
// Created by wangzhen on 2022-11-03
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>

using namespace std;


class C
{
public:
    C(const string &s) : mystr(s) {

    }

    friend ostream &operator<<(ostream out, const C &c)
    {
        out << c.mystr << endl;
    }
private:
    string mystr;
};

int main(void)
{
    cout << "Hello VSCode!" << endl;

    auto i = 42;    //编译器具备实参推导

    auto ll1 = [](int x) -> int
    {
        return x + 10;
    };

    //lambda 匿名函数
    function<int(int x)> ll = [](int x) -> int
    {
        return x + 10;
    };

    cout << ll(10) << endl;
    list<int> l{1, 2, 3};
    list<int>::iterator iterator;
    //iterator = find(l.begin(), l.end(), 10);

    //auto ite = find(l.begin(), l.end(), 11);    // auto关键字

    vector<int> vec;
    //==============range-based for statement===============
    // (1)
    for(auto elem:vec) // pass by value
    {
        cout << elem << endl;
    }
    // c++2.0之前 (2) 编译器会把(1)转换为(2)或(3)
    for(auto _pos = l.begin(), _end = l.end(); _pos != _end; ++_pos)
    {
        cout << *_pos << " ";
    }
    cout << endl;
    // (3)
    // c++2.0 之后 全局函数begin(Container)与end(container)可以接受容器
    for(auto _pos = begin(l), _end = end(l); _pos != _end; ++_pos)
    {
        cout << *_pos << " ";
    }
    cout << endl;
    // (4)
    for(auto &elem:vec) // pass by reference
    {
        elem *= 3;
    }
    // (5) 编译器会把(4)转换为(5)
    for(auto _pos = l.begin(), _end = l.end(); _pos != _end; ++_pos)
    {
        auto &elem = *_pos;
        elem *= 3;
    }
    cout << endl;

    vector<string> vs = {"hello", "world"};
    // 加了explicit就不能转了 error
    for(const C &elem:vs)
    {
    }
    // auto 不利：降低代码可读性、可能得不到你预想的类型、配合decltype有意想不到的结果
    // auto可能得不到你预想的类型，如vector<bool>[]的返回类型。
    vector<bool> v(true);
    auto var = v.at(0);
    cout << typeid(var).name() << endl;
    return 0;
}