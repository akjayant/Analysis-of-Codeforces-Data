#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define ll long long int
#define mp make_pair
#define sz(arr) (ll)arr.size()
#define MOD 1000000007

using namespace std;

void func(){
	int n;
	cin>>n;
	ll odd1=0;
	ll even1=0;
	forn(_,n){
		ll x;
		cin>>x;
		if (x%2==1) odd1++;
		else even1++;
	}
	int m;
	cin>>m;
	ll odd2=0;
	ll even2=0;
	forn(_,m){
		ll x;
		cin>>x;
		if (x%2==1) odd2++;
		else even2++;
	}
	ll ans=odd1*odd2+even1*even2;
	cout<<ans<<'\n';
}

int main(){
	int T;
	cin>>T;
	forn(i,T) func();
}
