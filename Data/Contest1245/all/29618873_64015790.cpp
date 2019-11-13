/*input
nnnuuu

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x firstw
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
#define endl '\n'
using namespace std;
// #define int ll
// #pragma GCC optimize("Ofast")

//coding in car is hard
const ll mod = 1e9 + 7;
ll fpow(ll a, ll b){ //a ^ b
    if(b == 1)
        return (a % mod);

    ll pow = fpow(a, b / 2);
    ll rez = (pow * pow) % mod;

    if(b % 2 == 1)
        rez = (rez * a) % mod;

    return rez;
}

ll inverse(ll b){
    return fpow(b, mod - 2);
}
ll dv(ll a, ll b){
    return (a * inverse(b)) % mod;
}


const int maxn = 1e5 + 10;
ll fact[maxn] = {1};
ll C(ll n, ll k){
	return dv(fact[n], (fact[k] * fact[n - k]) % mod);
}
int32_t main(){

	for(int i = 1; i < maxn; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}

	string s;
	cin >> s;

	ll n = s.size();
	ll ans = 1;

	for(int i = 0; i < n; i++){
		if(s[i] == 'n' || s[i] == 'u'){
			char t = s[i];
			ll kiek = 0;
			while(i < n && s[i] == t){
				kiek++;
				i++;
			}
			// db(kiek);

			ll vars = 0;
			for(ll lets = (kiek + 1) / 2; lets <= kiek; lets++){
				vars += C(lets, kiek - lets);
				vars %= mod;
			}
			ans *= vars;
			ans %= mod;

			i--;

		}

		if(s[i] == 'm' || s[i] == 'w'){
			ans = 0;
		}

	}

	cout << ans << endl;

}
