#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, mod = 1e9 + 7;
int n,m,f[N];
template<class T> inline void read(T &x) {
    bool f = false; x = 0;
    char ch = getchar();
    while (ch<'0' || ch>'9') {if (ch == '-') f = true; ch = getchar();}
    while (ch>='0' && ch<='9') x = x * 10 + ch - '0', ch = getchar();
    if (f) x = -x;
}
signed main() {
    read(n), read(m);
    if (n > m) swap(n, m);
    f[1] = 2, f[2] = 4;
    for (int i = 3; i <= m;i++) {
        f[i] = (f[i-2] + f[i-1]) % mod;
    }
    int ans =(( (f[m] + f[n]) % mod - 2 )%mod+ mod)%mod;
    cout<<ans<<endl;
    return 0;
}