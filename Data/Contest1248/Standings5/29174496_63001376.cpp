#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FOD(i,a,b) for(int i=(a);i>=(b);--i)
#define fs first
#define sc second

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const ll mod=1e9+7;
const int N=1e5+10;

int n,m;
ll f[N];
ll g[N];
ll ans;



int main()
{
    if (fopen("exam.inp","r"))
    {
        freopen("exam.inp","r",stdin);
        freopen("exam.out","w",stdout);
    }

    cin >> n >> m;
    if (n>m) swap(n,m);
    f[1]=2ll;
    f[2]=4ll;
    FOR(i,3,m)
    {
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
    }
    g[1]=0ll;
    g[2]=2ll;
    g[3]=2ll;
    FOR(i,4,n)
    {
        g[i]=g[i-1]+g[i-2];
        g[i]%=mod;
    }
    ll res=0;
    FOR(i,1,n)
    {
        res=res+g[i];
        res%=mod;
    }

    ans=res+f[m];
    ans%=mod;

    cout << ans << endl;

    return 0;
}

