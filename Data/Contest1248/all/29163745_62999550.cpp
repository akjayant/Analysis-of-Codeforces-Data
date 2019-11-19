    #include <iostream>
        #include <cstdio>
        #include <map>
        #include <vector>
        #include <algorithm>
        #include <deque>
		#include <cmath>
        #include <set>
        #define ld long double
        #define ll long long
        #define cld const long double
        #define cll const long long

using namespace std;

long long binpow (long long a, long long n) {
	long long res = 1;
	while (n) {
		if (n & 1)
			res = (res*a) % 1000000007;

		a = (a*a) %1000000007;
		n >>= 1;
	}
	return (res%1000000007);
}




 main() {
ll n , m;

cin >> n >> m;

if(n == 1 && m == 1 ) {cout << 2 ;return 0;}
if(m < n) swap(n , m);




const ll M = m ;
ll mas[M];
mas[0] = 1;
mas[1] = 2;
for( ll i = 2 ; i < m ; ++i)
mas[i] = (mas[i-1] + mas[i-2])%1000000007;





cout << 2*( mas[m - 1] + mas[n - 1] - 1 ) % 1000000007;



 }

