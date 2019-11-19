#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define ll long long int
#define mp make_pair
#define sz(arr) (ll)arr.size()
#define MOD 1000000007

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	forn(i,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	ll ans=0;
	forn(i,n) ans+=arr[i]*arr[i];
	ll store=0;
	forn(i,(n)/2){
		ans+=2*store*arr[i];
		store+=arr[i];
	}
	store=0;
	for(int i=n/2; i<n; i++){
		ans+=2*store*arr[i];
		store+=arr[i];
	}
	cout<<ans;
}
