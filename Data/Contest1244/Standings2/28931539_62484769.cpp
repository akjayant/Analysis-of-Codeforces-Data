#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ve vector
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define sz(a) (int)(a.size())
//using namespace __gnu_pbds;
using namespace std;

// // // functions: find_by_order  & order_of_key
// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int inf=(int)2e9;
const long long md=1000000007; //1E9+7
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

ll power(ll a,ll p){
	ll ans=1;
	while(p){
		if(p&1) ans*=a;
		p/=2;a*=a; ans%=md;a%=md;
	}
	return ans;
}
ll mdinv(ll a){return power(a,md-2); }

const int N=1e5+10;
int cost[4][N];
vi adj[N];
int vis[N];
vi arr;

void dfs(int i){
	vis[i]=1;
	arr.pb(i);	
	for(int v:adj[i]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
int col[N];


int DP[N][4][4];
int op[N][4][4];

int sol(int i,int x,int y){
	if(i==arr.size()) return 0;
	if(DP[i][x][y]!=-1)
		return DP[i][x][y];

	int ans=LLONG_MAX;
	for(int c=1;c<=3;c++){
		if(c==x||c==y) continue;
		int here=cost[c][arr[i]]+sol(i+1,y,c);
		if(ans>here){
			ans=here;
			op[i][x][y]=c;
		}
	}

	return DP[i][x][y]=ans;
}

signed main(){
	IOS
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cost[1][i];
	}
	for(int i=1;i<=n;i++){
		cin>>cost[2][i];
	}
	for(int i=1;i<=n;i++){
		cin>>cost[3][i];
	}
	forn(i,n-1){
		int a,b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int deg2=0;
	int start=0;
	for(int i=1;i<=n;i++){
		if(sz(adj[i])>2){
			cout<<-1;return 0;
		}
		if(sz(adj[i])==1) start=i;
	}

	dfs(start);
	memset(DP,-1,sizeof(DP));
	cout<<sol(0,0,0)<<"\n";
	int ind=0,x=0,y=0;
	while(ind!=sz(arr)){
		int here=op[ind][x][y];
		col[arr[ind]]=here;
		ind++;
		x=y;
		y=here;
	}
	for(int i=1;i<=n;i++) cout<<col[i]<<" ";
}
