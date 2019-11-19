#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

ll COST[2020][2020];

vii P;
ll dist(ll i, ll j) {
    return abs(P[i].fs-P[j].fs)+abs(P[i].sc-P[j].sc);
}

vi OL;
vii SOL;

struct union_find {
	vi p;
	union_find(ll n) : p(n) { rep(i,0,n) p[i] = i; }
	ll find(ll a) { return p[a] == a ? a : p[a] = find(p[a]); }
	bool joined(ll a, ll b) { return find(a) == find(b);}
	void unite(ll a, ll b) { p[find(a)] = find(b); }
};

ll n;
ll mst(vector<pair<ll,ii>> &edg, ll size) {
    sort(edg.begin(), edg.end());
	ll cost = 0;
	union_find ds(size);
	vii mst;
	rep(i,0,edg.size()) {
		ll x = edg[i].sc.fs;
		ll y = edg[i].sc.sc;
        if (!ds.joined(x, y)) {
            if(x == n) {
                OL.pb(y);
            } else if(y == n) {
                OL.pb(x);
            }
            else {
                SOL.pb(ii(x,y));
            }

			cost += edg[i].fs;
			ds.unite(x, y);
		}
	}
	return cost;
}


int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    rep(i,0,n+10) rep(j,0,n+10) COST[i][j] = 10000000000000000LL;
    P = vii(n);
    vi C(n);
    vi K(n);
    ll t = n;
    rep(i,0,n) cin >> P[i].fs >> P[i].sc;
    rep(i,0,n) cin >> C[i];
    rep(i,0,n) cin >> K[i];
    rep(i,0,n) rep(j,0,n) {
        if(i == j) continue;
        COST[i][j] = dist(i,j)*(K[i]+K[j]);
    }
    rep(i,0,n) {
        COST[n][i] = C[i];
        COST[i][n] = C[i];
    }
    vector<pair<ll,ii>> E;
    rep(i,0,n+1) rep(j,0,n+1) E.pb(pair<ll,ii>(COST[i][j], ii(i,j)));
    ll val = mst(E,n+1);
    cout << val << endl;
    cout << size(OL) << endl;
    iter(it,OL) cout << *it+1 << " ";
    cout << endl;
    cout << size(SOL) << endl;
    iter(it,SOL) cout << (*it).fs+1 <<  " " << (*it).sc+1 << endl;
    return 0;
}


