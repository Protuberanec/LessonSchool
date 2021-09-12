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
void cycle() {
    for (int i = 10; i < 10; i++) {
        cout << i << " ";
    }

    cout << endl;

    cout << " while" << endl;
    int i = 10;
    while(i < 10) {
        cout << i << " ";
        i++;
    }
    cout << "\ndo while" << endl;
    i = 10;
    do {
        cout << i << " ";
        i++;
    } while(i < 10);
}
int main()
{
    int indMax = 0;
    int indMin = 0;

    int a1 = 10;
    int b1 = 20;

    cout << "a1 = " << a1 << " b1 = " << b1 << endl;

    int temp = a1;
    a1 = b1;
    b1 = temp;
//    a1 = a1 + b1;
//    b1 = a1 - b1;
//    a1 = a1 - b1;

    cout << "a1 = " << a1 << " b1 = " << b1 << endl;

    int a[10] = {90, 89, 200, 100, 90, 24, 15, 89, 150, 99};
    for (int j = 0; j < 10; j++) {
        indMin = j;
        for (int i = j; i < 10; i++) {
            if (a[indMin] > a[i]) {
                indMin = i;
            }
        }
        int t = a[indMin];
        a[indMin] = a[j];
        a[j] = t;
    }

    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }


    return 0;
}