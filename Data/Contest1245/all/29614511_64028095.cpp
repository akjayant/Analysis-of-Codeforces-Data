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

long double DP[12][12];
int vis[12][12];
int h[12][12];

long double sol(int i,int j){
	if(i==9 && j==0) return 0;

	if(vis[i][j]) return DP[i][j];
	vis[i][j]=1;
	long double ans=0;

	if(i==9 && j<=6){
		int gr=6-j;
		int le=6-gr;
		for(int x=1;x<=j;x++){
			ans+=sol(i,j-x);
		}
		ans/=le;ans+=6/((long double)le);
		return DP[i][j]=ans;
	}

	if(i%2==0){
		for(int d=1;d<=6;d++){
			int ni=i,nj=j+d;
			if(nj>=10) {
				nj-=10,ni++;
				nj=9-nj;
			}
			if(ni>9) continue;
			long double f1=1+min(sol(ni,nj),sol(ni+h[ni][nj],nj));
			ans+=f1/6;
		}
	}
	else{
		for(int d=1;d<=6;d++){
			int ni=i,nj=j-d;
			if(nj<0) {
				nj+=10,ni++;
				nj=9-nj;
			}
			if(ni>9) continue;
			long double f1=1+min(sol(ni,nj),sol(ni+h[ni][nj],nj));
			ans+=f1/6;
		}
	}
	return DP[i][j]=ans;
}

signed main(){
	IOS
	forn(i,10) forn(j,10) cin>>h[9-i][j];
	cout<<setprecision(12)<<sol(0,0)<<endl;
}
