#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+5;
int c[5][maxn],pos,u,v;
int p[maxn],ans[maxn];
vector<int>G[maxn];
int main(){
	scanf("%d",&n);
	for (int k=1;k<=3;k++)
		for (int i=1;i<=n;i++)
			scanf("%d",&c[k][i]);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flag=true;
	for (int i=1;i<=n;i++){
		if (G[i].size()>2){
			flag=false;
			break;
		}
		if (G[i].size()==1){
			pos=i;
		}
	}
	if (!flag){
		cout << -1 ;
		return 0;
	}
	long long cost=0;
	long long mi=1e18;
	for (int i=1;i<=3;i++){
		p[pos]=i;
		for (int j=1;j<=3;j++){
			if (i==j) continue;
			u=pos;
			v=G[pos][0];
			p[v]=j;
			cost=c[i][pos];
			cost+=c[j][v];
			while (G[v].size()!=1){
				int w=G[v][0];
				if (w==u)
					w=G[v][1];
				int color=6-p[u]-p[v];
				cost+=c[color][w];
				p[w]=color;
				u=v;
				v=w;
			}
			if (cost<mi){
				memcpy(ans,p,sizeof(p));
				mi=cost;
			}
		}
	}
	cout << mi << '\n';
	for (int i=1;i<=n;i++)
		cout << ans[i] << ' ';
} 