#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<int,pi>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector <ll> v;
ll ans;
int main()
{
    go;
    ll n;
    cin>>n;
    if(n==1)
        return cout<<1,0;
    ans=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll j=n/i;
            ans=__gcd(ans,i);
            ans=__gcd(ans,j);
        }
    }
    cout<<ans;
    return 0;
}
