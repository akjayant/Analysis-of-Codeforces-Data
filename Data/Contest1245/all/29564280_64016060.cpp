#include <bits/stdc++.h>

using namespace std;

const long long SZ = 26, MAXN = 2e3 + 20, MAXM = 1410, mod = 1e9 + 7, inf = 1e9 + 100, L = 19;
const double eps = 1e-9, Pi = acos(-1);
mt19937 rnd;

struct point {
    long long x, y;
};

int par[MAXN], rnk[MAXN], id[MAXN];
long long c[MAXN], k[MAXN];
point p[MAXN];
vector <pair <long long , pair <int, int> > > ed;

long long dist(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int get(int a) {
    if (a == par[a])
        return a;
    return par[a] = get(par[a]);
}

void join(int a, int b) {
    if (rnk[a] > rnk[b])
        swap(a, b);
    else if (rnk[a] == rnk[b])
        ++rnk[b];
    par[a] = b;
    if (c[id[b]] > c[id[a]])
        id[b] = id[a];
}

long long cost(int a, int b) {
    return dist(p[a], p[b]) * (k[a] + k[b]);
}

void solve () {
    int n;
    cin >> n;
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
        cin >> p[j].x >> p[j].y;
        par[j] = id[j] = j;
        rnk[j] = 0;
    }
    for (int j = 0; j < n; ++j)
        cin >> c[j], sum += c[j];
    for (int j = 0; j < n; ++j)
        cin >> k[j];

    for (int j = 0; j < n; ++j) {
        for (int i= j + 1; i < n; ++i) {
            ed.push_back({cost(j, i), {j, i}});
        }
    }

    sort(ed.begin(), ed.end());
    queue <pair <int, int> > q;
    int cnt = n;
    for (int j = 0; j < ed.size(); ++j) {
        int a = ed[j].second.first, b = ed[j].second.second;
        long long cst = ed[j].first;
        int pa = get(a);
        int pb = get(b);
        if (pa == pb)
            continue;
        if (c[id[pa]] + c[id[pb]] > min(c[id[pa]], c[id[pb]]) + cst) {
            q.push({a + 1, b + 1});
            sum -= max(c[id[pa]], c[id[pb]]) - cst;
            join(pa, pb);
            --cnt;
        }
    }
    cout << sum << '\n' << cnt << '\n';
    for (int j = 0; j < n; ++j) {
        if (get(j) == j) {
            cout << id[j] + 1 << ' ';
        }
    }
    cout << '\n' << q.size() << '\n';
    while (!q.empty()) {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);

    int t = 1;
    while (t--)
        solve();
}