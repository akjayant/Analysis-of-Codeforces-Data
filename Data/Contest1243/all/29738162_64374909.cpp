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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
         cin>>a[i];
        for(int i=n;i>=0;i--)
        {
            int c=0,f=0;
            for(int j=n-1;j>=0;j--)
            {
                if(a[j]>=i)
                 c++;
            }
            if(c>=i)
            {
                cout<<i;
                f++;
                break;
            }
            if(f)
             break;
        }
        cout<<"\n";
    }}
        
        
        
        
    
        