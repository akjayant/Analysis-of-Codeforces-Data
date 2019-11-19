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
	ll n;cin>>n;
	ll a[n];rep(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll x=0,y=0,c=0;
	for(ll i=n-1;i>=0;--i){
		x+=a[i];c++;
		if(c==n)break;
		y+=a[n-i-1];c++;
		if(c==n)break;
	}
	ll ans=(x*x)+(y*y);
	// tell(x,y);
	cout<<ans;
	
	return 0;
}

