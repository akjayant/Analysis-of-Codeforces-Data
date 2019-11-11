#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll ct;
ll dp[N];

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll sub(ll a, ll b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}
ll divi(ll a, ll b){
    return(mul(a, power(b, MOD - 2)) % MOD);
}

ll go(ll idx){
	if(idx == ct) return 1;
	if(idx > ct) return 0;
	ll &ans = dp[idx];
	if(ans != -1) return ans;
	ans = 0;
	ans = ad(ans, go(idx + 1));
	ans = ad(ans, go(idx + 2));
	return ans;
}


int main(){
	fast;
	string s;
	cin >> s;
	ll pt = 0;
	ll res = 1, ok = 0;
	memset(dp, -1, sizeof dp);
	while(pt != s.size()){
		ct =  0;
		ll fl = 0;
		if(s[pt] == 'w' || s[pt] == 'm'){
			ok = 1;
			break;
		}
		while(pt != s.size() && s[pt] == 'u'){
			pt++;
			ct++;
			fl = 1;
		}
		if(fl) pt--;
		fl = 0;
		while(pt != s.size() && s[pt] == 'n'){
			pt++;
			ct++;
			fl = 1;
		}
		if(fl) pt--;
		if(ct){
			res = mul(res, go(0));
		}
		for(int i = 0; i < ct + 3; i++) dp[i] = -1;
		pt++;
	}
	//cout << ok << endl;
	if(ok) res = 0;
	cout << res ;

	
	
	return 0;
}
