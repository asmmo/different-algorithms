#include <iostream>
#include <list>
#include <numeric>

uint64_t recursivePowi(uint32_t x, uint32_t y){
    if(!y) return 1;
    auto temp = recursivePowi(x, y/2);
    if(y % 2 == 0) return temp * temp;
    return temp * temp * x;
}

uint64_t powi(uint32_t x, uint32_t y){
    if (!y) return 1;
    std::list<uint64_t> ls;
    uint64_t res = x;
    for(;y > 1; y/=2){
        if (y  % 2 == 1) ls.push_back( res );
        res *= res;
    }
    return std::accumulate(ls.begin(), ls.end(), res, [](uint64_t l, uint64_t r){return l * r;}) ;
}

int main(){

    uint64_t x = 0;
    for(uint32_t j{}; j<32;++j) x+= powi(2,j);

    uint64_t recursiveX = 0;
    for(uint32_t j{}; j<32;++j) recursiveX+= recursivePowi(2,j);

    std::cout << powi(2, 32) - 1 << "\n" << x << " " << recursiveX << " " << std::numeric_limits<uint32_t>::max();
}
