#include <bits/stdc++.h>

#define N 1000010 

using namespace std;

int head[N], to[N << 1], nxt[N << 1], tot;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
    int x = 0, f = 1;
    char c = nc();
    while (c < 48) {
        if (c == '-')
            f = -1;
        c = nc();
    }
    while (c > 47) {
        x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
    }
    return x * f;
}

inline void add(int x, int y) {
    to[ ++ tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

queue <int> q;

bool vis[N];

int aft[N], pre[N];

int main() {
    int n = rd(), m = rd();
    for (int i = 1; i <= m; i ++ ) {
        int x = rd(), y = rd();
        add(x, y), add(y, x);
    }
    for (int i = 0; i <= n; i ++ ) {
        aft[i] = i + 1, pre[i] = i - 1;
    }
    aft[n] = 0;
    int ans = 0;
    while (aft[0]) {
        q.push(aft[0]);
        ans ++ ;
        int mdl;
        mdl = aft[0] = aft[aft[0]];
        pre[mdl] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = head[x]; i; i = nxt[i]) {
                vis[to[i]] = true;
            }
            for (int i = aft[0]; i; i = aft[i]) {
                if (!vis[i]) {
                    q.push(i);
                    int k1, k2;
                    k1 = pre[i], k2 = aft[i];
                    aft[k1] = k2, pre[k2] = k1;
                }
            }
            for (int i = head[x]; i; i = nxt[i]) {
                vis[to[i]] = false;
            }
        }
    }
    cout << ans - 1 << endl ;
    return 0;
}