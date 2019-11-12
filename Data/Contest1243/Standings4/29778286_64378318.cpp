#include <bits/stdc++.h>
using namespace std;

signed main () {
#ifdef _IANE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> ne;
        for (int i = 0; i < n; ++i)
            if (a[i] != b[i])
                ne.push_back(i);
        if (ne.size() == 2) {
            swap(a[ne[0]], b[ne[1]]);
           // swap(a[ne[1]], b[ne[0]]);
            if (a == b) {
                cout << "Yes\n";
                continue;
            }
        }
        cout << "No\n";
    }

    return 0;
}
