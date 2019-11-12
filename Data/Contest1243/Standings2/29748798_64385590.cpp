#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define all(v)          ((v).begin()), ((v).end())
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define clr(v,d)		memset(v, d, sizeof(v))
const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = (1e9) + 7;
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
const int N = 1000001;
#define endl '\n'
#define ever ;;
#define F first
#define S second
#define pii pair<int,int>
#define sz(v) ((int)((v).size()))
#define pll pair<ll,ll>
#define test int t;cin>>t;while(t--)
void stop() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
void file() {
#ifndef ONLINE_JUDGE
	freopen("tawla.in", "r", stdin);
	//	freopen("pizza.out", "w", stdout);
#endif
}
struct point {
	ll x, y;
};
ull gcd(ull a, ull b) { return !b ? a : gcd(b, a % b); }
ll fixMod(ll a, ll b) { return ((a%b) + b) % b; }
double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2.;
};
ll dis(pair<ll, ll> a, pair<ll, ll> b) {
	ll x = a.first - b.first, y = a.second - b.second;
	return abs(x) + abs(y);
}
ull LCM(ull a, ull b) {
	return a / gcd(a, b)*b;
}
ll power(ll x, ll y)
{
	if (y == 0)return 1;
	if (y == 1)return x;
	ll r = power(x, y / 2) % mod;
	return r%mod*r%mod*power(x, y % 2) % mod;
}
bool isPrime(ll x){
	if (x <= 1)return 0;
	for (ll i = 2; i*i <= x; i++){
		if (x%i == 0)return 0;
	}
	return 1;
}
int main()
{
	fast
		test{
	string s, t;
	int n;
	cin >> n;
	cin >> s >> t;
	vector<int>no_eq;

	int c = 0;
	for (int k = 0; k < n; k++)
	{
		if (s[k] != t[k])
			c++, no_eq.push_back(k);
	}
	if (c > 2){
		cout << "No" << endl;
		continue;
	}
	swap(s[no_eq[0]], t[no_eq[0]]);
	if (s == t){
		cout << "Yes" << endl;
		continue;
	}

	swap(s[no_eq[0]], t[no_eq[0]]);
	if (no_eq.size() != 2){
		cout << "No" << endl;
		continue;
	}
	swap(s[no_eq[0]], t[no_eq[1]]);
	if (s == t){
		cout << "Yes" << endl;
		continue;
	}
	swap(s[no_eq[0]], t[no_eq[1]]);
	swap(s[no_eq[1]], t[no_eq[0]]);
	if (s == t){
		cout << "Yes" << endl;
		continue;
	}

	swap(s[no_eq[1]], t[no_eq[0]]);
	swap(s[no_eq[1]], t[no_eq[1]]);
	if (s == t)cout << "Yes" << endl;
	else cout << "No" << endl;
}
	stop();
	return 0;
}