#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int x[2005], y[2005];
int c[2005], k[2005];
int p[2005];

typedef pair<ll, pair<int, int>> E;

int find(int x) {
    return p[x] = p[x] != x ? find(p[x]) : x;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    vector<E> e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            e.emplace_back((ll)(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), make_pair(i, j));
        }
        e.emplace_back((ll)c[i], make_pair(0, i));
    }
    sort(e.begin(), e.end());
    for (int i = 0; i <= n; i++) p[i] = i;
    vector<int> vv;
    vector<pair<int, int>> ev;
    ll ans = 0;
    for (auto i : e) {
        int x = i.second.first;
        int y = i.second.second;
        if (find(x) == find(y)) continue;
        p[find(x)] = find(y);
        if (x == 0) vv.push_back(y);
        else ev.emplace_back(x, y);
        ans += i.first;
    }
    printf("%lld\n", ans);
    printf("%d\n", vv.size());
    for (int i : vv) printf("%d ", i);
    printf("\n%d\n", ev.size());
    for (auto i : ev) printf("%d %d\n", i.first, i.second);
}