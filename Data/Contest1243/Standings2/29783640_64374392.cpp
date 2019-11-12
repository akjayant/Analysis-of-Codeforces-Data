#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define F first
#define S second
//cout<<fixed<<setprecision(11);
const string nl="\n";
const ll MOD=1000000007;
const ll ARR_MAX = 1e5+1;

void solve(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans;
	for(int i=n-1;i>=0;i--){
		int x=n-i;
		if(a[i]>=x){
			ans=x;
		}
	}
	cout<<ans<<nl;
}

int main(){
    fastio();
    int t=1;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}