//at least c++20
//Euclid’s rule If x and y are positive integers with x ≥ y, then gcd(x, y) = gcd(x mod y, y).
//https://godbolt.org/z/Kfbfac
#include <iostream>
#include <concepts>

struct gcd
{

    template <uint64_t m, uint64_t n> requires (n!=0 || m!=0)
    constexpr static uint64_t recursive( )
    {
        if constexpr( n == 0) return m;
        else if constexpr ( m < n ) return recursive<m, n % m>();
        else return recursive<n, m % n>();
    }

    template < uint64_t m, uint64_t n> requires (n!=0 || m!=0)
    constexpr static uint64_t iterative(uint64_t m_ = m, uint64_t n_ = n)
    {

        while( n_ != 0 && m_ != 0 )
        {
            uint64_t rem = m_ % n_;
            m_ = n_;
            n_ = rem;
        }
        return m_;
    }

};



int main(){


    std::cout
//          << " " << gcd::iterative<0, 0>()
            << " " << gcd::iterative<27, 21>()
            << " " << gcd::recursive<27, 21>();
}


/*
after any two consecutive rounds, m and n, are at the very least halved in value (i.e) the length of each decreases by at least one bit. If
they are initially n-bit, then the base case will be reached within 2n iterations. And since the mode is a quadratic-time in bits, the total time is O(n3).
*/
