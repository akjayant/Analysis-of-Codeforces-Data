#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define M 1000010

int main(){
	IOS;
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll ep=0;
		ll p[n];rep(i,0,n){cin>>p[i];if(p[i]%2==0)ep++;}
		ll m;cin>>m;
		ll q[m];
		ll eq=0;
		rep(i,0,m){cin>>q[i];if(q[i]%2==0)eq++;}
		ll ans=(ep*eq)+(n-ep)*(m-eq);
		cout<<ans<<"\n";
	}
	
	return 0;
}

