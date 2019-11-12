#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[2010];
int main()
{
    ll t,n,i,j,k,l;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (i=0;i<n;i++)
            cin>>arr[i];
        sort (arr,arr+n);
        ll ans=0;
        for (i=n-1;i>=0;i--)
        {
            ll p = arr[i];
            ll q = n-i;
            ll r = min(p,q);
            ans=max(ans,r);
        }
        cout<<ans<<'\n';
    }
    return 0;
}