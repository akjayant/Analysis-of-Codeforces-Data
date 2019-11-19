#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long int
#define hell 1000000007LL
using namespace std;
ll power(ll x, ll y){ 
    if(y==0)
     return 1;
    else
    {
        ll p=power(x,y/2);
        if(y%2==0)
         return (p*p)%hell;
        else
        return (x*((p*p)%hell))%hell;
    }}
ll gcd(ll x,ll y)
{
    if(y==0)
     return x;
    else
    return gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    ll n,c=0;
    cin>>n;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
             c++;
            else
             c=c+2;
        }
    }
    if(c==1||c==2)
     cout<<n;
    else
    {
        set<ll>s;
        while(n%2==0)
        {
            s.insert(2);
            n=n/2;
        }
        for(ll i=3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
            {
                s.insert(i);
                n=n/i;
            }
        }
        if(n>2)
         s.insert(n);
        if(s.size()==1)
        {
            for(auto it=s.begin();it!=s.end();it++)
             cout<<*it;
        }
        else
        {
            cout<<1;
        }
    }
    }