// Call-by-Value: In this method, a copy of the actual parameter's value is passed to the function.
// Any changes made to the parameter inside the function will not affect the original value outside the function.
// Call-by-Reference: In this method, instead of passing a copy of the value, the address (reference) of the
//actual parameter is passed to the function. Therefore, any changes made to the parameter inside the function
//will affect the original value outside the function.
// Here's a code example in C++ demonstrating both concepts:


#include <iostream>
using namespace std;

// Function to demonstrate call-by-value
void incrementByValue(int num) {
    num += 1;
    cout << "Inside incrementByValue: " << num << endl;
}

// Function to demonstrate call-by-reference
void incrementByReference(int &num) {
    num += 1;
    cout << "Inside incrementByReference: " << num << endl;
}

int main() {
    int value = 5;

    cout << "Original value: " << value << endl;

    // Call-by-value
    incrementByValue(value);
    cout << "After calling incrementByValue: " << value << endl;

    // Call-by-reference
    incrementByReference(value);
    cout << "After calling incrementByReference: " << value << endl;

    return 0;
}
