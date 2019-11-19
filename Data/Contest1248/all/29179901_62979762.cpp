#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nParity(2);

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            nParity[x % 2]++;
        }

        int m; cin >> m;
        vector<int> mParity(2);

        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            mParity[x % 2]++;
        }

        cout << 1LL * nParity[0] * mParity[0] + 1LL * nParity[1] * mParity[1] << '\n';
    }
    return 0;
}
