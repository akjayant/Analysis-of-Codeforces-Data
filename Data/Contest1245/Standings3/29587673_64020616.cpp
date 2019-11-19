#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++i)

int MOD = 1e9 + 7;

int Distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int> > v(n);
    F(i, n) cin >> v[i].first >> v[i].second;
    vector<int> c(n), k(n);
    F(i, n) {
        cin >> c[i];
    }
    F(i, n) cin >> k[i];
    int mni = 0;
    F(i, n) {
        if(c[i] < c[mni]) {
            mni = i;
        }
    }
    vector<char> ch(n);
    vector<int> from(n, -1);
    vector<pair<int, int> > roads;
    F(q, n) {
        ch[mni] = true;
        int new_mni = -1;
        F(i, n) {
            if(ch[i]) {
                continue;
            }
            int cost = Distance(v[mni], v[i]) * (k[mni] + k[i]);
            if (cost < c[i]) {
                from[i] = mni;
                c[i] = cost;
            }
            if (new_mni == -1 || c[i] < c[new_mni]) {
                new_mni = i;
            }
        }
        mni = new_mni;
    }
    int ans = 0;
    vector<int> a;
    vector<pair<int, int> > b;
    F(i, n) {
        ans += c[i];
        if(from[i] == -1) {
            a.push_back(i);
        } else {
            b.push_back({i, from[i]});
        }
    }
    cout << ans << endl;
    cout << a.size() << endl;
    F(i, a.size()) {
        cout << a[i] + 1 << ' ';
    }
    cout << endl << b.size() << endl;
    F(i, b.size()) {
        cout << b[i].first + 1 << ' ' << b[i].second + 1 << endl;
    }
}
