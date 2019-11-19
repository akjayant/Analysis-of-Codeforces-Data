#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int t;

    cin >> t;

    for (int _ = 0; _ < t; ++_) {
        int n, m;
        cin >> n;
        long long even1 = 0, odd1 = 0, even2 = 0, odd2 = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            even1 += !(x % 2);
            odd1 += x % 2;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            long long x;
            cin >> x;
            even2 += !(x % 2);
            odd2 += x % 2;
        }
        cout << even1 * even2 + odd1 * odd2 << endl;
    }

    return 0;
}