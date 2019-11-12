#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
bool check(pair<ll,ll> p1,pair<ll,ll> p2)
{
    return p2.second>p1.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=0;
        ll temp=min(b,c/2);
        ans+=temp;
        b-=temp;
        temp=min(a,b/2);
        ans+=temp;
        cout<<ans*3<<endl;
    }
	return 0;
}