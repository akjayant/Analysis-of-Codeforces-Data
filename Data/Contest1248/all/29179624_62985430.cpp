#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int n, a[maxn];
ll rec1, rec2;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int mid = n / 2;
    for (int i = n; i > mid; --i) rec1 += a[i];
    for (int i = 1; i <= mid; ++i) rec2 += a[i];
    printf("%lld\n", rec1 * rec1 + rec2 * rec2);
    return 0;
}