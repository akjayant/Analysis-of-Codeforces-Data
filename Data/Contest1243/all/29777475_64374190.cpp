#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

#define dbg(a) cout << "-> " << __LINE__ << ": " << #a << " = " << a << endl

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int v : a) {
                if (v >= i) {
                    ++cnt;
                }
            }
            if (cnt >= i) {
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
