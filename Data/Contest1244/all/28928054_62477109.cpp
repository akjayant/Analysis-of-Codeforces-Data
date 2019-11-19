#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl;
#define forn(i,n) for(int i=0;i<n;i++)

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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll a = n,b = -1;
        forn(i,n) if(s[i]=='1') b=i;
        for(int i=n-1;i>=0;i--) if(s[i]=='1') a = i;
 
        ll ans = (b+1)*2;
        if((n-a)*2>ans)
          ans = (n-a)*2;
 
        if(a==n &&  b==-1)
          ans = n;
        cout<<ans<<endl;
    }
    return 0;
}