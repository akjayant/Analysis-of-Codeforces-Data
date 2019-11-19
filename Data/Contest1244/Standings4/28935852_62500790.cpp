#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
const int maxn = 1e5+35;
int head[maxn],c[maxn][4],d[maxn],cnt,n,u,v;
struct edge{
	int to,nxt;
}e[maxn<<1];
inline void add(int u,int v){
	e[++cnt] = (edge){v,head[u]};
	head[u] = cnt;
}
int a[maxn],cl[maxn],res[maxn],m;
void dfs(int x,int fa){
	a[++m] = x;
	for(int i = head[x]; i;i = e[i].nxt){
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,x);
	}
}
ll dp[maxn][3];
int main(){
	cin >> n;
	for(int i = 1;i <= n; ++i) cin >> c[i][1];
	for(int i = 1;i <= n; ++i) cin >> c[i][2];
	for(int i = 1;i <= n; ++i) cin >> c[i][3];
	for(int i = 1;i < n; ++i){
		cin >> u >> v; d[u]++; d[v]++;
		add(u,v); add(v,u);
	}
	int rt = 0; bool flag = true;
	for(int i = 1;i <= n; ++i){
		if(d[i] == 1) rt = i;
		else if(d[i] != 2) flag = false;
	}
	if(!flag) return puts("-1"),0;
	dfs(rt,0);
	ll ans = 1e18; int x = 0,y = 0;
	for(int i = 1;i <= 3; ++i){
		for(int j = 1;j <= 3; ++j){
			if(i == j) continue;
			ll cost = c[a[1]][i]+c[a[2]][j]; cl[1] = i;cl[2] = j;
			for(int q = 3;q <= n; ++q){
				for(int p = 1;p <= 3; ++p){
					if(p!=cl[q-1]&&p!=cl[q-2]){
						cost += c[a[q]][p];
						cl[q] = p; break;
					}
				}
			}
			if(cost < ans){
				ans = cost; x = i,y = j;
			}
		}
	}
	   cl[1] = x;cl[2] = y; res[a[1]] = x,res[a[2]] = y;
			for(int q = 3;q <= n; ++q){
				for(int p = 1;p <= 3; ++p){
					if(p!=cl[q-1]&&p!=cl[q-2]){
						cl[q] = p; res[a[q]] = p;break;
					}
				}
			}
	cout << ans << '\n';
	for(int i = 1;i <= n; ++i) cout << res[i] << " ";
	return 0;
	
} 