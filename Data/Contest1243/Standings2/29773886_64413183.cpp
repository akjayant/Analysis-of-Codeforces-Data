#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int MAXN = 1 << 17;

struct disjoint_set_union {
    int ncmp;
    vector<int> pr, sz;
    disjoint_set_union(int n) {
        pr.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
            pr[i] = i, sz[i] = 1;
        ncmp = n;
    }
    int cmp(int x) {
        if (pr[x] == x)
            return x;
        return pr[x] = cmp(pr[x]);
    }
    void mrg(int u, int v) {
        int pu = cmp(u), pv = cmp(v);
        if (pu == pv)
            return;
        ncmp--;
        if (sz[pu] > sz[pv])
            swap(pu, pv);
        pr[pu] = pv;
        sz[pv] += sz[pu];
    }
};

int n, m;
vector<set<int>> fadl;
vector<vector<int>> sadl;
vector<bool> fvis, inv;
mt19937 rnd;

void fdfs(int vtx) {
    fvis[vtx] = true;
    for (auto it : fadl[vtx]) {
        if (!fvis[it])
            fdfs(it);
    }
}

void invert(int i, vector<int> &v) {
    vector<int> u;
    for (int i = 0; i < n; i++) {
        if (!binary_search(v.begin(), v.end(), i))
            u.pb(i);
    }
    v = u;
    inv[i] = true;
}

int main(int argc, char *argv[]) {
    cin >> n >> m;
    if (n <= 2000) {
        fadl.resize(n);
        fvis.resize(n);
        fill(fvis.begin(), fvis.end(), false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                fadl[i].insert(j);
            }
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            fadl[u].erase(v);
            fadl[v].erase(u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!fvis[i]) {
                ans++;
                fdfs(i);
            }
        }
        cout << ans - 1 << endl;
    } else {
        sadl.resize(n);
        inv.resize(n);
        disjoint_set_union dsu(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            sadl[u].pb(v);
            sadl[v].pb(u);
        }
        for (int i = 0; i < n; i++) {
            sort(sadl[i].begin(), sadl[i].end());
            if (sadl[i].size() > n / 2)
                invert(i, sadl[i]);
        }
        for (int i = 0; i < n; i++) {
            if (inv[i]) {
                for (auto it : sadl[i])
                    dsu.mrg(i, it);
            }
        }
        for (int i = 0; i < 10000000; i++) {
            int u = rnd() % n;
            if (inv[u] && sadl[u].empty())
                continue;
            if (inv[u]) {
                int v = sadl[u][rnd() % sadl[u].size()];
                dsu.mrg(u, v);
            } else {
                int v = rnd() % n;
                while (binary_search(sadl[u].begin(), sadl[u].end(), v))
                    v = rnd() % n;
                dsu.mrg(u, v);
            }
        }
        cout << dsu.ncmp - 1 << endl;
    }

    return 0;
}