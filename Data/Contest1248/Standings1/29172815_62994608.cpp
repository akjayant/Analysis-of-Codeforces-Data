#define mm(a) memset(a,0,sizeof(a));
#define max(x, y) (x)>(y)?(x):(y)
#define min(x, y) (x)<(y)?(x):(y)
#define Fopen freopen("1.in","r",stdin); freopen("m.out","w",stdout);
#define rep(i, a, b) for(int i=(a);i<=(b);i++)
#define per(i, b, a) for(int i=(b);i>=(a);i--)
#define PII pair<ll,ll>

#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;


ll f[MAXN];
int n, m;

int main() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 100000; i++)f[i] = (f[i - 1] + f[i - 2]) % mod;
    scanf("%d%d", &n, &m);
    ll ans = (f[n] + f[m] - 1) * 2 % mod;
    ans %= mod;
    ans += mod;
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}