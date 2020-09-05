#include <iostream>
#include <list>
#include <numeric>

long long recursivePowi(unsigned int x, unsigned int y){
    if(!y) return 1;
    auto temp = recursivePowi(x, y/2);
    if(y % 2 == 0) return temp * temp;
    return temp * temp * x;
}

long long powi(unsigned int x, unsigned int y){
    if (!y) return 1;
    std::list<long long> ls;
    long long res = x;
    for(;y > 1; y/=2){
        if (y  % 2 == 1) ls.push_back( res );
        res *= res;
    }
    return std::accumulate(ls.begin(), ls.end(), res, [](unsigned int l, unsigned int r){return l * r;}) ;
}

int main(){

    unsigned x = 0;
    for(size_t j{}; j<32;++j) x+= powi(2,j);

    unsigned recursiveX = 0;
    for(size_t j{}; j<32;++j) recursiveX+= recursivePowi(2,j);

    std::cout << powi(2, 32) - 1 << "\n" << x << " " << recursiveX << " " << std::numeric_limits<unsigned int>::max();
}
