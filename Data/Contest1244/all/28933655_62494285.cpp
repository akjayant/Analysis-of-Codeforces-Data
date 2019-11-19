#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll k;
ll a[100100]; 
int main() {
    scanf("%d %I64d", &n, &k);
    // scanf("%d %lld", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
        // scanf("%lld", &a[i]);

    sort(a, a+n);

    int p = 0;
    int q = 0;
    int ans = 0;
    while (p < n && a[0] == a[p]) p++;
    while (q < n && a[n-1] == a[n-1 - q]) q++;

    while (p + q <= n && k >= 0) {
        if (p <= q) {
            if ((a[p] - a[p-1]) * p <= k) {
                k -= (a[p] - a[p-1]) * p;

                int pp = p;
                while (p < n && a[pp] == a[p]) p++;
            } else {
                a[p-1] += k/p;
                break;
            }
        }
        else {
            if ((a[n-q] - a[n-1-q]) * q <= k) {
                k -= (a[n-q] - a[n-1-q]) * q;

                int qq = n-1-q;
                while (q < n && a[qq] == a[n-1-q]) q++;
            } else {
                a[n-q] -= k/q;
                break;
            }
        }
    }

    if (p+q > n)
        printf("0\n");
    else
        printf("%I64d\n", a[n-q] - a[p-1]);
        // printf("%lld\n", a[n-q] - a[p-1]);

    return 0;
}
