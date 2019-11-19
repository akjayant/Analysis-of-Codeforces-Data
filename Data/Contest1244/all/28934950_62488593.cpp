#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define X first
#define Y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
#define de(x,y) cout<<#x<<" "<<x<<y;
#define pray(a,i,n_thing) for(int x=i;x<=(i+n_thing);x++) cout<<#a<<"["<<x<<"] :"<<a[x]<<endl;
#define mem(aa,x) memset(aa,x,sizeof aa)
#define pb push_back
typedef long long ll;
typedef pair<int,int> ii;
const int maxn=4e5+5;
int arr[maxn];
vector<int> G[maxn];
int color[5][maxn];
vector<int> idx;
void dfs(int fa,int now) {
	idx.pb(now);
	for(int k:G[now]) {
		if(k == fa) continue;
		dfs(now,k);
	}
	
}
int ans[maxn];
int cc[5] = {1,2,3};
main(){IOS
	int n;
	cin>>n;
	for(int i=1;i<=3;i++) {
		rep(j,1,n) {
			cin>>color[i][j];
		}
	}
	bool fg = 0;
	int root = 0;
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
		if(G[u].size() > 2 || G[v].size() >2) 
			fg = 1;
		
	}
	if(fg) {
		cout<<"-1\n";
		return 0;	
	}
	for(int i=1;i<=n;i++) {
		if(G[i].size()==1){
			dfs(0,i);
			break;
		}
	}
	int sum = 1e17;
	do{
		int tmp = 0;
		for(int i=0;i<idx.size();i++) {
			int now = idx[i];
			tmp+= color[ cc[ i%3 ] ][ now ];
		}
		if(tmp < sum) {
			for(int i=0;i<idx.size();i++) {
				int now = idx[i];
				ans[now] = cc[i%3];
//				tmp+= color[ cc[ i%。3 ] ][ now ];
			}
			sum = tmp;
		}
	}while(next_permutation(cc,cc+3));
	cout<<sum<<"\n";
	for(int i=1;i<=n;i++) {
		cout<<ans[i]<<" ";
	}
}

