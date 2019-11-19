// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, maxn=2e5+5;

int n;
int c[3][maxn];
int de[maxn],ans,seq[maxn];
vector<int>g[maxn];
int tmp,c1,c2;

void dfs(int x,int fat=0){
	if(x!=1)++de [x];
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(u == fat)continue;
		++ de[x];dfs(u,x);
	}
}

void solve(int now,int c1,int c2,int fat){ 
	tmp += c[c1][now];
	for(int i=0;i<g[now].size();i++){
		int u=g[now][i];
		if(u == fat)continue;
		for(int j=0;j<=2;j++)if(j!=c1 && j!=c2)solve(u,c2,j,now); 
	} 
}

void calc(int u,int c1,int c2,int fat){
	seq[u] = c1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v == fat)continue;
		for(int j=0;j<=2;j++)if(j!=c1 && j!=c2)calc(v,c2,j,u);
	}
}

signed main(){
	scanf("%lld",&n);
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)scanf("%lld",&c[i][j]);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%lld%lld",&x,&y);g[x].push_back(y);g[y].push_back(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		if(de[i] >= 3)return puts("-1"), 0;
	int pos = 0;
	for(int i=1;i<=n;i++){
		if(de[i] == 1){pos = i;break;}
	}
	tmp=0;
	int ans=1e18;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			if(i == j)continue;
			tmp = 0;
			solve(pos,i,j,0);
			if(tmp<ans){ans=tmp;c1=i;c2=j;}
		}
	calc(pos,c1,c2,0);
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)printf("%lld ",seq[i]+1);puts(""); 

	return 0;
}
