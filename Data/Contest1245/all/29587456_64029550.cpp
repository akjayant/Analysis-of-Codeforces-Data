#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

struct dsu {
    vector <int> p;
    void init(int n) {
        p.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int get(int v) {
        if (p[v] == v) {
            return v;
        }
        else {
            return p[v] = get(p[v]);
        }
    }

    bool merge(int a, int b) {
        a = get(a);
        b = get(b);

        if (a == b) {
            return false;
        }
        else {
            //p[a] = b;
            return true;
        }
    }
};

struct osu {
    ll cost;
    int a, b;
};

bool cmp(osu a, osu b) {
    return a.cost < b.cost;
}

int dist(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

void solve() {
    int n;
    cin >> n;

    vector <int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector <int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector <int> k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector <osu> edge;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            edge.push_back(make_struct(1LL * (k[i] + k[j]) * dist(x[i], y[i], x[j], y[j]), i, j));
        }
    }

    sort(edge.begin(), edge.end(), cmp);

    dsu str;
    str.init(n);

    ll cost = 0;
    for(int i = 0; i < n; i++) {
        cost += c[i];
    }

    vector <int> used(n, 1);
    vector <pair <int, int> > out_edge;
    for(auto i : edge) {
        int ra = str.get(i.a);
        int rb = str.get(i.b);
        if (ra != rb) {
            int mx = max(c[ra], c[rb]);
            int mn = min(c[ra], c[rb]);

            ll cost_edge = i.cost;

            if (mx > cost_edge) {
                if (c[ra] > c[rb]) {
                    str.p[ra] = rb;
                    used[ra] = 0;
                }
                else {
                    used[rb] = 0;
                    str.p[rb] = ra;
                }



                cost -= mx;
                cost += cost_edge;

                out_edge.push_back(make_pair(i.a, i.b));
                //str.p[ra] = rb;
            }
        }
    }

    cout << cost << "\n";

    vector <int> gen;
    for(int i = 0; i < n; i++) {
        if (used[i]) {
            gen.push_back(i);
        }
    }

    cout << gen.size() << "\n";
    for(auto i : gen) {
        cout << i + 1 << " ";
    }

    cout << "\n";

    cout << out_edge.size() << "\n";
    for(auto i : out_edge) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test;
    //cin >> test;
    test = 1;
    while(test--) {
        solve();
    }

    return 0;
}
/*
*/
