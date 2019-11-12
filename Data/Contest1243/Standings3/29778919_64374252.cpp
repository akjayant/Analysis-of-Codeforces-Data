#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[n - 1 - i] >= i + 1) {
                ans = i + 1;
            }
        }
        printf("%d\n", ans);
    }
}