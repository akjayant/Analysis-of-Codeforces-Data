#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
	int f=0,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
vector<int> G[MAXN+5];
int ncnt,cost[MAXN+5][3],d[MAXN+5],id[MAXN+5];
void DFS(int u,int fa){
	id[++ncnt]=u;
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i];
		if(v==fa) continue;
		DFS(v,u);
	}
	return ;
}
LL ans[10];
vector<int> Ans[10];
int Pri[MAXN+5];
int main(){
	int n=read();
	for(int t=0;t<=2;t++)
		for(int i=1;i<=n;i++)
			cost[i][t]=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		d[u]++,d[v]++;
		G[u].push_back(v),G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(d[i]>=3)
			puts("-1"),exit(0);
	for(int i=1;i<=n;i++)
		if(d[i]==1){
			DFS(i,0);
			break;
		}
	if(ncnt<n){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i%3==1){
			ans[1]+=cost[id[i]][0],Ans[1].push_back(0);
			ans[2]+=cost[id[i]][0],Ans[2].push_back(0);
			ans[3]+=cost[id[i]][1],Ans[3].push_back(1);
			ans[4]+=cost[id[i]][1],Ans[4].push_back(1);
			ans[5]+=cost[id[i]][2],Ans[5].push_back(2);
			ans[6]+=cost[id[i]][2],Ans[6].push_back(2);
		}
		else if(i%3==2){
			ans[1]+=cost[id[i]][1],Ans[1].push_back(1);
			ans[2]+=cost[id[i]][2],Ans[2].push_back(2);
			ans[3]+=cost[id[i]][0],Ans[3].push_back(0);
			ans[4]+=cost[id[i]][2],Ans[4].push_back(2);
			ans[5]+=cost[id[i]][1],Ans[5].push_back(1);
			ans[6]+=cost[id[i]][0],Ans[6].push_back(0);
		}
		else{
			ans[1]+=cost[id[i]][2],Ans[1].push_back(2);
			ans[2]+=cost[id[i]][1],Ans[2].push_back(1);
			ans[3]+=cost[id[i]][2],Ans[3].push_back(2);
			ans[4]+=cost[id[i]][0],Ans[4].push_back(0);
			ans[5]+=cost[id[i]][0],Ans[5].push_back(0);
			ans[6]+=cost[id[i]][1],Ans[6].push_back(1);
		}
	}
	LL a=100000000000000000ll;int t=0;
	for(int i=1;i<=6;i++)
		if(a>ans[i])
			a=ans[i],t=i;
	printf("%lld\n",a);
	for(int i=0;i<n;i++)
		Pri[id[i+1]]=Ans[t][i]+1;
	for(int i=1;i<n;i++)
		printf("%d ",Pri[i]);
	printf("%d\n",Pri[n]);
	return 0;
}
