#include <iostream>

unsigned int fact(unsigned int);
unsigned int fact1(unsigned int, unsigned int = 1);
unsigned int fact2(unsigned int, unsigned int = 1);
unsigned int fact3(unsigned int);
unsigned int fact4(unsigned int);

int main()
{
    unsigned int n;
    std::cout << "Nhap mot so n:";
    std::cin >> n;
    std::cout << "Giai thua cua so vua nhap: " << fact(n);
    return 0;
}

unsigned int fact(unsigned int n)
{
    return fact1(n);
}

// ver 1: tail recursive optimized
unsigned int fact1(unsigned int n, unsigned int f)
{
start:
    // stop condition
    if (n <= 1)
        return f;

    // return fact1(n - 1, f * n);  non-optimized

    f *= n--;   // optimized by compiler
    goto start; //
}

// ver 2: tail recursive non-optimized
unsigned int fact2(unsigned int n, unsigned int f)
{
    // stop condition
    if (n <= 1)
        return f;

    return fact2(n - 1, f * n);
}

// ver 3: non-tail recursive
unsigned int fact3(unsigned int n)
{
    // stop condition
    if (n <= 1)
        return 1;

    return n * fact3(n - 1);
}

// ver 4: using loop
unsigned int fact4(unsigned int n)
{
    unsigned int result = 1;

    while (n > 1)
        result *= n--;

    return result;
}