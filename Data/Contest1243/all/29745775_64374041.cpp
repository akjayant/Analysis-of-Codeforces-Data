#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &e : v) {
            cin >> e;
        }
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= (i + 1)) {
                ans = i + 1;
            }
        }
        cout << ans << '\n';
    }
}
