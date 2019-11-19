#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 100000 + 10;
const ll mod = 1e9 + 7;
ll mp[2010][2010];
ll val[2010], k[2010];
struct pp {
    ll x, y;
} a[2010];
int n;
struct node {
    ll from, to, dis;
};
vector<node> g;
int pre[maxn];

bool cmp(node a, node b) {
    return a.dis < b.dis;
}
int ffind(int x) {
    return pre[x] == x ? x : pre[x] = ffind(pre[x]);
}
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) pre[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mp[i][j] = mp[j][i] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
        }
    }
    for (int i = 1; i <= n; i++) {
        g.push_back(node{0, i, val[i]});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mp[i][j] = mp[j][i] = mp[i][j] * (k[i] + k[j]);
            g.push_back(node{i, j, mp[i][j]});
        }
    }
    sort(g.begin(), g.end(), cmp);
    int u, v, w;
    int prex, prey, c = 0;
    ll ans = 0;
    vector<pii > vv;
    vector<int> v1;
    for (int i = 0; i < g.size(); i++) {
        u = g[i].from;
        v = g[i].to;
        w = g[i].dis;
        prex = ffind(u);
        prey = ffind(v);
        if (prex != prey) {
            ans += w;

            pre[prex] = prey;
            if (u != 0 && v != 0)
                vv.push_back({u, v});
            else
                v1.push_back(max(u, v));
            if (++c == n)
                break;
        }
    }
    cout << ans << endl;
    cout << v1.size() << endl;
    for (auto x:v1)
        cout << x << " ";
    cout << endl;
    cout << vv.size() << endl;
    for (auto x:vv)
        cout << x.first << " " << x.second << endl;
    return 0;
}
