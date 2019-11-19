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


int solve(int n,int k,vi& v){
	sort(all(v));
	vi vsum(n);
	vsum[0]=v[0];
	
	for(int i=1;i<n;i++)
		vsum[i]=vsum[i-1]+v[i];

	vi leftLine(n),lsum(n+1);
	vi rightLine(n),rsum(n+1);
	forn(i,n){
		leftLine[i]=v[i]-v[0];
	}
	lsum[0]=0;
	for(int i=1;i<n;i++)
		lsum[i]=lsum[i-1]+leftLine[i];

	forn(i,n){
		rightLine[i]=v.back()-v[i];
	}
	rsum[n-1]=0;
	for(int i=n-2;i>=0;i--)
		rsum[i]=rsum[i+1]+rightLine[i];

	int store=LLONG_MAX;

	// cout<<"inp :";
	// for(int i:v) cout<<i<<" ";
	// cout<<endl;
	// cout<<"leftLine :";
	// for(int i:leftLine) cout<<i<<" ";
	// cout<<endl;
	// cout<<"rightLine :";
	// for(int i:rightLine) cout<<i<<" ";
	// cout<<endl;

	for(int ind=0;ind<n;ind++){
		int bringLeft=rsum[0]-rsum[ind];
		bringLeft-=rightLine[ind]*ind;
		// cout<<ind<<" "<<bringLeft<<endl;
		if(bringLeft>k) continue;
		int l=v[ind],r=v.back();
		int ans=INT_MIN;
		while(l<=r){
			int mid=(l+r)/2;
			int loc=upper_bound(all(v),mid)-v.begin();
			int noele=n-loc;
			int bringRight=vsum[n-1];
			if(loc)
				bringRight-=vsum[loc-1];

			bringRight-=mid*noele;
			if(bringRight+bringLeft>k){
				l=mid+1;
			}
			else{
				ans=mid;
				r=mid-1;
			}
		}
		if(ans!=INT_MIN){
			int here=ans-v[ind];
			store=min(store,here);
		}
	}
	return store;
}

signed main(){
	IOS
	int n,k;cin>>n>>k;
	vi v(n);
	forn(i,n) cin>>v[i];
	int ans=LLONG_MAX;
	ans=min(ans,solve(n,k,v));
	int mx=*max_element(all(v));
	forn(i,n) v[i]=mx-v[i];
	ans=min(ans,solve(n,k,v));
	cout<<ans;	
}
