#include <iostream>

// Return by value - RVO Return Value Optimization:
// That local variable is about to go out of scope, the compiler will move it, not copy it.
// 编译器明确知道函数会返回哪一个局部对象 那么编译器会把存储这个局部对象的地址和存储返回值临时对象的地址进行复用 也就是说避免了从局部对象到临时对象的拷贝操作
// https://www.jianshu.com/p/dcd3390c5c84

using namespace std;

class A {
public:
    int stored;
    A() { cout << "default constructor called" << endl; }
    A(int i) : stored(i) { cout << i << "constructor called" << endl; }
    A(const A &a) : stored(a.stored) { cout << a.stored << "copy constructor called" << endl; }
    A &operator=(const A &a) {
        cout << a.stored << "operator= called" << endl;
        stored = a.stored;
        return *this;
    }
    ~A() { cout << stored << "destructor called" << endl; }
};

// func: RVO enabled
A func(A a) {
    //a.stored = 3;
    A b(2);
    cout << "address of b: " << &b << endl;
    //return 2;
    return b;   // Why not call copy constructor when return copied to a temp instance?
}

// func2: RVO avoided
A func2(A a) {
    //a.stored = 3;
    A b(2);
    cout << "address of b: " << &b << endl;
    if (a.stored > 0) {
        return b;
    } else {
        A c;
        return c;
    }
}

int main() {
    cout << "Start!" << endl;
    A a(1);
    /****** RVO enabled ******/
/*  RVO - 把要返回的局部变量直接构造在临时对象所在的区域  */
    A b = func(a);  // Why not call copy constructor 2 times: local (return) copied to temp & temp copied to b? BOTH optimized.
    //const A &b = func(a);
    cout << "address of b: " << &b << endl;
    cout << endl;
    b = func(a);
    cout << "address of b: " << &b << endl;
    cout << endl;

    /****** RVO disabled ******/
    A c = func2(a); // Call copy constructor only 1 time here: local copied to temp
    cout << "address of c: " << &c << endl;
/*  另外的优化 - 把c的存储区域作为临时对象的区域  */
/*  Output:
    1copy constructor called      // func2的局部对象a
    2constructor called           // func2的局部对象b
    address of b: 0x7ffee5d39900
    2copy constructor called      // func2的局部对象b->临时对象 即c
    2destructor called            // func2的局部对象b析构
    1destructor called            // func2的局部对象a析构
    address of c: 0x7ffee5d39998
*/
    cout << endl;
    c = func2(a);
    cout << "address of c: " << &c << endl;
/*  Output:
    1copy constructor called      // func2的局部对象a
    2constructor called           // func2的局部对象b
    address of b: 0x7ffee5d39900
    2copy constructor called      // func2的局部对象b->临时对象
    2destructor called            // func2的局部对象b析构
    2operator= called             // 临时对象->c
    2destructor called            // 临时对象析构
    1destructor called            // func2的局部对象a析构
    address of c: 0x7ffee5d39998
*/
    cout << "End!" << endl;
    return 0;
}
