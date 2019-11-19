#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mp make_pair
#define pb push_back

int main()
{
    //boost
    ll t;
    ll n,i;
    cin>>n;
    t=n;
    vector<ll>v;
    for(i=2;i*i<=n;i++)
    {
        if(t%i==0)
        {
            v.pb(i);
            while(t%i==0)
            {
                t/=i;
            }
        }
    }
    if(t>1)
        v.pb(t);
    ll ans = 0;
    if(v.size()==0)
    {
        ans = n;
    }
    if(v.size()==1)
    {
        ans = v[0];
    }
    if(v.size()>1)
    {
        ans = 1;
    }
    cout<<ans<<"\n";
}


