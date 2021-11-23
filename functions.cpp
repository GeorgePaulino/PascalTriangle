/**
 * @file functions.cpp
 * @brief Some functions to return calculated values.
 * 
 */

#include"functions.hpp"

unsigned long long int Factorial(int n)
{ 
    unsigned long long int f = 1;
    for(unsigned long long int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int Binomial(int r, int c)
{
    return Factorial(r) / (Factorial(c) * Factorial(r - c));
}