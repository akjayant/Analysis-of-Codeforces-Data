#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
const int mod=1e9+7;
ll f[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    ll ans=2;
    cin>>n>>m;
    int mx=max(n,m);
    f[1]=1;f[2]=2;
    for (int i=3;i<=mx;i++)
        f[i]=(f[i-1]+f[i-2])%mod;
    ll sum=f[n]*2%mod;
    sum=(sum+f[m]*2%mod)%mod;
    ans=(ans+sum-4+mod)%mod;
    cout<<ans<<endl;
    return 0;
}