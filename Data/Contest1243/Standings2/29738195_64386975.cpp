#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        ll ans=1,mn=INT_MAX;
        for(ll i=n-1;i>=0;i--)
        {
            if(a[i]>=ans)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        cout << ans-1 << endl;
    }
    return 0;
}