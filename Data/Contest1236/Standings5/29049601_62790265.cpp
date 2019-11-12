using namespace std;
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int mod =  1000000007;
vector<int> fac, ifac;

int power (int base, int exp, int mod)
{
    int res = 1;
    base%=mod;
    while(exp)
    {
        if (exp & 1)
        {
            res*=base;
            res%=mod;
        }
        exp>>=1;
        base*=base;
        base%=mod;
    }
    return res;
}

int inv (int arg, int mod)
{
    return power(arg, mod-2, mod);
}

void preCompute(int sz)
{
    fac.resize(sz+1);
    ifac.resize(sz+1);
    fac[0]=1;
    for (int i=1; i<=sz; i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    ifac[sz]=inv(fac[sz],mod);
    for (int i=sz-1; i>=0; i--)
        ifac[i]=(ifac[i+1]*(i+1))%mod;
}

int nCr (int n, int r)
{
    if (n>=r && r>=0)
        return (((fac[n]*ifac[n-r])%mod)*ifac[r])%mod;
    return 0;
}

signed main ()
{
    IOS;
    int n,m; cin>>n>>m;
    int x = power(2,m,mod)-1;
    x = (x + mod)%mod;
    int y = power(x,n,mod);
    cout<<y;

    
}
