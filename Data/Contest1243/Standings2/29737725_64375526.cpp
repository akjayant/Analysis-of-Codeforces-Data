#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 2e5 + 100;
const ll mod = 1e9 + 7;

int t, n;
int ar[1005];

int main() {

   cin >> t;

    while (t--) {

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        sort(ar, ar + n, greater <int>());

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if ((i + 1) <= ar[i]) {
                ans = max(ans, (i + 1));
            }
        }

        cout << ans << "\n";
    }


    return 0;
}