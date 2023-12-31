#include "include/functions.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>
#include <iostream>

namespace func {
    int64_t max_prime_factor(int64_t n) {
        //Vector to hold prime factors of n.
        std::vector<int64_t> prime_factors;

        //Special case for 2.
        if (n % 2 == 0) {
            prime_factors.push_back(2);
        }

        //Loop to find prime factors of n.
        for (int i = 3; i <= std::sqrt(n); i+=2) {
            if (n % i == 0 && is_prime(i)) {
                prime_factors.push_back(i);
            }
        }

        //Find max prime factor of n by accessing the last element in prime_factors.
        return prime_factors.back();
    }

    bool is_prime(int64_t n) {
        //Checks if a single signed 64-bit integer is a prime number.
        if (n > std::numeric_limits<int64_t>::max() || n < std::numeric_limits<int64_t>::min()) {
            throw std::invalid_argument("Argument 'n' is out of range for 'int64_t' type.");
        }
        if (n <= 1) {
                return false;
        } else if (n == 2) {
            return true;
        } else if (n > 2 && n % 2 == 0) {
            return false;
        }

        int64_t max_divisor = std::ceil(std::sqrt((long double) n));
        for (int64_t d = 3; d < max_divisor + 1; d+=2) {
            if (n % d == 0) {
                return false;
            }
        }

        return true;
    }
}