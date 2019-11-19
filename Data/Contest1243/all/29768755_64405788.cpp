#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define int long long
#define ll long long
#define ins insert
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define ld long double
#define rsz resize
#define pii pair<int, int>

using namespace std;

mt19937 rnd(time(nullptr));

const long long INF = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].insert(u);
        g[u].insert(v);
    }
    vector<int> used(n);
    int ans = -1;
    set<int> alive;
    for (int i = 0; i < n; i++) alive.insert(i);
    map<int, int> cnt;
    set<pii> st;
    for (int i = 0; i < n; i++) st.insert({0, i});
    int sz = 0;
    for (int i = 0; i < n; i++) {
   //         for (int elem : alive) cout << elem << ' ';
    //cout << "\n";
        if (used[i] || alive.find(i) == alive.end()) continue;
        used[i] = 1;
        alive.erase(i);
        st.erase({i, cnt[i]});
        for (int u : g[i]) {
            if (st.find({cnt[u], u}) == st.end()) continue;
            st.erase({cnt[u], u});
            cnt[u]++;
            st.insert({cnt[u], u});
        }
        ans++;
        sz++;
        while (st.size() > 0) {
            pii p = *st.begin();
            int v = p.ss;
            if (p.ff == sz)
                break;
            st.erase(p);
            sz++;
            alive.erase(v);
            for (int u : g[v]) {
                if (st.find({cnt[u], u}) == st.end()) continue;
                st.erase({cnt[u], u});
                cnt[u]++;
                st.insert({cnt[u], u});
            }
        }
    }
    cout << ans;
    return 0;
}
