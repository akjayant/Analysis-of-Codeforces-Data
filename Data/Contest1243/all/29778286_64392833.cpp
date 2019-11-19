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

    int n;
    cin >> n;

    vector<int> del;

    int x = n;
    for (int i = 2; i * i <= n; ++i) {
        if (x % i == 0)
            del.push_back(i);
        while (x % i == 0)
            x /= i;
    }

    if (del.size() == 0) {
        cout << n;
        return 0;
    }

    if (x > 1) {
        cout << 1;
        return 0;
    }

    if (del.size() == 1) {
        cout << del[0];
        return 0;
    }

    cout << 1;

    return 0;
}
