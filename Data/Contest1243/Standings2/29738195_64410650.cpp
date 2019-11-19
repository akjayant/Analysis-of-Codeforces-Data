#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    vector<ll>v;
    for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        if(v.size()==0)
        {
            cout << n;return 0;
        }
    ll ans=v[0];
    for(ll i=0;i<v.size();i++)
    {
        ans=__gcd(ans,v[i]);
    }
    cout << ans;
    return 0;
}