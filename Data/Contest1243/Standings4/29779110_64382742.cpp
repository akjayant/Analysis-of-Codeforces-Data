#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const ll inf=1e18;
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
    ll t1;
    cin>>t1;
    while(t1--)
    {
       ll n,i,a,b,c;
       string s,t;
       cin>>n;
       cin>>s;
       cin>>t;
       vector<ll>v;
       for(i=0;i<n;i++)
       {
           if(s[i]!=t[i])
           {
               v.pb(i);
           }
       }
       if(v.size()>2 || v.size()==1)
       {
           cout<<"No"<<endl;
           continue;
       }
       if(s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]])
        cout<<"Yes"<<endl;
       else
        cout<<"No"<<endl;
    }
}
