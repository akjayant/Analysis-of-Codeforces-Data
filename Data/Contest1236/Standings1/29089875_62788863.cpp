#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define pri (ll)1e9+7
using namespace std;
void masterstroke(){
	ll a,b,c;
	cin>>a>>b>>c;
	
	ll f=0;
	
	for(ll i=0;i<=a;i++){
		
		if(b<2*i)break;
		
		ll ans=3*i;
		
		ll j=b-2*i;
	
		ll z=((min(2*j,c))/2);
		ans+=3*z;
		f=max(f,ans);
	
		
	}
	cout<<f<<endl;
	}

int main() {
	//cout<<pri+3;
	ll t=1;
	cin>>t;
	for(ll i=0;i<t;i++)masterstroke();

	// your code goes here
	return 0;
}