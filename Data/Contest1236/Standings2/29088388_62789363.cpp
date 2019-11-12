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


int binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			{res *= a; res%=1000000007;}
		a *= a;
		a%=1000000007;
		n >>= 1;
	}
	return (res % 1000000007);
}

int main() {
ll a , b;
cin>>a>>b;



ll sh = (binpow ( 2 , b ) -1) % 1000000007 ;

cout << binpow(sh , a);


}
