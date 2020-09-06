//c++17 at least  https://godbolt.org/z/MrvWY6
#include <iostream>
#include <array>
#include <limits>

template <uint32_t n>
struct Fib
{

    constexpr static uint64_t recursiveExponentialFib()
    {
        if constexpr (n < 2) return n;
        else return Fib<n-1>::recursiveExponentialFib() + Fib<n-2>::recursiveExponentialFib();
    }


    constexpr static uint64_t linearFib()
    {
        if constexpr (n < 2) return n;
        uint64_t array [] {0, 1, 1};
        for (size_t i {2}; i <= n; ++i) {
            array[2] = array[1] + array[0];
            array[0] = array[1];
            array[1] = array[2];
        }
        return array[2];
    }
private:
    using Row = std::array<uint64_t,2>;
    using Mat = std::array<Row,2>;

    constexpr static Mat muliplyMats(const Mat & lhs, const Mat & rhs)
    {
        return Mat{
            Row{lhs[0][0]*rhs[0][0]+lhs[0][1]*rhs[1][0],
            lhs[0][0]*rhs[0][1]+lhs[0][1]*rhs[1][1]},
            Row{lhs[1][0]*rhs[0][0]+lhs[1][1]*rhs[1][0],
            lhs[1][0]*rhs[0][1]+lhs[1][1]*rhs[1][1]}
            };
    }

    template<uint32_t m = n>
    constexpr static Mat power(Mat X)
    {
        if constexpr (m == 0) return Mat{Row{1,0}, Row{0, 1}}; //the identity matrix
        else if constexpr (m == 1) return X;
        else
        {
            auto temp = power<m/2>(X);
            if constexpr (m % 2 == 0) return muliplyMats(temp, temp);
            else return muliplyMats(muliplyMats(temp, temp),  X);
        }
    }
public:
    template<uint32_t m = n>
    constexpr static uint64_t logFib()
    {
        if (m < 2) return m;
         auto X = Mat{Row{0, 1}, Row{1, 1}}; //matrix or 2d array
         auto temp = power<m>(X);
         return temp[0][1]; //note that the indices start from 0
    }



};



int main(){


    std::cout
            << Fib<9>::recursiveExponentialFib()
              << " " << Fib<9>::linearFib()
              << " " << Fib<9>::logFib()
              << " " << Fib<std::numeric_limits<uint32_t>::max()>::logFib();
}
