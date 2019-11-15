#include <bits/stdc++.h>

using namespace std;
#define int long long
#define EPS 1e-6
#define mod 1000000007


signed main() {
    int n;
    cin >> n;
    vector<int> ans(n * n);
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; ++j) {
            ans[i * n + j] = j;
        }
        if (i != n - 1) {
            for (int j = 0; j < n; ++j) {
                ans[i * n + n + j] = n - j - 1;
            }
        }
    }
    vector<vector<int>> res(n);
    for (int i = 0; i < n * n; ++i) {
        res[ans[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}