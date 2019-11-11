#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
using namespace std;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
typedef pair <long long,long long> ii;
// typedef complex<long double> point;
ll mod = 1e9+7;
ll power(ll x, ll y) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % mod;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % mod; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % mod;   
    } 
    return res; 
} 

vector <ll> pre;


ll calc(ll count){
	ll ans = 1;
	ll k = count-1;
	ll c = 1;
	while (count-2 >= 0){
		ans += ((pre[k]*power(pre[count-2],mod-2))%mod)*power(pre[c],mod-2);
		ans %= mod;
		count -= 2;
		k--;
		c++;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin >> s;
	ll n = s.size();
	pre.resize(n+1);
	pre[1] = 1;
	pre[0] = 1;
	for (int z=2;z<=n;z++){
		pre[z] = pre[z-1]*z;
		pre[z] %= mod;
	}
	for (int z=0;z<n;z++){
		if (s[z] == 'm' || s[z] == 'w'){
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans = 1;
	for (int z=0;z<n;z++){
		if (s[z] == 'u' || s[z] == 'n'){
			char prev = s[z];
			ll count = 0;
			for (;z<n;z++){
				if (s[z] == prev){
					count++;
				} else if (s[z] != prev && (s[z] == 'u' || s[z] == 'n')){
					if (count >= 2){
						ll k = calc(count);
						ans *= k;
						ans %= mod;
					}
					count = 1;
					prev = s[z];
				} else {
					if (count >= 2){
						ll k = calc(count);
						ans *= k;
						ans %= mod;
					}
					count = 0;
					break;
				}
			}
			if (count >= 2){
				ll k = calc(count);
				ans *= k;
				ans %= mod;
			}
		}
	}
	cout << ans << endl;
}
 
 