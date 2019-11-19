#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define sz(x) (int)x.size()
using namespace std;

vector<pii> ed;
vector<int> bl;
struct city {
    int x, y, c, k, i;
};

struct edge {
    int fr, to, type, w;
};
const int N = 2e3 + 5;
int p[N];
int dist[N];
int used[N];

bool cmin(int& a, int b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

signed main() {
    using namespace std;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //n = 2000;
    int ans = 0;
    int mx = 0;
    vector<city> a(n);
    vector<edge> cr;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; ++i)
        cin >> a[i].c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].k;
        dist[i] = a[i].c;
    }
    while (true) {
        int mx = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (mx == -1 || dist[mx] > dist[j]))
                mx = j;
        if (mx == -1)
            break;
        ans += dist[mx];
        used[mx] = 1;
        for (int i = 0; i < n; ++i) {
            if (used[i])
                continue;
            if (cmin(dist[i], (a[i].k + a[mx].k) * (abs(a[i].x - a[mx].x) + abs(a[i].y - a[mx].y)))) {
                p[i] = mx + 1;
            }
        }
    }
    for  (int i = 0; i <n; ++i) {
        if (p[i])
            ed.pb({p[i], i + 1});
        else
            bl.pb(i + 1);
    }
    cout << ans << endl;
    cout << sz(bl) << endl;
    for (int i : bl)
        cout << i << " ";
    cout << endl;
    cout << sz(ed) << endl;
    for (auto c : ed) {
        cout << c.x << " " << c.y << "\n";
    }
    return 0;
}
