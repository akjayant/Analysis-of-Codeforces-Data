#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef pair<int, ii> tri;
typedef vector<tri> viii;

#define fi(i,a,b) for(auto i=a;i<b;i++)
#define trav(i,v) for(auto &i: v)
#define fd(i,a,b) for(auto i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define ss second
#define ff first
#define sz(a) a.size()
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d %d", &x, &y)
#define sc3(x) scanf("%s", x)
#define sc4(x) scanf("%lld", &x)
#define sc5(x, y) scanf("%lld %lld", &x, &y)
#define sc6(x) scanf("%lf", &x)
#define sc7(x, y) scanf("%lf %lf", &x, &y)
#define mse(a, x) memset(a, x, sizeof(a))
#define mod 1000000007ll

#define TRACE
#ifdef TRACE
	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
		
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << ": " << arg1 << std::endl;
	}

	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ',');
		cerr.write(names, comma - names) << ": " << arg1<<" |";
		__f(comma+1, args...);
	}
#else
	#define trace(...) ;
#endif

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll c[100100][3];
vl g[100100];
ll r[100100];

ll calc(ll u, ll p, ll x, ll y) {
	ll res = c[u][x];
	trav(i, g[u]) {
		if(i == p) {
			continue;
		}
		res += calc(i, u, 3 - x - y, x);
	}
	return res;
}

void pr(ll u, ll p, ll x, ll y) {
	r[u] = x;
	trav(i, g[u]) {
		if(i == p) {
			continue;
		}
		pr(i, u, 3 - x - y, x);
	}
}

int main() {
	ll n;
	sc4(n);
	fi(i, 0, 3) {
		fi(j, 0, n) {
			sc4(c[j][i]);
		}
	}
	ll u, v;
	fi(i, 0, n-1) {
		sc5(u, v);
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fi(i, 0, n) {
		if(g[i].size() > 2) {
			printf("-1\n");
			return 0;
		}
		if(g[i].size() == 1) {
			u = i;
		}
	}
	ll res = mod * mod, temp;
	pll minm;
	fi(i, 0, 3) {
		fi(j, 0, 3) {
			if(i == j) continue;
			temp = calc(u, -1, i, j);
			if(res > temp) {
				res = temp;
				minm = {i, j};
			}
		}
	}
	printf("%lld\n", res);
	pr(u, -1, minm.ff, minm.ss);
	fi(i, 0, n) {
		printf("%lld ", r[i]+1);
	}
	printf("\n");
	return 0;
}
