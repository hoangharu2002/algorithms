#include <iostream>

unsigned int *fi = new unsigned int[100];       //extra array

unsigned int fibo(unsigned int);
unsigned int fibo1(unsigned int);
unsigned int fibo2(unsigned int);
unsigned int fibo3(unsigned int);
unsigned int fibo4(unsigned int);

int main()
{
    int n;
    std::cin >> n;
    std::cout << "So fibo tai vi tri thu " << n << " la: " << fibo(n);
    delete[] fi;
    return 0;
}

unsigned int fibo(unsigned int n)
{
    return fibo1(n);
}

// ver 1: using loop without using array

unsigned int fibo1(unsigned int n)
{

    unsigned int num1 = 1, num2 = 0;

    while (n > 0)
    {
        num2 = num1 + num2;
        num1 = num2 - num1;
        --n;
    }

    return num2;
}

// ver 2: using loop without using array

unsigned int fibo2(unsigned int n)
{
    fi[0] = 0;
    fi[1] = 1;

    for (int i = 2; i < n; ++i)
    {
        fi[i] = fi[i - 1] + fi[i - 2];
    }

    return fi[n - 1];
}

// ver 3: using recursion without extra memory

unsigned int fibo3(unsigned int n)
{
    if (n < 3)
        return n - 1;

    return fibo3(n - 1) + fibo3(n - 2);
}

// ver 4: upgrade recursion with extra memory

unsigned int fibo4(unsigned int n)
{
    // if available
    if (fi[n] > -1)
        return fi[n - 1];

    // if not available
    if (n < 3)
    {
        fi[n - 1] = n - 1;
    }
    else
        fi[n - 1] = fibo4(n - 1) + fibo4(n - 2);

    return fi[n - 1];
}