#include <bits/stdc++.h>

using namespace std;

#define int long long

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int32_t main() {
    #ifdef THERE
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        //freopen("common.in", "r", stdin);
        //freopen("common.out", "w", stdout);
    #endif
    int n, s = 0; cin >> n;
    vector <vector <int> > a(n, vector <int>(n));
    for (int i = 1; i <= n * n; i += n, s++)
        if (s % 2)
            for (int j = 0; j < n; j++)
                a[j][s] = i + j;
        else
            for (int j = 0; j < n; j++)
                a[j][s] = i + (n - j - 1);
    for (auto v : a) {
        for (auto el : v)
            cout << el << " ";
        cout << "\n";
    }
    return 0;
}
