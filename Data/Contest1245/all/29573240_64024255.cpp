#include <iostream>
#include <vector>

using namespace std;

const int64_t inf = 1000000000000000000LL;
const size_t size_inf = 1000000000ULL;

struct plant {
    int64_t x, y, k;

    plant(int64_t x, int64_t y) : x(x), y(y), k(-1) {}

    plant() : x(-1), y(-1), k(-1) {}
};

size_t n;

int64_t get_w(size_t i, size_t j, vector<plant> &a, vector<int64_t> &c) {
    if (j == n) {
        swap(i, j);
    }
    if (i == n) {
        return c[j];
    } else {
        return (a[i].k + a[j].k) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<plant> a;
    vector<int64_t> c(n);

    for (size_t i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    a.emplace_back();

    for (size_t i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i].k;
    }

    vector<int64_t> d(n + 1);
    fill(d.begin(), d.end(), inf);
    d[0] = 0;
    vector<size_t> p(n + 1);
    fill(p.begin(), p.end(), size_inf);
    vector<bool> vis(n + 1);

    int64_t total_cost = 0;
    vector<size_t> conn_to_factory;
    vector<pair<size_t, size_t>> connections;

    for (size_t i = 0; i < n + 1; ++i) {
        size_t v = n + 1;
        for (size_t j = 0; j < n + 1; ++j) {
            if (!vis[j] && (v == n + 1 || d[v] > d[j])) {
                v = j;
            }
        }

        total_cost += d[v];

        size_t va = v;
        size_t vb = p[v];
        if (p[v] != size_inf) {
            if (vb == n) {
                swap(va, vb);
            }
            if (va == n) {
                conn_to_factory.push_back(vb);
            } else {
                connections.emplace_back(va, vb);
            }
        }

        vis[v] = true;

        for (size_t j = 0; j < n + 1; ++j) {
            int64_t w = get_w(j, v, a, c);
            if (!vis[j] && d[j] > w) {
                d[j] = w;
                p[j] = v;
            }
        }
    }

    cout << total_cost << '\n';
    cout << conn_to_factory.size() << '\n';
    for (size_t v : conn_to_factory) {
        cout << (v + 1) << " ";
    }
    cout << '\n';
    cout << connections.size() << '\n';
    for (auto conn : connections) {
        cout << (conn.first + 1) << " " << (conn.second + 1) << '\n';
    }
}
