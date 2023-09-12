#include "include/functions.h"
#include <iostream>

/*
The number 13195 consists of the prime factors 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?
*/

int main() {
    std::cout << "The largest prime factor of 600851475143 is: " << '\n';
    std::cout << func::max_prime_factor(600851475143) << '\n';

    return 0;
}