#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 100003;
int n, c[3][N], ans[3], resx[3], nod[N], tot, pre[N], deg[N];
LL res;
vector<int> vec[N];
inline void dfs(int u, int f = 0){
	nod[++ tot] = u; pre[u] = tot;
	for(Rint v : vec[u])
		if(v != f) dfs(v, u);
}
int main(){
	scanf("%d", &n);
	for(Rint i = 0;i < 3;i ++)	
		for(Rint j = 1;j <= n;j ++) scanf("%d", c[i] + j);
	for(Rint i = 1;i < n;i ++){
		int u, v;
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
		++ deg[u]; ++ deg[v];
	}
	for(Rint i = 1;i <= n;i ++)
		if(deg[i] >= 3){puts("-1"); return 0;}
	for(Rint i = 1;i <= n;i ++)
		if(deg[i] == 1){
			dfs(i); break;
		}
	for(Rint i = 0;i < 3;i ++) ans[i] = i; res = 1e18;
	do {
		LL tmp = 0;
		for(Rint i = 1;i <= n;i ++)
			tmp += c[ans[i % 3]][nod[i]];
		if(tmp < res){
			res = tmp; memcpy(resx, ans, sizeof resx);
		}
	} while(next_permutation(ans, ans + 3));
	printf("%I64d\n", res);
	for(Rint i = 1;i <= n;i ++)
		printf("%d ", resx[pre[i] % 3] + 1);
}