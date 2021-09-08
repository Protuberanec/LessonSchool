#include <stdio.h>
#include <iostream>


class TestClass
{
private:
    int a;
public:
    TestClass() : a(0) {
        printf("TestClass: default constructor %d\n", 0);
    }
    TestClass(const int a) : a(a) {
        printf("TestClass: constructor %d\n", a);
    }
    TestClass(const TestClass& other) : a(other.a) {
        printf("TestClass: copy constructor %d\n", a);
    }
    TestClass(TestClass&& other) : a(std::move(other.a)) {
        printf("TestClass: move constructor %d\n", a);
    }
    ~TestClass() {printf("TestClass: destructor %d\n", a);}
};

using namespace std;
int main()
{
    const int SIZE_AR = 10;
    int tempAr[SIZE_AR];

    int i = 0;
    for (i = 0; i < SIZE_AR; i += 1 /* i++ */) {
        tempAr[i] = i;
    }

    for (int i = 0; i < SIZE_AR; i += 1 /* i++ */) {
        cout << tempAr[i] << " ";
    }

    cout << endl;

    return 0;
}