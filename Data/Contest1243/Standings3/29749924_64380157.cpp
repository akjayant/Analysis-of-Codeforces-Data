#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define mod 1000000007
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define Find find_by_order
#define Pos order_of_key
#define N 1000000
ll power(ll n,ll p)
{
    if(p==0) return 1;
    ll P=power(n,p/2);
    if(p%2==0) return ((((P%mod)*(P%mod))%mod)*(1%mod))%mod;
    if(p%2==1) return ((((P%mod)*(P%mod))%mod)*(n%mod))%mod;
}
ll prime(ll n)
{
    if(n==1) return 0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
ll fact[N+1];
ll inv[N+1];
ll pre()
{
    fact[0]=1;
    inv[0]=1;
    for(int i=1;i<=N;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=power(fact[i],mod-2)%mod;
    }
}
ll ncr(ll n,ll r)
{
    if(n<r) return 0;
    if(r==0 || r==n) return 1;
    return (((fact[n]*inv[r])%mod)*inv[n-r])%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<char> c1,c2;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i]) continue;
            c1.pb(s[i]);
            c2.pb(t[i]);
        }
        if(c1.size()==0) 
        {
            cout<<"YES";
        }
        else if(c1.size()==2)
        {
            if(c1[1]==c1[0] && c2[1]==c2[0])
            {
                cout<<"YES";
            }
            else
            {
                cout<<"NO";
            }
        }
        else 
        {
            cout<<"NO";
        }
        cout<<"\n";
    }
}