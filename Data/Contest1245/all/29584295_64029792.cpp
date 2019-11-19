#include<bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)/2)
#define st first
#define nd second
#define ll long long
#define N 60005
#define inf 1000000000
#define MOD 1000000007
#define fast_io() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(false)
using namespace std;

int n;
int go[N][10];
double dp[N][2];
int vis[N][2],lad[N];

int g(int x,int y) {

	if(x<1 || y<1 || x>n || y>n) return 0;

	return (x-1)*10+y;

}

double dfs(int node,int zr) {

	if(node==1) return 0;

	if(vis[node][zr]) return dp[node][zr];

	vis[node][zr]=1;

	if(!zr) { 

		double p=1.0/6;
		double sum=1;

		for(int i=1;i<=6;i++) {

			int gg=go[node][i];

			if(gg==1) {

				dp[node][zr]=sum+=p*dfs(gg,1);

				int x=6-i;

				dp[node][zr]=sum*6/(6-x);

				break ;

			}
			else {

				dp[node][zr]=sum+=p*dfs(gg,1);

			}

		}

		return dp[node][zr];

	}
	else {

		return dp[node][zr]=min(dfs(node,0),dfs(lad[node],0));

	}

}

int main() {

	n=10;

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=n;j++) {

			int cur=g(i,j);
			int x;

			scanf("%d",&x);

			if(i&1) {

				if(j!=1) go[cur][1]=g(i,j-1);
				else go[cur][1]=g(i-1,j);

			}
			else {

				if(j!=n) go[cur][1]=g(i,j+1);
				else go[cur][1]=g(i-1,j);

			}

			lad[cur]=g(i-x,j);

		}

	}

	for(int i=1;i<=n;i++) {

		if(i&1) {

			for(int j=1;j<=n;j++) {

				int cur=g(i,j);

				for(int k=2;k<=6;k++) {

					go[cur][k]=go[go[cur][1]][k-1];

				}

			}

		}
		else {

			for(int j=n;j>=1;j--) {

				int cur=g(i,j);

				for(int k=2;k<=6;k++) {

					go[cur][k]=go[go[cur][1]][k-1];

				}

			}

		}

	}

	dfs(g(n,1),0);

	printf("%.12lf\n",dp[g(n,1)][0]);

}