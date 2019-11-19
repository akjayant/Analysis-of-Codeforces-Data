#include<bits/stdc++.h>
//#include<unordered_map>

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
#define YES cout<<"Yes"<<endln
#define OK cout<<"OK"<<endln
#define NO cout<<"No"<<endln
#define rep(x,a,b) for(int x = a; x < b; x++)
#define per(x,a,b) for(int x = a; x > b; x--)

//#define int long long

const ll  md = 1e9 + 7;
const ll Inf = 1e9;
const ll Inf64 = 1e18;
const ll MaxN = 2e5 + 100;
const ll LogN = 21;
const ll MaxM = 5e5 + 10;
const ld eps = 1e-6;
const ll dx[4] = { 0,1,0,-1 };
const ll dy[4] = { 1,0,-1,0 };
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

vector<ll > Gr[MaxN];
vector<ll > Mt;
void dfs(ll v, ll p) {
	Mt.pb(v);
	for (ll to : Gr[v]) {
		if (p == to) cont;
		dfs(to, v);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	//ifstream cin("nim.in");
	//ofstream cout("nim.out");
	//ifstream lin("");
	//ofstream cerr("errput.txt");
#else
//	ifstream cin("nim.in");
//	ofstream cout("nim.out");
#endif // !LOCAL
	cin.tie(0);
	cout.tie(0);
	//cerr.tie(0);
	//cout << fixed, cout.precision(20);
	// //

	{
		ll N;
		cin >> N;
		vector<ll > At(N);
		vector<ll > Bt(N);
		vector<ll > Ct(N);
		cin >> At >> Bt >> Ct;
		for (int i = 0;i< N - 1;i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			Gr[a].push_back(b);
			Gr[b].push_back(a);
			if (sz(Gr[a]) >= 3 || sz(Gr[b]) >= 3) {
				cout << -1;
				goto END;
			}
		}
		ll k = 0;
		for (int i = 0;i < N;i++) {
			if (sz(Gr[i]) == 1) { k = i; break; }
		}
		dfs(k, -1);
		vector<vector<ll > > dp(6, vector<ll >(N, 0));
		//vector<vector<ll > > Res(6);
		dp[0][1] = At[Mt[0]] + Bt[Mt[1]];
		dp[1][1] = At[Mt[0]] + Ct[Mt[1]];
		dp[2][1] = Bt[Mt[0]] + At[Mt[1]];
		dp[3][1] = Bt[Mt[0]] + Ct[Mt[1]];
		dp[4][1] = Ct[Mt[0]] + At[Mt[1]];
		dp[5][1] = Ct[Mt[0]] + Bt[Mt[1]];
		for (int i = 2;i < N;i++) {
			dp[0][i] = dp[4][i-1] + Bt[Mt[i]];
			dp[1][i] = dp[2][i - 1] + Ct[Mt[i]];
			dp[2][i] = dp[5][i - 1] + At[Mt[i]];
			dp[3][i] = dp[0][i - 1] + Ct[Mt[i]];
			dp[4][i] = dp[3][i - 1] + At[Mt[i]];
			dp[5][i] = dp[1][i - 1] + Bt[Mt[i]];
		}
		ll Ans = Inf64;
		ll r = -1;
		for (int i = 0;i < 6;i++) {
			if (Ans > dp[i][N-1]) {
				Ans = dp[i][N-1];
				r = i;
			}
		}
		vector<ll > Res;
		for (int i = 0;i < N;i++) {
			if (r == 0) {
				Res.pb(2);
				r = 4;
			}else if (r == 1) {
				Res.pb(3);
				r = 2;
			}
			else if (r == 2) {
				Res.pb(1);
				r = 5;
			}
			else if (r == 3) {
				Res.pb(3);
				r = 0;
			}
			else if (r == 4) {
				Res.pb(1);
				r = 3;
			}
			else if (r == 5) {
				Res.pb(2);
				r = 1;
			}
			
		}
		reverse(all(Res));
		vector<ll > Tr(N);
		for (int i = 0;i< N;i++) {
			Tr[Mt[i]] = Res[i];
		}
		cout << Ans << endln;
		cout << Tr;

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
4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1

*/