#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int ans[333][333];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int idx = 1;
    for (int i = 1; i <= n;) {
        for (int j = 1; j <= n; j++) {
            ans[j][i] = idx++;
        }
        i++;
        for (int j = n; j >= 1; j--) {
            ans[j][i] = idx++;
        }
        i++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}