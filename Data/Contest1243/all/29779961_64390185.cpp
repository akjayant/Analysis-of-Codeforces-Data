#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

#define MAXN 100010
#define MOD 1000000007
 
using namespace std;
ll power(ll x, ll y, ll p)
{
    ll res = 1; 
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}
ll gcd(ll a, ll b){return __gcd(a,b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    ll x;
    cin>>x;
    while(x--)
    {
        //cout<<x<<": ";
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int f=0,c=0;
        string ns="",nt="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
            {
                c++;
            }
            else
            {
                ns+=s[i];
                nt+=t[i];
            }
        }
        if(c==n-2)
        {
            // cout<<ns<<" "<<nt;
            swap(ns[0],nt[1]);
            if(ns==nt)
            {
            // cout<<ns<<" "<<nt;
                cout<<"Yes\n";
                continue;
            }
            swap(ns[0],nt[1]);
            swap(ns[0],nt[0]);
            
            // cout<<ns<<" "<<nt;
            if(ns==nt)
            {
                cout<<"Yes\n";
                continue;
            }
            swap(ns[0],nt[0]);
            swap(ns[1],nt[1]);
            if(ns==nt)
            {
                cout<<"Yes\n";
                continue;
            }
        }
        cout<<"No\n";
    }
    
    
    
    
    
    
    
    
    return 0;
}