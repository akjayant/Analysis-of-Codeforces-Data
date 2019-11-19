#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,c1[N],c2[N],c3[N],w[N],dd[3][3],res=3e18,col[N];
vector<int>g[N],d[3];
void dfs(int v){
	for(auto&u:g[v]){
		if(w[u]>w[v]+1){
			w[u]=w[v]+1;
			dfs(u);
		}
	}
}
signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	fill(w,w+N,1e9);
	for(int i=0;i<n;++i)cin>>c1[i];
	for(int i=0;i<n;++i)cin>>c2[i];
	for(int i=0;i<n;++i)cin>>c3[i];
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int vv=0;
	for(int i=0;i<n;++i){
		if(g[i].size()>2){
			cout<<-1;
			return 0;
		}
		if(g[i].size()==1){
			vv=i;
		}
	}
	w[vv]=0;
	dfs(vv);
	for(int i=0;i<n;++i){
		d[w[i]%3].push_back(i);
		dd[w[i]%3][0]+=c1[i];
		dd[w[i]%3][1]+=c2[i];
		dd[w[i]%3][2]+=c3[i];
	}
	int x=0,y=0,z=0;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<3;++k){
				if(i!=j&&i!=k&&k!=j){
					int op=dd[0][i]+dd[1][j]+dd[2][k];
					if(op<res){
						x=i;
						y=j;
						z=k;
						res=op;
					}
				}
			}
		}
	}
	for(int j=0;j<d[0].size();++j)col[d[0][j]]=x;
	for(int j=0;j<d[1].size();++j)col[d[1][j]]=y;
	for(int j=0;j<d[2].size();++j)col[d[2][j]]=z;
	cout<<res<<'\n';
	for(int i=0;i<n;++i)cout<<col[i]+1<<' ';
}