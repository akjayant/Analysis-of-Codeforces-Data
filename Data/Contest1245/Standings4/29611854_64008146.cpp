#include<bits/stdc++.h>
//#include<unordered_map>

//кодеры класс и информатика тоже!!! © Мейбл

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

typedef long long  ll;
typedef unsigned long long ull;
typedef long double ld;

#define pii pair<int,int >
#define pll pair<ll ,ll >
#define pdd pair<ld ,ld >
#define pbb pair<bool,bool>
#define plll pair<long long,pair<long long ,long long > >
#define sefi second.first
#define sese second.second
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) x.size()
#define sqr(x) (x)*(x)
#define cont continue
#define endln '\n'
#define YES cout<<"YES"<<endln
#define OK cout<<"OK"<<endln
#define NO cout<<"NO"<<endln
#define rep(x,a,b) for(int x = a; x < b; x++)
#define per(x,a,b) for(int x = a; x > b; x--)

//#define int long long

const ll  md = 1e9 + 7;
const ll Inf = 1e9;
const ll Inf64 = 1e18;
const ll MaxN = 4e5 + 100;
const ll LogN = 21;
const ll MaxM = 5e5 + 10;
const ld eps = 1e-15;
const ll dx[8] = { 1,-1,2,2,-1,1,-2,-2 };
const ll dy[8] = { 2,2,1,-1,-2,-2,1,-1 };
const ll ddx[4] = { 1,1,-1,-1 };
const ll ddy[4] = { 1,-1,1,-1 };
const ld Pi = acos(-1);

using namespace std;

template <typename T>
istream & operator>> (istream & in, pair<T, T> & a) {
	in >> a.first >> a.second;
	return in;
}

template <typename T>
ostream & operator<< (ostream & out, pair<T, T> a) {
	out << a.first << ' ' << a.second;
	return out;
}

template <typename T>
istream & operator>> (istream & in, vector<T> & Mt) {
	for (T & a : Mt) in >> a;
	return in;
}

template <typename T>
ostream & operator<< (ostream & out, vector<T> Mt) {

	for (int i = 0;i < sz(Mt);i++) {
		out << Mt[i];
		if (i != sz(Mt)) out << ' ';
	}
	out << endln;
	return out;
}

inline ll Mod(ll &a, ll m = md) {
	while (a >= m)
		a -= m;
	return a;
}

inline ll gcd(ll a, ll b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

inline ll gcdex(ll a, ll mod = md) {
	ll g = mod, r = a, x = 0, y = 1;
	while (r != 0) {
		ll q = g / r;
		g %= r;
		swap(g, r);
		x -= q * y;
		swap(x, y);
	}
	return x < 0 ? x + mod : x;
}

inline ll binpow(ll a, ll n, ll m = md) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res % md;
}

// ///////
/// ////
// ///////

ll calc(ll N) {
	
	ll a = 0;
	ll b = 1;
	while (N--) {
		a += b;
		a %= md;
			swap(a, b);

	}
	return b;
}
signed main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	//ifstream cin("input.txt");
	//ofstream cout("nim.out");
	//ifstream lin("");
	//ofstream cerr("errput.txt");
#else
	//ifstream cin("race.in");
	//ofstream cout("race.out");
#endif // !LOCAL
	cin.tie(0);
	cout.tie(0);
	//cerr.tie(0);
	cout << fixed, cout.precision(20);
	// //

	{	
		
		string s;
		cin >> s;
		//bool f = 1;
		ll N = sz(s);
		for (int i = 0;i < N;i++) {
			if (s[i] == 'm' || s[i] == 'w') {
				cout << 0;
				goto END;
			}
		}
		s.push_back('1');
		bool f = 0;
		ll a = 0;
		char c;
		ll Ans = 1;
		N++;
		for (int i = 0;i < N;i++) {
			if (f == 0) {
				if (s[i] == 'u') {
					f = 1;
					a = 1;
					c = 'u';
				}
				if (s[i] == 'n') {
					f = 1;
					a = 1;
					c = 'n';
				}
			}
			else {
				if (c == s[i]) {
					a++;
				}
				else {
					Ans *= calc(a);
					Ans %= md;
					f = 0;
					c = 0;
					a = 0;
					i--;
				}
			}
		}
		cout << Ans;
	}
	



	// //////////////

END:
#ifdef LOCAL
	cerr << '\n' << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << '\n';
	ll o;
	cin >> o;
#endif

	return 0;


}
/*

*/