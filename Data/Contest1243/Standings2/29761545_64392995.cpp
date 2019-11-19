#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=1e18*4;
const ld pai=acos(-1);
ll n;
int main(){
	cin>>n; 
	vll v;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			v.pb(i);
			if(n/i!=i)v.pb(n/i);
		}	
	}
	sort(v.begin(),v.end());
	if(v.size()==0)cout<<n<<endl,exit(0);
	ll G=v[0];
	for(ll i=1;i<v.size();i++)G=__gcd(G,v[i]);
	cout<<G<<endl;
}
