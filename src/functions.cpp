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

        //Loop to find prime factors of n.
        for (int i = 1; i <= std::sqrt(n); i++) {
            if (n % i == 0 && is_prime(i)) {
                prime_factors.push_back(i);
            }
        }

        //Sort vector to find max value (in descending order).
        std::sort(prime_factors.begin(), prime_factors.end());

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