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
    	ll a,b,c,d,k;
    	cin>>a>>b>>c>>d>>k;
    	ll x = (a-1)/c + 1;
    	ll y = (b-1)/d + 1;
    	if(x+y <= k)
    		cout<<x<<' '<<y<<endl;
    	else
    		cout<<"-1"<<endl;
    }
	return 0;
}