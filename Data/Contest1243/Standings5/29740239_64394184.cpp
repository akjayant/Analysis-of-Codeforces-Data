#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 5;

struct DSU{
	int lab[maxn];

	void Init (void){
		memset (lab, -1, sizeof lab);
	}
	int finds (int u){
		if (lab[u] < 0) return u;
		return lab[u] = finds (lab[u]);
	}
	bool same (int u, int v){
		return (finds (u) == finds (v));
	}
	bool merges (int u, int v){
		u = finds (u); v = finds (v);
		if (u == v) return 0;
		if (lab[v] < lab[u]) swap (u, v);
		lab[u] += lab[v];
		lab[v] = u;
		return 1;
	}
}dsu;

int brute_force (int n){
	dsu.Init ();
	for (int i=1; i<=n; ++i){
		for (int j=i+2; j<=n; ++j){
			if (n % (j-i) == 0){
				dsu.merges (i, j);
			}
		}
	}
	int ret = 0;
	for (int i=1; i<=n; ++i) if (dsu.lab[i] < 0) ++ret;
	return ret;
}

bool check (int x, int spf){
	while (x != 1){
		if (x % spf != 0) return false;
		x /= spf;
	}
	return true;
}

signed main (void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	int spf = 0;
	for (int i=2; i*i<=N; ++i){
		if (N % i == 0){
			spf = i;
			break;
		}
	}
	//cerr << brute_force (N) << '\n';
	if (spf == 0) cout << N;
	else if (check (N, spf)) cout << spf;
	else cout << 1;
}

