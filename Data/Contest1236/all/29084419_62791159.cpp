/* 	* Author: ReSi
 	* Time: 2019-10-17 17:17:03
**/

#include <bits/stdc++.h>

using namespace std;

#define mP make_pair
#define ll long long
#define pB push_back
#define X first
#define Y second

const ll MOD = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll y) 
{ 
    ll res = 1;
    while (y > 0) { 
        if (y & 1) {
            res = res * x; 
            res %= MOD;
        }
  
        y = y >> 1; // y = y/2 
        x = x * x; // Change x to x^2 
        x %= MOD;
    } 
    return res; 
} 

int main(){
	ll n, m;
	cin >> n >> m;
	ll ans = 1;

	ans = power(2 , m) - 1;
	ans %= MOD;

	ans = power(ans, n);
	ans %= MOD;
	if(ans < 0) ans += MOD;

	cout << ans << endl;

	return 0;
}
