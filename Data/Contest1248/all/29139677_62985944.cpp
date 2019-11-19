#include <bits/stdc++.h>

#define ll long long

using namespace std;
const int MX = 100'000 + 5; // check bounds!

int t, n, m;
int main() {
    cin >> t;
    while (t--) {
        ll odd1 = 0, even1 = 0, x;
        ll odd2 = 0, even2 = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x % 2)
                even1++;
            else
                odd1++;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> x;
            if (x % 2)
                even2++;
            else
                odd2++;
        }
        cout << even1 * even2 + odd1 * odd2 << "\n";
    }

    return 0;
}
