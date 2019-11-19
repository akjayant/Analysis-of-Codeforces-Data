#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll gcdd(ll f, ll s, ll *fi, ll *si); 
ll inverse(ll b, ll m) 
{ 
    ll x, y;
    ll g = gcdd(b, m, &x, &y); 
    return (x%m + m) % m; 
} 
ll div(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = inverse(b, m); 
    return ((inv * a) % m); 
} 
ll gcdd(ll f, ll s, ll *fi, ll *si) 
{
    if (f == 0) 
    { 
        *fi = 0, *si = 1; 
        return s; 
    } 
  
    ll xx, yy;
    ll g = gcdd(s%f, f, &xx, &yy); 
    *fi = yy - (s/f) * xx; 
    *si = xx; 
    return g; 
} 

int main()
{
    
    vector<ll> arr(100005,0);
    
    arr[0]=1;
    for(ll i=1;i<100005;i++)
    {
        arr[i]=arr[i-1]*i;
        arr[i]%=mod;
    }
    ll sol=0;
    ll l=0;
    ll n,m;
    cin>>n>>m;
    ll i,j,kk=0;
    for(i=0;i<=n/2;i++)
    {
        kk=n-i;
        j=i;
        l=arr[kk];
        l=div(l,arr[j],mod);
        l=div(l,arr[kk-j],mod);
        sol+=2*l;
        sol%=mod;

    }
    for(i=1;i<=m/2;i++)
    {
        kk=m-i;
        j=i;
        l=arr[kk];
        l=div(l,arr[j],mod);
        l=div(l,arr[kk-j],mod);
        sol+=2*l;
        sol%=mod;
    }
    sol%=mod;
    cout<<sol<<endl;
    
    return 0;
}