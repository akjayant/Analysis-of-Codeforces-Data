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

    ll n;
    cin>>n;
    ll ans=n;
    vector<ll> ar;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ar.pb(i);
            if(i*i!=n)
            {
                ar.pb(n/i);
            }
        }
    }
    if(ar.size()==0){cout<<ans;return(0);}
    ans=0;
    for(ll i=0;i<ar.size();++i)
    {
        ans=__gcd(ans,ar[i]);
    }
    cout<<ans<<endl;

    return (0);
}
