
// class Variables:
//behaviour of a class variable when made static and compare it with non static variable c++ along with some code and explanations

// Non-Static Variable:
// When a variable in a class is non-static, each instance (object) of the class has its own copy of that variable. Any modifications to the variable will only affect that particular instance.

#include <iostream>
using namespace std;

class MyClass1 {
public:
    int nonStaticVar;

    MyClass1(int value) {
        nonStaticVar = value;
    }
};


// Static Variable:
// When a variable in a class is static, all instances of the class share the same copy of that variable.
//Any modifications to the variable will affect all instances.


class MyClass2 {
public:
    static int staticVar;

    MyClass2(int value) {
        staticVar = value;
    }
};


int main() {


  MyClass1 obj1(5);
  MyClass1 obj2(10);

  obj1.nonStaticVar = 8;

  cout << "obj1.nonStaticVar: " << obj1.nonStaticVar << endl;
  cout << "obj2.nonStaticVar: " << obj2.nonStaticVar << endl;


  MyClass2 obj3(5);
  MyClass2 obj4(10);

  obj3.staticVar = 8;

  cout << "obj1.staticVar: " << obj3.staticVar << endl;  // Output: 8
  cout << "obj2.staticVar: " << obj4.staticVar << endl;  // Output: 8

  return 0;
}
