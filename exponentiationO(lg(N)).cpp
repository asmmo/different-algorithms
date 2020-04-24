#include <iostream>

//Exponentiation algorithm O(log(N))
long long pow( long long x, int n )
{
    if( n == 0 ) return 1;
    if( n % 2 == 0 ) return pow( x * x, n / 2 );
    else return pow( x * x, n / 2 ) * x;
}


int main(){
    std::cout << pow( 2, 15 ) / 2 - pow( 2, 14 );
}
