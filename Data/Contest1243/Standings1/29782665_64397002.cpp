#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
set<int>st;
bool used[300200];
vector<int>g[300200];

void dfs(int v) {
    int ptr = 0;
    sort(all(g[v]));
    auto it = st.begin();
    vector<int>get_rec;
    for(auto it : st) {
        while(ptr < g[v].size() && g[v][ptr] < (it))
            ++ptr;
        if (ptr < g[v].size()) {
            if (g[v][ptr] != (it))
                get_rec.push_back(it);
        }
        if (ptr == g[v].size())
            get_rec.push_back(it);
    }
    for(auto er : get_rec)
        st.erase(er);
    for(auto er : get_rec)
        dfs(er);
}



signed main() {
    accell();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        st.insert(i);
    for(int i = 0; i < n; ++i) {
        if (st.find(i) != st.end()) {
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt - 1;
    return 0;
}
