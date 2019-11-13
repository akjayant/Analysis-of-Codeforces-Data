#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long q=1;
    cin>>q;
    while(q--)
    {
        ll n,ma=0;
        vector<ll> a;
        cin>>n;
        a.resize(n);
        for(ll i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end(),greater<int>());
        for(ll i=0;i<n;++i)
        {
            ma=max(ma,min(i+1,a[i]));
        }
        cout<<ma<<endl;
    }
    return 0;
}
