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

int l,r;
int DP[32][2][2][2][2][2]; //ind 1-> less than l 1-> gr than r

int sol(int ind,int le1,int gr1,int le2,int gr2,int cry){
	if(ind==32) {
		if(le1+gr1+le2+gr2==0) return 1;
		return 0;
	}
	if(DP[ind][le1][gr1][le2][gr2][cry]!=-1) return DP[ind][le1][gr1][le2][gr2][cry]; 
	int low=(l>>ind)&1;int high=(r>>ind)&1;
	int ans=0;
	forn(a,2){
		forn(b,2){
			if((a+b+cry)%2!=(a^b)) continue;
			int nle1=le1,ngr1=gr1,nle2=le2,ngr2=gr2;
			if(a!=low) nle1=(a<low);
			if(a!=high) ngr1=(a>high);
			if(b!=low) nle2=(b<low);
			if(b!=high) ngr2=(b>high);
			int ncry=0;
			if(a+b+cry>1) ncry=1;

			ans+=sol(ind+1,nle1,ngr1,nle2,ngr2,ncry);
		}
	}
	return DP[ind][le1][gr1][le2][gr2][cry]=ans;
}

signed main(){
	IOS
	int tt;cin>>tt;
	while(tt--){
		memset(DP,-1,sizeof(DP));
		cin>>l>>r;
		cout<<sol(0,0,0,0,0,0)<<"\n";
	}
}
