#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define LL long long
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 3;
const LL INF = 1e17;
vector <int> G[N];
int n,rt,cnt;
LL sum;
int d[N];
int c[N][4];
int pre[5];
int as[N];
int num[5];
int dd[N];
inline int read(){
	int v = 0,c = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') c = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		v = v * 10 + ch - 48;
		ch = getchar();
	}
	return v * c;
}
//inline void dfs(int x,int fa){
////	printf("x:%d %d\n",x,fa);
//	bool ok = 1;
//	for(int i = 0;i < (int)G[x].size();++i){
//		int y = G[x][i];
//		if(y == fa) continue;ok = 0;
//		dfs(y,x);
//		for(int u = 1;u <= 3;++u){
//			for(int v = 1;v <= 3;++v){
//				if(u == v || u == pre[y][v].se) continue;
//				if(f[x][u] > f[y][v] + c[x][u]){
//					f[x][u] = min(f[x][u],f[y][v] + c[x][u]);
//					pre[x][u] = mk(y,v);	
//				}
//			}
//		}
//	}
//	if(ok){
//		for(int i = 1;i <= 3;++i) f[x][i] = c[x][i];
//	}
//}
//inline void work(int x,int y){
//	if(!x) return ;
//	as[x] = y;
//	work(pre[x][y].fi,pre[x][y].se);
//}
inline void dfs(int x,int f,int dep,int c1,int c2){
//	printf("%d %d %d %d %d\n",x,f,dep,c1,c2);
	dd[dep] = x;
	if(dep < 3) sum += c[x][num[dep]];
	else {
		int id = 6 - c1 - c2;
	//	printf("%d\n",id);
		sum += c[x][id];
	}
	for(int i = 0;i < (int)G[x].size();++i){
		int y = G[x][i];
		if(y == f) continue;
		if(dep == 1) dfs(y,x,dep + 1,c2,num[1]);
		else if(dep == 2) dfs(y,x,dep + 1,c2,num[2]);
		else dfs(y,x,dep + 1,c2,6 - c1 - c2);
	}
}
int main(){
	n = read();
	for(int i = 1;i <= n;++i) c[i][1] = read();	
	for(int i = 1;i <= n;++i) c[i][2] = read();
	for(int i = 1;i <= n;++i) c[i][3] = read();
//	for(int i = 1;i <= n;++i){
//		for(int j = 1;j <= 3;++j) f[i][j] = INF;
//	}	
	for(int i= 1;i < n;++i){
		int x = read(),y = read();
		G[x].push_back(y);
		G[y].push_back(x);
		d[x]++,d[y]++;
		if(d[x] > 2 || d[y] > 2){
			puts("-1");
			return 0;
		}
	}
	for(int i = 1;i <= n;++i) if(d[i] == 1) rt = i;
	for(int i = 1;i <= 3;++i) num[i] = i;
	LL ans = 100000000000000000ll;
	int id = 0;
	do{
		sum = 0;
//	for(int i = 1;i <= 3;++i) printf("%d ",num[i]);puts(""); 
		dfs(rt,0,1,0,0);
		
		if(sum < ans){
			ans = sum;
			for(int i = 1;i <= 3;++i) pre[i] = num[i];
		}
	}while(next_permutation(num + 1,num + 4));
	printf("%lld\n",ans);
	for(int i = 1;i <= n;++i){
		if(i <= 3) as[dd[i]] = pre[i];
		else as[dd[i]] = 6 - as[dd[i - 1]] - as[dd[i - 2]];	
	}
	for(int i = 1;i <= n;++i) printf("%d ",as[i]);
	return 0;
}

