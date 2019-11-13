#include<bits/stdc++.h>
#define ll long long
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;

ll modexp(ll x, ll n)
{
    if(n==0)
        return 1LL;
    if(n%2==0)
    {
        ll y = modexp(x,n/2)%mod;
        return (y*y)%mod;
    }
    return (x*modexp(x,n-1)%mod)%mod;
}

ll powr(ll x, ll n)
{
    ll ans = 1;
    for(int i=1;i<=n;i++)
        ans=ans*x;
    return ans;
}

int main() 
{    
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    si(n);
    
    int a[n+1][n+1];
    int tot = n*n;
    int ct = 1;
    for(int i=1;i<=n;++i) 
    {
        if(i&1) 
        {
            for(int j=1;j<=n;++j) 
            {
                a[j][i]=ct++;
            }
        }
        else {
            for(int j=n;j>=1;--j) 
            {
                a[j][i]=ct++;
            }
        }
    }
    for(int i=1;i<=n;++i) 
    {
        for(int j=1;j<=n;++j) 
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
