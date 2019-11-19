#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
inline int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
inline int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
const int N = 101010;
int n;
int c[3][N];
vi G[N];
int col[N], sb[N];
int in[N];
int cnt = 0;
ll ans = 1e18;
void dfs(int c1, int c2, int u, int p, ll s) {
	cnt++;
	for(int v : G[u]) if(v != p) {
		rep(i, 0, 3) if(i != c1 && i != c2) {
			sb[v] = i;
			dfs(i, c1, v, u, s + c[i][v]);
		}
	}
	if(cnt == n && s < ans) {
		ans = s;
		rep(i, 0, n) col[i] = sb[i];
	}
	cnt--;
}
int main(){
	scanf("%d", &n);
	rep(i, 0, 3) rep(j, 0, n) scanf("%d", c[i] + j);
	rep(i, 0, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		in[v]++, in[u]++;
		G[u].pb(v); G[v].pb(u);
	}
	int mx = 0, rt = 0;
	rep(i, 0, n) {
		mx = max(mx, in[i]);
		if(in[i] == 1) rt = i;
	}
	if(mx > 2) puts("-1");
	else {
		rep(i, 0, 3) {
			sb[rt] = i;
			dfs(i, -1, rt, -1, c[i][rt]);
		}
		printf("%lld\n", ans);
		rep(i, 0, n) printf("%d ", col[i] + 1);
	}
	return 0;
}

