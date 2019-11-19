#include <bits/stdc++.h>

#define int long long
using namespace std;

int solve(int n, vector<int> &p, int m, vector<int> &q) {
    int ep = 0, op = 0, eq = 0, oq = 0;
    for (int i:p) {
        if (i % 2 == 0)
            ep++;
        else
            op++;
    }
    for (int i:q) {
        if (i % 2 == 0)
            eq++;
        else
            oq++;
    }
    int res = 0;
    res += (op * oq);
    res += (ep * eq);
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        int m;
        cin >> m;
        vector<int> q(m);
        for (int i = 0; i < m; i++)
            cin >> q[i];
        cout << solve(n, p, m, q) << "\n";
    }
}