//stack size is 50MB
#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<fstream>
#include<cstring>
#include<list>
#include <queue>

#define fr(j,k) for(int i = 0; i < k; i++)
#define rfr(j,k) for(int i = k; i >= 0; i--)
using ll = long long;
using ull = unsigned long long int;
using ld = long double;
using namespace std;
using vll = vector<ll>;
# define PI acos(ld(-1))
ll egcd(ll a, ll b, ll& x, ll& y) {//ax + by = gcd(a,b)
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll ans = egcd(b, a % b, x, y);
	ll p = x, q = y;
	x = q;
	y = p - a / b * q;
	return ans;
}
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}
const ll mod = 1e9 + 7;
ll modpow(ll n, ll r) {
	if (!r)return 1;
	if (r == 1) return n;
	ll p = modpow(n,r / 2);
	p = (p * p) % mod;
	if (r % 2)p = (p * n) % mod;
	return p;
}

int main()
{
	//ofstream cout("outpUt.txt");
	//ifstream cin("inpUt.txt");
	//freopen("outpUt.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1)
			cout << "Finite";
		else
			cout << "inFinite";
		cout << endl;
	}
}