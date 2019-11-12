// qdd on Oct 17, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > ans(n, vector<int>(n));
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        if (j & 1)
            for (int i = n - 1; i >= 0; i--) {
                ans[i][j] = ++cnt;
            }
        else
            for (int i = 0; i < n; i++) {
                ans[i][j] = ++cnt;
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}