#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = pow(10,9)+7;

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<ll>());
        ll ans=0;
        ll x=pow(10,5);
        for(ll i=0;i<n;i++)
        {
            x=min(x,a[i]);
            ans=max(ans,min(i+1,x));
        }
        cout<<ans<<endl;
    }
    return 0;
}
