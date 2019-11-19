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


int n, k, T, m;
int a[MAXN], b[MAXN], cnt[2];

int main() {
    scanf("%d", &T);
    while (T--) {
        cnt[0] = cnt[1] = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)scanf("%d", &a[i]), cnt[a[i] % 2]++;
        scanf("%d", &m);
        ll ans = 0;
        for (int i = 1; i <= m; i++)scanf("%d", &b[i]), ans += cnt[b[i] % 2];
        printf("%lld\n", ans);
    }
    return 0;
}