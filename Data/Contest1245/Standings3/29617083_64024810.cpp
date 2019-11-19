#include <bits/stdc++.h>

using namespace std;

vector<int> f(2005);

struct edge {
    int u, v;
    long long w;
    edge(int _u, int _v, long long _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

int getf(int x) {
    if (f[x] == x) return f[x];
    return f[x] = getf(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n), c(n), k(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> k[i];
    vector<edge> e;
    for (int i = 0; i < n; ++i) e.push_back(edge(i, n, c[i]));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            e.push_back(edge(i, j, dist * (k[i] + k[j])));
        }
    }
    sort(e.begin(), e.end(), cmp);
    for (int i = 0; i <= n; ++i) f[i] = i;
    long long cost = 0;
    int left = n;
    vector<int> build;
    vector<pair<int, int> > con;
    for (int i = 0; i < (int)e.size(); ++i) {
        int xx = getf(e[i].u), yy = getf(e[i].v);
        if (xx != yy) {
            f[xx] = yy;
            if (e[i].v == n) {
                build.push_back(e[i].u + 1);
            } else {
                con.push_back(make_pair(e[i].u + 1, e[i].v + 1));
            }
            cost += e[i].w;
            --left;
            if(left == 0) break;
        }
    }
    cout << cost << endl;
    cout << build.size() << endl;
    for (int i = 0; i < (int)build.size(); ++i) {
        cout << build[i] << " ";
    }
    cout << endl;
    cout << con.size() << endl;
    for (int i = 0; i < (int)con.size(); ++i) {
        cout << con[i].first << " " << con[i].second << endl;
    }
    return 0;
}

