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
const long long mod=1000000007; //1E9+7
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

ll powmod(ll a,ll p){
	ll ans=1;
	while(p){
		if(p&1) ans*=a;
		p/=2;a*=a; ans%=mod;a%=mod;
	}
	return ans;
}
ll mdinv(ll a){return powmod(a,mod-2); }

signed main(){
	IOS
	int tt;cin>>tt;
	ve<char> v;
	ve<bool> vis;
	while(tt--){
		int n;cin>>n;
		v.assign(n,'S');
		vis.assign(n,0);
		int a,b,c;cin>>a>>b>>c;
		string s;cin>>s;
		int ind=0;
		while(ind<n && a){
			if(s[ind]=='S'){
				a--;v[ind]='R';
				vis[ind]=1;
			}
			ind++;
		}
		ind=0;
		while(ind<n && b){
			if(s[ind]=='R'){
				b--;v[ind]='P';
				vis[ind]=1;
			}
			ind++;
		}
		ind=0;
		while(ind<n && c){
			if(s[ind]=='P'){
				c--;v[ind]='S';
				vis[ind]=1;
			}
			ind++;
		}
		for(int i=0;i<n;i++){
			if(a && !vis[i]){
				vis[i]=1;
				a--;v[i]='R';
			}
			else if(b && !vis[i]){
				vis[i]=1;
				b--;v[i]='P';
			}
			else if(c && !vis[i]){
				vis[i]=1;
				c--;v[i]='S';
			}
		}
		int score=0;
		for(int i=0;i<n;i++){
			if(v[i]=='R' && s[i]=='S') score++;
			else if(v[i]=='P' && s[i]=='R') score++;
			else if(v[i]=='S' && s[i]=='P') score++;
		}
		int least=(n+1)/2;
		if(score>=least){
			cout<<"YES\n";
			for(char c:v) cout<<c;
			cout<<"\n";
		}
		else cout<<"NO\n";
	}
}
