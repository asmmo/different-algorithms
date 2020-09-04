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
    std::list<unsigned int> ls;
    auto res = x;
    for(;y > 1; y/=2){
        if (y  % 2 == 1) ls.push_back( res );
        res *= res;
    }
    return std::accumulate(ls.begin(), ls.end(), res, [](unsigned int l, unsigned int r){return l * r;}) ;
}
