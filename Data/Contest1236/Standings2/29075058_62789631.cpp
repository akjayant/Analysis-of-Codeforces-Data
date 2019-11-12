#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            for (int j = n - 1; j >= 0; j--) {
                ans[i][j] = cur++;
            }
        } else {
            for (int j = 0; j < n; j++) {
                ans[i][j] = cur++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[j][i] << ' ';
        }
        cout << '\n';
    }
}
