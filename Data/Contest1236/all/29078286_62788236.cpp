#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 998244353
#define ff first
#define ss second
#define endl '\n'
using namespace std;
/*ll power(ll x,ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return res;
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll a,b,c;
       cin>>a>>b>>c;
       ll s=0,k=0;
       s=min(b,c/2);
       b=b-s;
       s=s*3;
       s=s+min(a,b/2)*3;
       cout<<s<<endl;
   }
}
