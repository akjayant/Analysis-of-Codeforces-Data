#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define sp fixed<<setprecision
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define bp __builtin_popcount
#define int ll
using namespace std;
ll M = (1e9)+7;
ll mpower(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1){
            res = (res*x) % p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int a[n+1][n+1],in=1;
        for(int j=1;j<=n;j++)
        {
            if(j%2)for(int i=1;i<=n;i++)a[i][j]=in++;
            else for(int i=1;i<=n;i++)a[n+1-i][j]=in++;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

/*

*/
