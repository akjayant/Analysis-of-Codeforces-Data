#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	ll ans = 0;
    	ll add = min(b,c/2);
    	ans += 3*add;
    	b-=add;
    	c-=2*add;
    	add = min(a,b/2);
    	ans += 3*add;
    	b-=2*add;
    	a-=add;
    	cout<<ans<<endl;
    }
	return 0;
}