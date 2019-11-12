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
int a ; cin >> a;

for(int i = 1 ; i <= a ; ++i)
    {for(int j = 0 ; j < a; ++j)
    {
        if(j%2 == 0) cout << i + j*a << " ";
        else cout << a*(j+1) + 1 - i << " ";
    }

cout << endl;
}

}
