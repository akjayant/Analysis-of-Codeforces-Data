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
	int n;cin>>n;
	while(n--){
		int a,b;cin>>a>>b;
		if(__gcd(a,b)==1){
			cout<<"Finite\n";
		}
		else
			cout<<"Infinite\n";
	}
}
