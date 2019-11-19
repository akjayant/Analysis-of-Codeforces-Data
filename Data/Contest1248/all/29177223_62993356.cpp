#include <iostream>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define MOD 1000000007
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

class Combination {
public:
	Array fact;//n！
	Array inv;//n!の逆元
	ll mod;
	Combination(ll n, ll _mod) {
		mod = _mod;
		fact.resize(n + 1);
		fact[0] = 1;
		REP(i, n) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		inv.resize(n + 1);
		REP(i, n + 1) {
			inv[i] = mod_inv(fact[i]);
		}
	}
	//modの逆元
	ll mod_inv(ll x) {
		ll n = mod - 2;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	ll nCr(ll n, ll r) {
		return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		//重複組み合わせ：n種類のものからr個取り出す組み合わせ
		return nCr(r + n - 1, r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,m;
	cin >> n>>m;

	ll ans = 0;
	Combination com(max(n+1,m+1), MOD);

	REP(i, n/2+1) {
		//cout <<"y"<< i << endl;
		ll nn = n -i;
		(ans += com.nCr(nn, i))%=MOD;
		//cout << com.nCr(nn, i) << endl;
	}

	rep(i,1, m / 2+1) {
		//cout << "x" << i << endl;
		ll mm = m - i;
		(ans += com.nCr(mm, i))%=MOD;
		//cout << com.nCr(mm, i) << endl;
	}

	cout << (ans*2)%MOD << endl;


	return 0;
}