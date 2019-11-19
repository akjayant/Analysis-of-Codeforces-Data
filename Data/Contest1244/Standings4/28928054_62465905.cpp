#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl;

using namespace std;

ll power(ll x, unsigned ll y, ll p) 
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,k,i,j;
        cin>>a>>b>>c>>d>>k;
        i=a/c;
        if(a%c!=0)
            i++;
        j=b/d;
        if(b%d!=0)
            j++;
        if(i+j<=k)
            cout<<i<<" "<<j<<endl;
        else 
            cout<<"-1\n";
    }
    return 0;
}