#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Example
{
public:
    explicit Example(string name) { this->name = name; }
    ~Example() {};
public:
    string name;
    int num = 0;
    int array[3] = {1,2,3};
    string str = "?";
    string *p = &str;
};

int main()
{
    Example a("a");
    Example b = a;  // 类的拷贝构造,类的属性依次赋值,属性中的普通数据类型正常(包括数组),属性中的指针指向同个内存地址
    b.name = "b";

    a.num = 1;
    b.num = 2;
    a.array[0] = 0;
    *(a.p) = "it's_a";
    *(b.p) = "it's_b";

    Example c("c");
    c = a;  // 类的赋值,类的属性依次赋值,属性中的普通数据类型行为正常(包括数组),属性中的指针指向同个内存地址
    c.array[2] = 5;

    printf("name=%s; num=%d; array=%d,%d,%d; *p=%s\n", a.name.c_str(), a.num, a.array[0], a.array[1], a.array[2], (*(a.p)).c_str());
    printf("name=%s; num=%d; array=%d,%d,%d; *p=%s\n", b.name.c_str(), b.num, b.array[0], b.array[1], b.array[2], (*(b.p)).c_str());
    printf("name=%s; num=%d; array=%d,%d,%d; *p=%s\n", c.name.c_str(), c.num, c.array[0], c.array[1], c.array[2], (*(c.p)).c_str());

    return 0;
}
