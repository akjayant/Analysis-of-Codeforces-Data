#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

int n;
vector<pair<int, int>> xy;
vector<int> c;
vector<int> k;

int distance(int i, int j) {
    return (k[i] + k[j]) * (abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second));
}

vector<int> from;
int ans = 0;

void Prim() {
    vector<int> d (n);
    vector<bool> used (n);
    set<tuple<int, int, int>> st;
    for (int i = 0; i < n; ++i) {
        d[i] = c[i];
        st.insert({d[i], i, i});
        from[i] = i;
    }
    while (!st.empty()) {
        auto p = *st.begin();
        st.erase(st.begin());
        ans += get<0>(p);
        int in = get<1>(p);
        used[in] = true;
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                if (d[j] > distance(in, j)) {
                    st.erase({d[j], j, from[j]});
                    from[j] = in;
                    d[j] = distance(in, j);
                    st.insert({d[j], j, from[j]});
                }
            }
        }
    }
}

signed main() {
    cin >> n;
    xy.resize(n);
    c.resize(n);
    k.resize(n);
    from.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> k[j];
    }
    Prim();
    cout << ans << '\n';
    vector<int> alone;
    vector<pair<int, int>> rebro;
    for (int i = 0; i < n; ++i) {
        if (from[i] == i) {
            alone.push_back(i + 1);
        } else {
            rebro.push_back({i + 1, from[i] + 1});
        }
    }
    cout << alone.size() << '\n';
    for (int j : alone) {
        cout << j << ' ';
    }
    cout << '\n' << rebro.size() << '\n';
    for (auto p : rebro) {
        cout << p.first << ' ' << p.second << ' ';
    }
}