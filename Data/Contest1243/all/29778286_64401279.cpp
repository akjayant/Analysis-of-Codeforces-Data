#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main () {
#ifdef _IANE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<pair<int, int>> op;
        bool ok = true;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                int it = i + 1;
                for (; it < b.size(); ++it)
                    if (b[it] == b[i])
                        break;
                if (it != b.size()) {
                    op.push_back({i, it});
                    swap(a[i], b[it]);
                    continue;
                }
                int rt = i + 1;
                for (; rt < a.size(); ++rt)
                    if (a[rt] == b[i])
                        break;
                if (rt != a.size()) {
                    op.push_back({rt, rt});
                    op.push_back({i, rt});
                    swap(a[rt], b[rt]);
                    swap(a[i], b[rt]);
                    continue;
                }
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        cout << op.size() << "\n";

        for (int i = 0; i < op.size(); ++i)
            cout << op[i].first + 1 << " " << op[i].second + 1 << "\n";
    }


    return 0;
}
