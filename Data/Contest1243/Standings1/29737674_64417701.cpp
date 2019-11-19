#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
int n, m;
int head[maxn << 1], cnt;
bool vis1[maxn], vis2[maxn];
int ans;
struct node {
    int v, nxt;
} e[maxn << 1];

struct link {
    int pre, nxt;
} lnk[maxn];

void add(int u, int v) {
    e[cnt]= {v, head[u]};
    head[u] = cnt++;
}

void del(int x) {
    lnk[lnk[x].pre].nxt = lnk[x].nxt;
    lnk[lnk[x].nxt].pre = lnk[x].pre;
}

void A(int u) {
    for (int i = head[u]; ~i; i = e[i].nxt)
        vis1[e[i].v] = 1;
}

void B(int u) {
    for (int i = head[u]; ~i; i = e[i].nxt)
        vis1[e[i].v] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        lnk[i].pre = i - 1, lnk[i - 1].nxt = i;
    }
    lnk[n].nxt = 0;
    for (int u, v, i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add(v, u);
        add(u, v);
    }
    queue<int> q;
    while (lnk[0].nxt) {
        int now = lnk[0].nxt;
        vis2[now] = 1;
        q.push(now);
        del(now);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            A(u);
            for (int i = lnk[0].nxt; i; i = lnk[i].nxt) {
                if (!(!vis1[i] && !vis2[i])) continue;
                else {
                    del(i);
                    q.push(i);
                    vis2[i] = 1;
                }
            }
            B(u);
        }
        ++ans;
    }
    printf("%d\n", ans - 1);
    return 0;
}
