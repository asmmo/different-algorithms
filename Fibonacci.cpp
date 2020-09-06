//c++20
#include <iostream>
#include <array>

template <uint32_t n>
struct Fib
{

    template<int m =n>
    constexpr static uint64_t exponentialFib()
    {
        if constexpr (m < 2) return m;
        else return exponentialFib<m-1>() + exponentialFib<m-2>();
    }


    constexpr static uint64_t linearFib()
    {
        if constexpr (n < 2) return n;
        std::array<uint64_t , 3> array{0, 0, 1};
        for (size_t i {2}; i <= n; ++i) {
            array[0] = array[1];
            array[1] = array[2];
            array[2] = array[1] + array[0];
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
        if constexpr (m == 1) return X;
        else
        {
            auto temp = power<m/2>(X);
            if constexpr (n % 2 == 0) return muliplyMats(temp, temp);
            return muliplyMats(muliplyMats(temp, temp),  X);
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

    std::cout << Fib<8>::exponentialFib() << " " << Fib<8>::linearFib() << " " << Fib<8>::logFib();
}
