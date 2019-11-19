#include <bits/stdc++.h>
#define fi first
#define se second
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int n, a[N];

int main() {
    scanf("%d", &n);
    ll s = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), s += 1LL * a[i];
    sort(a + 1, a + 1 + n);
    ll x = 0;
    for(int i = 1; i <= n/2; i++) x += a[i];
    ll y = s - x;
    printf("%lld\n", x*x + y*y);
    return 0;
}
