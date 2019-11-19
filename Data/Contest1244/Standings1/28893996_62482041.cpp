#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 998244353;
const int N = 100010;
int n, a[N], len, aa[N];
int c[4][N];
vector<int> e[N]; int in[N];
ll f[4][4][N]; pii opt[4][4][N];

template<typename T> void gi(T &x) {
	x = 0; register char c = getchar(), pre = 0;
	for(; c < '0' || c > '9'; pre = c, c = getchar());
	for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10ll + (c ^ 48);
	if(pre == '-') x = -x;
}
void dfs(int u, int ff) {
	a[++len] = u; for(auto v : e[u]) if(v != ff) dfs(v, u);
}
int main() {
	gi(n);
	rep(i, 1, 3) rep(j, 1, n) gi(c[i][j]);
	rep(i, 2, n) {
		int x, y; gi(x), gi(y), e[x].pb(y), e[y].pb(x);
		++in[x], ++in[y]; if(in[x] > 2 || in[y] > 2) { puts("-1"); return 0; }
	}
	rep(i, 1, n) if(in[i] == 1) { dfs(i, 0); break; }
	rep(i, 1, 3) f[i][i][1] = c[i][a[1]];
	rep(i, 2, n) {
		rep(j, 1, 3) rep(k, 1, 3) if(f[j][k][i - 1]) {
			rep(h, 1, 3) if(h != j && h != k) {
				if(!f[k][h][i])
					f[k][h][i] = f[j][k][i - 1] + c[h][a[i]], opt[k][h][i] = mp(j, k);
				else if(f[k][h][i] > f[j][k][i - 1] + c[h][a[i]])
					f[k][h][i] = f[j][k][i - 1] + c[h][a[i]], opt[k][h][i] = mp(j, k);
			}
		}
	}
	ll ans = 1e16;
	rep(i, 1, 3) rep(j, 1, 3) if(f[i][j][n]) ans = min(ans, f[i][j][n]);
	printf("%lld\n", ans);
	pii id = mp(0, 0);
	rep(i, 1, 3) rep(j, 1, 3) if(f[i][j][n] == ans) { id = mp(i, j); break; }
	per(i, n, 1) {
		aa[a[i]] = id.snd, id = opt[id.fst][id.snd][i];
	}
	rep(i, 1, n) printf("%d ", aa[i]);
	return 0;
}