//amitgomi
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
 
///////////////////////////////////////////////////////////
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// ordered_set st;
// st.order_of_key(l);
// double PI=3.1415926535897932384626;
// ll bin_expo(ll a,ll b, ll m){ ll res =1; a %= m; while(b!=0){ if(b%2==1) res = (res*a)%mod; a = (a*a)%mod; b = b/2; } return res; }
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); } 
///////////////////////////////////////////////////////////////////////////////////////////////////

int cr[100005][4];

vector <int> v[100005];
vector <int> ar;
int cnt=0;

int dfs(int x,int par){
	ar.push_back(x);
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]==par)
			continue;
		dfs(v[x][i],x);
	}
	return 0;
}

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cr[i][0];
	for(int i=1;i<=n;i++)
		cin>>cr[i][1];
	for(int i=1;i<=n;i++)
		cin>>cr[i][2];

	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int a = 0;
	for(int i=1;i<=n;i++){
		if(v[i].size()>2){
			cout<<-1<<endl;
			return 0;
		}
		if(v[i].size()==1)
			a = i;
	}
	dfs(a,a);
	int br[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

	ll cost = 1e17;
	a=0;
	for(int i=0;i<6;i++){
		ll sum=0;
		for(int j=0;j<n;j++){
			sum += cr[ar[j]][br[i][j%3]];
		}
		if(sum<cost){
			cost = sum;
			a = i;
		}
	}
	cout<<cost<<endl;
	int ans[n];
	for(int i=0;i<n;i++){
		ans[ar[i]] = br[a][i%3]+1;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}