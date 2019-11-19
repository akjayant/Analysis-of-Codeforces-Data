#include <bits/stdc++.h>
using namespace std;
#define opt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long int
// I might be a loser, but I have nothing to lose :p
int main()
{
opt;
ll n,ans;
cin>>n;
if(n<=3)
{
    cout<<n;
    return 0;
}
vector<ll> f;
for(ll i=2 ; i<=(ll)(sqrtl(n));i++)
{
    if(n%i==0)
    {
        f.push_back(i);
        f.push_back(n/i);
    }
}
if(f.empty()==1)
{
    cout<<n;
}
else if(f.size()==1)
{
    cout<<f[0];
}
else
{
    ans=__gcd(f[0],f[1]);
    for(int i=2;i<f.size();i++)
    {
        ans=__gcd(ans,f[i]);
    }
    cout<<ans;
}
return 0;
}