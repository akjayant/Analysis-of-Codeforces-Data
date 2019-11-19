#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[1005];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, s);
        int m = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') m = min(m, min(i, n-1-i));
        }
        if (m == n) printf("%d\n", n);
        else printf("%d\n", 2*(n-m));
    }
    return 0;
}

