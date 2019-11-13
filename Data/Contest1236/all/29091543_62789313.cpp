#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> group(n);
    bool ok = false;
    int ctr = 1;
    for (int i = 0; i < n; i++) {
        if (!ok) {
            for (int j = 0; j < n; j++) {
                group[j].emplace_back(ctr++);
            }
        } else {
            for (int j = n-1; j > -1; j--) {
                group[j].emplace_back(ctr++);
            }
        }
        ok = !ok;
    }

    for (int i = 0; i < n; i++) {
        for (int &v : group[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}