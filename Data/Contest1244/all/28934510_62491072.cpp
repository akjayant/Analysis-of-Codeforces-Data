#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define chrng(n,a,b)      (((n)>=(a))&&((n)<=(b)))
#define clamp(n,a,b)      (((n)<(a))?(a):((((n)>(b))?(b):(n)))

int c[100005][3];
vector<int> p[6];
int w[100005][6];

vector<int> v[100005];int vis[100005];
int dfs(int z,int q,int a){
	vis[z]=1;
	int ans=0;
	for(int x:v[z]){
		if(vis[x])continue;
		ans+=dfs(x,(q+1)%3,a);
	}
	ans+=c[z][p[a][q]];
	w[z][a]=p[a][q];
	return ans;
}
void solve(){
	int n;
	cin>>n;
	rep(j,0,3)
	for(int i=1;i<=n;i++){
		cin>>c[i][j];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int t=0,l;
	rep(i,1,n+1){
		t=max(t,(int)v[i].size());
		if(v[i].size()==1)l=i;
	}
	if(t>2){
		cout<<-1;
		return;
	}
	p[0]={0,1,2};
	p[1]={0,2,1};
	p[2]={1,0,2};
	p[3]={1,2,0};
	p[4]={2,0,1};
	p[5]={2,1,0};
	t=-1;int ap=0;
	rep(i,0,6){
		mem0(vis);
		int k=dfs(l,0,i);
		if(t==-1||k<t){
			t=k;ap=i;
		}
		// cout<<t<<" "<<i<<"\n";
	}
	cout<<t<<"\n";
	rep(i,1,n+1){
		cout<<w[i][ap]+1<<" ";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
