#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e6+10;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        sort(a+1, a+1+n);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res = max(res, min(a[i], n - i+1));
        }
        printf("%d\n", res);
    }

    return 0;
}