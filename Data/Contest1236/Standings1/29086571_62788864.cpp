#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
ll bigmod(ll b,ll p ,ll m)
{
    if(p==0)
        return 1;
    if(p%2 == 0)
    {
        ll temp = bigmod(b,p/2,m);
        return (temp*temp)%m;
    }
    return (bigmod(b,p-1,m)*(b%m))%m;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll mod = 1e9+7;
    ll R = bigmod(2,m,mod);
    R--;
    ll ans = bigmod(R,n,mod);
    cout<<ans<<endl;
}
