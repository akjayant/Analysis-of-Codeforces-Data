#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef  long long  int ll;
typedef  long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll n;
string s;
int main() {
    ios :: sync_with_stdio(false); cin.tie(0);
   ll t;cin>>t;
    while(t--) {
    	cin>>n>>s;
    	if(s[0] == '1' || s[n-1] == '1') {
    		cout<<2*n<<'\n';
    		continue;
    	}
    	ll ans = n; ll tt = 0;
    	rep(i,0,n-1) if(s[i] == '1') {
    		tt ++;
    		ans = max(ans,2+2*max(i,n-1-i));
    	}
    	ans = max(ans,n+tt);
    	cout<<ans<<'\n';
    }
}
