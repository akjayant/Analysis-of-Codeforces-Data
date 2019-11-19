#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;


#define ll long long
const ll mod = 1e9 + 7;
ll inf = 1e18;

int n;
ll x[2005], y[2005], c[2005], k[2005];
ll d[2005][2005], dis[2005];
int f[2005];
bool flag[2005];
vector<int> a;
vector<pair<int, int> > b;

ll prim() {
    for(int i = 0; i < n; i++) {
        dis[i] = inf;
        f[i] = -1;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll minn = inf;
        int u = -1;

        for(int j = 0; j < n; j++) {
            if(!flag[j] && dis[j] <= minn) {
                minn = dis[j];
                u = j;
            }
        }
        flag[u] = 1;
        int v = f[u];
        if(v != -1) {
            if(u == n - 1) a.push_back(v);
            else if(v == n - 1) a.push_back(u);
            else b.push_back(make_pair(u, v));
            ans += minn;
        }
        for(int j = 0; j < n; j++) {
            if(!flag[j]) {
                if(d[u][j] < dis[j]) {
                    dis[j] = d[u][j];
                    f[j] = u;
                }
            }
        }
    }
    return ans;
}
int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    }

    for(int i = 0; i < n; i++) {
        d[n][i] = d[i][n] = c[i];
    }
    n += 1;
    cout << prim() << endl;
    cout << a.size() << endl;
    for(auto u: a) {
        printf("%d ", u + 1);
    }
    puts("");
    cout << b.size() << endl;
    for(auto it: b) {
        printf("%d %d\n", it.first + 1, it.second + 1);
    }

    return 0;
}