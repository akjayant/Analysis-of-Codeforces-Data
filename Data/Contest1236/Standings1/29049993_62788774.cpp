#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long modpow(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a,b,c;
    cin>>a>>b;
    c=(modpow(2,b)-1+mod)%mod;
    c=modpow(c,a);
    cout<<c;
}
