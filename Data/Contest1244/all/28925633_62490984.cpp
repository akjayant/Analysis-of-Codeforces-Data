#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int M=1e5+5;
#define LL long long
int n,w,Now,a,b;
int C[4][M];
int c[M];
LL Ans=1e18,res=0,Now1,Now2;
vector<int>E[M];
void dfs(int x,int f,int d) {
	if(d>Now) {
		Now=d;
		w=x;
	}
	for(int i=0; i<(int)E[x].size(); ++i) {
		int u=E[x][i];
		if(u==f)continue;
		dfs(u,x,d+1);
	}
}
void Dfs(int x,int f,int k,int d) {
	res+=C[d][x];
	c[x]=d;
	for(int i=0; i<(int)E[x].size(); ++i) {
		int u=E[x][i];
		if(u==f)continue;
		Dfs(u,x,k,(d+k+3)%3);
	}
}
int main() {
	scanf("%d",&n);
	for(int j=0; j<3; ++j)
		for(int i=1; i<=n; ++i)scanf("%d",C[j]+i);
	for(int i=1; i<n; ++i) {
		scanf("%d%d",&a,&b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for(int i=1; i<=n; ++i)
		if(E[i].size()>2) {
			puts("-1");
			return 0;
		}
	dfs(1,0,0);
//	printf("w=%d\n",w);
	for(int i=0; i<3; ++i) {
		res=0;
		Dfs(w,0,-1,i);
		if(res<Ans)Ans=res,Now1=i,Now2=-1;
		res=0;
		Dfs(w,0,1,i);
		if(res<Ans)Ans=res,Now1=i,Now2=1;
	}
	Dfs(w,0,Now2,Now1);
	cout<<Ans<<endl;
	for(int i=1; i<=n; ++i)
		printf("%d ",c[i]+1);
}