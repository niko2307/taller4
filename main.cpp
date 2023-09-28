#include <ctime>
#include <cmath.h>
#include <iostream>

using namespace std;

int main () {
std::clock_t init_time = std::clock( );
int freq = 99998;
for ( int i=2; i<=n; ++i )
for ( int j=sqrt(i); j>1; --j )
if ( i%j==0 ) {
--freq;
break;
}
std::clock_t end_time = std::clock( );
cout << "The number of primes lower than 100000 is: " << freq << endl;
double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
cout << " It took me "<< calc_time << "seconds.\n";
return 0;


}
