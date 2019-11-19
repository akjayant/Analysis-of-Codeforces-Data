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


int n;
ll a[MAXN];

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++)scanf("%lld", &a[i]), sum += a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n / 2; i++)ans += a[i];
    printf("%lld\n", ans * ans + (sum - ans) * (sum - ans));
    return 0;
}