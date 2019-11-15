#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(int a, int b, int c) {
    int res = 0;
    for (int x = 0; x <= a; x++) {
        for (int y = 0; y <= c / 2; y++) {
            int z = x * 2 + y;
            if (z > b) continue;
            res = max(res, x + z + y * 2);
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << "\n";
    }
    return 0;
}