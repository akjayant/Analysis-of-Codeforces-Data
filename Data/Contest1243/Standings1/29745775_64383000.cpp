#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    for (int test = 0; test < k; test++) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                bool flag = false;
                for (int j = i + 1; j < n; j++) {
                    if (a[i] == a[j]) {
                        ans.push_back({j, i});
                        swap(a[j], b[i]);
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    for (int j = i + 1; j < n; j++) {
                        if (a[i] == b[j]) {
                            ans.push_back({j, j});
                            swap(a[j], b[j]);
                            ans.push_back({j, i});
                            swap(a[j], b[i]);
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag) {
                    break;
                }
            }
        }
        cout << (a == b ? "Yes\n" : "No\n");
        if (a == b) {
            cout << ans.size() << "\n";
            for (pair<int, int> i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
    }
}
