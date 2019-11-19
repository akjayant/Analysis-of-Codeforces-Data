#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    pair<long long, long long> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    long long c[n], m = -1, val = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] < val)
            val = c[i], m = i;
    }

    long long k[n];
    for (int i = 0; i < n; i++)
        cin >> k[i];

    long long ans = 0;
    vector<int> v;
    vector<pair<int, int>> e;

    bool connected[n] = {};
    set<pair<long long, pair<int, int>>> s;
    s.insert({c[m], {m, m}});
    int settled = 0;

    while (settled != n) {
        auto it = s.begin();
        long long cost = it -> x;
        int i = it -> y.x;
        int i_ = it -> y.y;
        s.erase(it);

        if (connected[i])
            continue;
        connected[i] = true;
        settled++;

        if (cost == c[i]) {
            ans += c[i];
            v.push_back(i + 1);
        } else {
            ans += cost;
            e.push_back({i + 1, i_ + 1});
        }

        for (int j = 0; j < n; j++) {
            if (!connected[j]) {
                long long dist = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
                long long tot = dist * (k[i] + k[j]);
                if (tot < c[j])
                    s.insert({tot, {j, i}});
                else
                    s.insert({c[j], {j, i}});
            }
        }
    }

    cout << ans << "\n";
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i << " ";
    cout << "\n" << e.size() << "\n";
    for (auto i : e)
        cout << i.first << " " << i.second << "\n";
}