#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 5001;
ll cost[maxn],ans;
int n;
ll x[maxn],y[maxn],k[maxn];
int from[maxn];
int vis[maxn];
inline ll xxx(ll x){ return x < 0 ? - x : x ; }
inline bool down(ll & x,ll y){
	return x > y ? x = y,1 : 0;
}
inline void prim(){
	for(int i = 1;i <= n;++i){
		int pos = - 1;
		for(int j = 1;j <= n;++j) if(!vis[j] && (pos == - 1 || cost[pos] > cost[j])) pos = j;
		ans += cost[pos]; vis[pos] = 1;
		for(int j = 1;j <= n;++j) if(!vis[j])
			if(down(cost[j],(xxx(x[j] - x[pos]) + xxx(y[j] - y[pos])) * (k[j] + k[pos])))
				from[j] = pos;
	}
}
int main(){
	std::cin >> n;
	for(int i = 1;i <= n;++i) std::cin >> x[i] >> y[i];
	for(int i = 1;i <= n;++i) std::cin >> cost[i];
	for(int i = 1;i <= n;++i) std::cin >> k[i];
	prim();
	std::cout << ans << '\n';
	std::cout << std::count(from + 1,from + n + 1,0) << '\n';
	for(int i = 1;i <= n;++i) if(from[i] == 0) std::cout << i << ' '; std::cout << '\n';
	std::cout << n - std::count(from + 1,from + n + 1,0) << '\n';
	for(int i = 1;i <= n;++i) if(from[i]) std::cout << from[i] << ' ' << i << '\n';
}
