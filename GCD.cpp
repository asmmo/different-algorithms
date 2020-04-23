#include <iostream>

//Euclid's algorithm O(log(N))
long long gcd( long long m, long long n )
{
    if ( m < n ) return gcd(n, m);
    while( n != 0 )
    {
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}


int main(){
    std::cout <<gcd(2,30);
}
