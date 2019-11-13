/**
	WGkKWGkF
	@author: harshkirat2
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define psb push_back
#define ppb pop_back
#define mkp make_pair
#define fst first
#define scd second
#define ins insert
#define psf push_front
#define ppf pop_front
//#define MAXN 1001
//#define modv 1000000007
using namespace std;
/*//Power Template
ll modExp(ll a, ll b, ll c) {
	a %= c;
	ll ans = 1;
	for(; b; b >>= 1) {
		if(b & 1){
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;
	}
	return ans;
}
ll fastExp(ll a, ll b) {
	ll ans = 1;
	for(; b; b >>= 1) {
		if(b & 1)
			ans *= a;
		a *= a;
	}
	return ans;
}
*/
/*//Factorial Template
ll fact[MAXN];
void factorialBoot(ll p){
	ll i;
	fact[0] = 1;
	for(i = 1; i < MAXN; i++)
		fact[i] = fact[i-1] * i % p;
}
ll nCr(ll n, ll r, ll p) {
	if(r < 0 || r > n)
		return 0;
	return fact[n] * modExp(fact[r] * fact[n - r] % p, p - 2, p);
}
*/
/*//primiality Template
bool isPrime(ll n) {
    if (n < 2)
		return false;
    if (n < 4)
		return true;
    if (n % 2 == 0 || n % 3 == 0)
		return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i+2) == 0)
           return false;
    return true;
}
ll eulerTotient(ll n) {
    ld result = n;
    for(ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
         	while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (ld)p));
        }
    }
    if (n > 1)
        result *= (1.0 - (1.0 / (ld)n));
    return (ll)result;
}
map<ll, ll> primeFactoriseMap(ll n) {
	map<ll, ll> a;
	if(n == 1)
		return a;
	ll i, x = 0;
	while((n & 1) == 0) {
		x++;
		n >>= 1;
	}
	if(x) {
		a[2] = x;
		x = 0;
	}
	while(n % 3 == 0) {
		x++;
		n /= 3;
	}
	if(x) {
		a[3] = x;
		x = 0;
	}
	for(i = 5; i * i <= n; i += (2<<(i % 6 == 1))) {
		while(n % i == 0) {
			x++;
			n /= i;
		}
		if(x) {
			a[i] = x;
			x = 0;
		}
	}
	if(n > 1)
		a[n] = 1;
	return a;
}
vector<pair<ll, ll> > primeFactorisePairVector(ll n) {
	vector<pair<ll, ll> > a;
	if(n == 1)
		return a;
	ll i, x = 0;
	while((n & 1) == 0) {
		x++;
		n >>= 1;
	}
	if(x) {
		a.push_back({2, x});
		x = 0;
	}
	while(n % 3 == 0) {
		x++;
		n /= 3;
	}
	if(x) {
		a.push_back({3, x});
		x = 0;
	}
	for(i = 5; i * i <= n; i += (2<<(i % 6 == 1))) {
		while(n % i == 0) {
			x++;
			n /= i;
		}
		if(x) {
			a.push_back({i, x});
			x = 0;
		}
	}
	if(n > 1)
		a.push_back({n, 1});
	return a;
}
*/
/*//string template
bool isPalindrome(string s) {
	ll n = s.length();
	ll ub = n / 2;
	for(ll i = 0; i < ub; i++)
		if(s[i] != s[n-1-i])
			return false;
	return true;
}
vector<pair<char, ll> > clubConsecutiveSameChar(string s) {
	vector<pair<char, ll> > a;
	ll i, ub = s.length();
	if(ub == 0)
		return a;
	a.push_back({s[0], 1});
	for(i = 1; i < ub; i++)
		if(s[i] == s[i-1])
			a.back().second++;
		else
			a.push_back({s[i], 1});
	return a;
}
*/
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t,a,b,c,x,y,ms;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ms=0;
		for(x=0;x<=a;x++)
			ms = max(ms, x + min(b-(x<<1), c>>1));
		cout<<3*ms<<"\n";
	}
	return 0;
}
