#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, a[maxn];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] >= i) cnt++;
            }
            if (cnt >= i) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}