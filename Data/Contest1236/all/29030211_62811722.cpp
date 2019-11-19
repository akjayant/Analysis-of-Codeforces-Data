#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e5 + 5);
const int inf = (1e9 + 7);

int n,m,k;
int a,b;
int ans;

vector <int> g[N],c[N];

main () {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++) g[i].pb(0);
    for (int i = 1; i <= m; i ++) c[i].pb(0);

    for (int i = 1; i <= k; i ++) {
        cin >> a >> b;
        g[a].pb(b);
        c[b].pb(a);
    }
    for (int i = 1; i <= n; i ++) g[i].pb(m + 1);
    for (int i = 1; i <= m; i ++) c[i].pb(n + 1);

    for (int i = 1; i <= n; i ++) sort(g[i].begin(),g[i].end());
    for (int i = 1; i <= m; i ++) sort(c[i].begin(),c[i].end());
    int x = 1,y = 1;
    int dir = 1;
    int x1 = 0,x2 = n + 1;
    int y1 = 0,y2 = m + 1;
    while(1) {
        if (dir == 1) {
            int pos = lower_bound(g[x].begin(),g[x].end(),y) - g[x].begin();
            int cur = min(y2 - 1,g[x][pos] - 1);
            ans += abs(cur - y);
            y = cur;
            y2 = cur;
            x1 = max(x1,x);

            dir = 2;
            pos = lower_bound(c[y].begin(),c[y].end(),x) - c[y].begin();
            if (min(x2 - 1,c[y][pos] - 1) == x) break;

        }
        else if (dir == 2) {
            int pos = lower_bound(c[y].begin(),c[y].end(),x) - c[y].begin();
            int cur = min(x2 - 1,c[y][pos] - 1);
            ans += abs(cur - x);
            x = cur;
            x2 = cur;
            y2 = min(y2,y);
            dir = 3;

            pos = lower_bound(g[x].begin(),g[x].end(),y) - g[x].begin();
            if (max(y1 + 1,g[x][pos - 1] + 1) == y) break;

        }
        else if (dir == 3) {
            int pos = lower_bound(g[x].begin(),g[x].end(),y) - g[x].begin();
            int cur = max(y1 + 1,g[x][pos - 1] + 1);
            ans += abs(y - cur);
            y = cur;
            y1 = cur;
            x2 = min(x2,x);
            dir = 4;

            pos = lower_bound(c[y].begin(),c[y].end(),x) - c[y].begin();
            cur = max(c[y][pos - 1] + 1,x1 + 1);
            if (cur == x) break;

        }
        else {
            int pos = lower_bound(c[y].begin(),c[y].end(),x) - c[y].begin();
            int cur = max(c[y][pos - 1] + 1,x1 + 1);
            ans += abs(x - cur);
            x = cur;
            x1 = cur;
            y1 = max(y1,y);

            dir = 1;

            pos = lower_bound(g[x].begin(),g[x].end(),y) - g[x].begin();
            cur = min(y2 - 1,g[x][pos] - 1);
            if (cur == y) break;
        }
    }
    if (ans + 1 == n * m - k) cout << "Yes" << endl;
    else cout << "No" << endl;
}

