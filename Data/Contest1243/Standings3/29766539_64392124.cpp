#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = pow(10,9)+7;
ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll v[2000000];
    ll k=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v[k++]=i;
            v[k++]=n/i;
        }
    }
    ll g=n;
    for(ll x=0;x<k;x++)
    {
        g=__gcd(g,v[x]);
       // cout<<g<<endl;
    }
    cout<<g<<endl;
    return 0;
}
