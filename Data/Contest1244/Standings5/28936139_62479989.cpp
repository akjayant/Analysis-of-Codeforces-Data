#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const ll inf=1e18;
const int maxn=1e5+5;
vector<int>g[maxn];

int ac[maxn],col[maxn];
ll a[4][maxn],in[maxn];
ll dfs(int u,int f,int curcol,int nxtcol){
	ll ak=a[nxtcol][u];
	col[u]=nxtcol;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==f)continue;
		//dfs(v,u);
		int w;
		for(int j=1;j<=3;j++){
			if(j!=curcol&&j!=nxtcol)w=j;
		}
		ak+=dfs(v,u,nxtcol,w);
		//ak+=a[]
		//if()w1+=dp[v][2]	
	}
	/*if(g[u].size()==1){
		w1=min(dp[g[u][0]][2],dp[g[u][0]][3]);	
		w2=min(dp[g[u][0]][1],dp[g[u][0]][3]);
		w3=min(dp[g[u][0]][2],dp[g[u][0]][1]);		
	}
	else if(g[u].size()==2){
		w1=min(dp[g[u][0]][2]+dp[g[u][1]][3],dp[g[u][0]][3]+dp[g[u][1]][2]);	
		w2=min(dp[g[u][0]][3]+dp[g[u][1]][1],dp[g[u][0]][1]+dp[g[u][1]][3]);
		w3=min(dp[g[u][0]][2]+dp[g[u][1]][1],dp[g[u][0]][1]+dp[g[u][1]][2]);		
	}
	dp[u][1]+=w1;
	dp[u][2]+=w2;
	dp[u][3]+=w3;*/
	return ak;
}

int main(){
	int n;
	scanf("%d",&n);
	int F=1;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);

		}
	}
	for(int i=1;i<n;i++){
		int b,c;
		scanf("%d%d",&b,&c);
		g[b].push_back(c);
		g[c].push_back(b);		
		in[b]++;
		in[c]++;
		if(in[b]>=3||in[c]>=3)F=0;
	}
	if(F){
	//	dfs(1,0);	
		ll ans=inf;
		int ww;
		for(int i=1;i<=n;i++){
			if(in[i]==1)ww=i;
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i==j)continue;
				col[ww]=i;
				ll x=dfs(g[ww][0],ww,i,j)+a[i][ww];
				if(x<ans){
					ans=x;
					//debug(ans);
					for(int k=1;k<=n;k++){
						ac[k]=col[k];
					}
				}
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++){
			printf("%d",ac[i]);
			char cc=(i==n)?'\n':' ';
			printf("%c",cc);
		}
		//printf("%lld\n",min(dp[1][1],min(dp[1][2],dp[1][3]))); 
	}
	else printf("-1\n"); 
	return 0;
} 
 