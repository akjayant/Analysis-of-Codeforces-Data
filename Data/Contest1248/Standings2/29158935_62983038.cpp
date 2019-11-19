#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int a[maxn];

int main() {

    int n; scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    sort(a, a + n);

    ll cnt = 0;
    for (int i = 0; i < n / 2; i++) {
        cnt += a[i];
    }

    printf("%lld", cnt * cnt + (sum - cnt) * (sum - cnt));

    return 0;
}