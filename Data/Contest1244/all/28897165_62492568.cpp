#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,c[4][maxn],du[maxn];
struct edge{
	int to,nex;
}e[maxn<<1];
int head[maxn],cnt;
void add(int x,int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
}
int t[maxn],tot;
void dfs(int u,int fa){
	t[++tot]=u;
	for(int i=head[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int mex(int x,int y){
	if(x!=1&&y!=1) return 1;
	if(x!=2&&y!=2) return 2;
	if(x!=3&&y!=3) return 3;
}
int dp[100010][4];
int a[maxn],tt[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>c[1][i];
	for(int i=1;i<=n;++i)
		cin>>c[2][i];
	for(int i=1;i<=n;++i)
		cin>>c[3][i];
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
		++du[x],++du[y];
		if(du[x]>2){
			cout<<"-1"<<'\n';
			return 0;			
		}
		if(du[y]>2){
			cout<<"-1"<<'\n';
			return 0;			
		}
	}
	int s=0;
	for(int i=1;i<=n;++i){
		if(du[i]==1){
			s=i;
		}
	}
	long long ans=(1ll<<60),ii=0,jj=0;
	dfs(s,0);
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(i==j) continue;
			a[1]=i;
			a[2]=j;
			long long now=0;
			for(int k=3;k<=n;++k){
				a[k]=mex(a[k-1],a[k-2]);
			}
			for(int k=1;k<=n;++k){
				now+=c[a[k]][t[k]];
			}
			if(now<ans){
				ans=now;
				ii=i,jj=j;
			}
		}
	}
	cout<<ans<<'\n';
	a[1]=ii,a[2]=jj;
	tt[t[1]]=a[1];
	tt[t[2]]=a[2];
	for(int k=3;k<=n;++k){
		a[k]=mex(a[k-1],a[k-2]);
		tt[t[k]]=a[k];
	}
	for(int k=1;k<=n;++k){
		cout<<tt[k]<<' ';
	}
	cout<<'\n';
	return 0;
}

