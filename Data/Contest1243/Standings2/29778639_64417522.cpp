#include<bits/stdc++.h>
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define sz(x) int(x.size())
#define All(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef priority_queue<int> BQ;
typedef priority_queue<int,vector<int>,greater<int> > SQ;
const int maxn=1e5+10,mod=1e9+7,INF=0x3f3f3f3f;
set<int> e[maxn];
int n;
int node[maxn],ne[maxn],pre[maxn],vis[maxn];
int find(int x){
	return vis[x]==0?x:ne[x]=find(ne[x]);
}
void dfs(int u){//de(u);
	if (!vis[u]){
		int p=ne[u],q=pre[u];
		ne[q]=p;
		pre[p]=q;
		vis[u]=1;
	}
	for (int i=ne[0];i!=n+1;){
		if (!vis[i]&&!e[u].count(i)){
			dfs(i);
			i=find(i);
		}
		else
			i=ne[i];
	}
}
int main()
{
	int m;
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		ne[i]=i+1,pre[i]=i-1;
	ne[0]=1;
	for (int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].insert(v);
		e[v].insert(u);
	}
	int cnt=0;
	for (int i=ne[0];i!=n+1;){
		dfs(i);
		cnt++;
		i=find(i);
	}
	cout<<cnt-1;
	return 0;
}
