#include <iostream>

void SwapMethod1(int &a, int &b){
    //The idea is using another variable to keep one of two value
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1, b = 2;
    //Print two value
    std::cout << "a = " << a << " and b = " << b;

    //Method 1
    SwapMethod1(a, b);

    //Print result
    std::cout << "a = " << a << " and b = " << b;

    return 0;
}