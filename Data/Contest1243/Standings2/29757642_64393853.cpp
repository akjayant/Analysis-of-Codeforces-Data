#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

struct tree {
    int v, tl, tr;
    vector <int> t;

    void init(int n) {
        v = 1;
        tl = 1;
        tr = n;

        t.resize(n * 5);
    }

    void inc(int v, int tl, int tr, int pos) {
        if (tl == tr)
            t[v]++;
        else {
            int tm = tl + tr >> 1;
            if (pos <= tm)
                inc(v << 1, tl, tm, pos);
            else
                inc(v << 1 | 1, tm + 1, tr, pos);

            t[v] = min(t[v << 1], t[v << 1 | 1]);
        }
    }

    void inc(int pos) {
        inc(v, tl, tr, pos);
    }

    int dfs(int v, int tl, int tr) {
        if (tl == tr)
            return (t[v] ? -1 : tl);

        int tm = tl + tr >> 1;
        if (t[v << 1 | 1])
            return dfs(v << 1, tl, tm);
        else
            return dfs(v << 1 | 1, tm + 1, tr);
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -1;

        if (tl == l && tr == r)
            return dfs(v, tl, tr);

        int tm = tl + tr >> 1;
        int ql = get(v << 1, tl, tm, l, min(r, tm));
        int qr = get(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r);

        return max(ql, qr);
    }

    int get(int l, int r) {
        return get(v, tl, tr, l, r);
    }
};

struct dsu {
    vector <int> p;

    void init(int n) {
        p.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int get(int v) {
        if (p[v] == v)
            return v;

        return p[v] = get(p[v]);
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);

        if (a != b) {
            p[a] = b;
        }

        return a != b;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector <pair <int, int> > edge;
    vector <vector <int> > temp_g(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        temp_g[a].push_back(b);
        temp_g[b].push_back(a);

        edge.push_back(make_pair(a, b));
    }

    vector <vector <pair <int, int> > > g(n + 1);
    for(int i = 1; i <= n; i++) {
        temp_g[i].push_back(n + 1);
        sort(temp_g[i].begin(), temp_g[i].end());

        int l = 0;
        for(auto x : temp_g[i]) {
            int r = x;
            if (l + 1 <= r - 1) {
                g[i].push_back(make_pair(l + 1, r - 1));
            }

            l = x;
        }
    }

    tree str;
    dsu osu;

    str.init(n);
    osu.init(n);

    for(int i = 1; i <= n; i++) {
        if (str.get(i, i) != -1) {
            queue <int> que;

            que.push(i);
            str.inc(i);

            vector <int> cmp;
            while(que.empty() == false) {
                int v = que.front();
                que.pop();

                cmp.push_back(v);

                for(auto to : g[v]) {
                    int l = to.first, r = to.second;

                    int x = str.get(l, r);
                    while(x != -1) {
                        que.push(x);
                        str.inc(x);

                        x = str.get(l, r);
                    }
                }
            }

            int last = cmp.back();
            for(auto v : cmp) {
                osu.unite(last, v);
                last = v;
            }

        }
    }

    int ans = 0;
    for(auto i : edge) {
        if (osu.unite(i.first, i.second)) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
/*
*/
