#include <bits/stdc++.h>
using namespace std;
const int N = 1000005,P = 1000000007;
using ll = long long;
ll qpow(ll a,ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % P;
        a = a * a % P;b >>= 1;
    }
    return ret;
}
ll fac[N],ifac[N];
inline ll C(int a,int b) {return fac[a] * ifac[b] % P * ifac[a - b] % P;}
int main ()
{
    ios::sync_with_stdio(false);
    int n,m;cin >> n >> m;if (n < m) swap(n,m);
    fac[0] = 1;
    for (int i = 1;i <= n;i++) fac[i] = fac[i - 1] * i % P;
    ifac[n] = qpow(fac[n],P - 2);
    for (int i = n;i > 0;--i) ifac[i - 1] = ifac[i] * i % P;
    ll ans = 0;
    for (int i = 1;i <= n / 2;i++) ans = (ans + C(n - i,i)) % P;
    for (int i = 1;i <= m / 2;i++) ans = (ans + C(m - i,i)) % P;
    ++ans;
    cout << ans * 2 % P << endl;
    return 0;
}