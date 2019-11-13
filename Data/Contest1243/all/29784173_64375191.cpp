#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        int x;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[x]++;
        }
        int sum = 0;
        for (int i = 1000; i >= 1; i--) {
            sum += a[i];
            if (sum >= i) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
