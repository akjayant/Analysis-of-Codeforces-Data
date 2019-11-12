#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=200010;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ar[n];
        for(ll i=0;i<n;++i){cin>>ar[i];}
        sort(ar,ar+n);
        ll ans=0,idx;
        reverse(ar,ar+n);
        for(ll i=0;i<n;++i)
        {
            ll side=min(ar[i],i+1);
            ans=max(ans,side);
        }
        cout<<ans<<endl;
    }

    return (0);
}
