#include<bits/stdc++.h>
#define lson sign << 1, l, mid
#define rson sign << 1 | 1, mid + 1, r
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f;
const long long inv2 = 500000004;
const int maxn = 1e5 + 5;

ll power(ll a, ll b, ll c) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = ans * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return ans % c;
}
int a[maxn];
int main() {
    int n, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int m = 0;
        for(int i = 1; i <= n; i++) {
            m = max(m, min(n - i + 1, a[i]));
        }
        printf("%d\n", m);
    }
    return 0;
}
