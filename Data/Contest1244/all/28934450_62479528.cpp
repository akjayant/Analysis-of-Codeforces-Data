#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 112345
vi g[N];
ll c[N][4];
int q[N];

void dfs(int a, int b, int p){
	DEBUG("%d: %d\n", b, a + 1);
	REP(i, 4) q[b] = a;
	for(int &i : g[a]){
		if(i == p) continue;
		dfs(i, b+1, a);
	}
}
int p[4] = {0, 1, 2};

int ans[N];
ll clc(int n){
		ll tmp = 0;
		REP(i, n){
			tmp += c[q[i]][p[i%3]];
			ans[q[i]] = p[i%3];
		}
		return tmp;
}

int main(){
	int n; scanf("%d", &n);
	REP(j, 3) REP(i, n) scanf("%lld", c[i]+j);
	REP(i, n-1){
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		g[u].EB(v);
		g[v].EB(u);
	}
	int mi = 0;
	REP(i, n) {
		if(g[i].size() > 2){
			printf("-1\n");
			return 0;
		}
		if(g[mi].size() > g[i].size()) mi = i;
	}
	dfs(mi, 0, -1);
	
	ll cand = LLONG_MAX;
	do {
		SML(cand, clc(n));
	}while(next_permutation(p, p+3));

	do {
		if(cand == clc(n)){
			printf("%lld\n", cand);
			REP(i, n) printf("%d ", ans[i] + 1);
			return 0;
		}
	}while(next_permutation(p, p+3));
}
