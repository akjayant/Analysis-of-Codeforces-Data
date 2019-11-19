#include <bits/stdc++.h>

#define clr(x, y) memset(x, y, sizeof x)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8, pi = acos(-1.0);
const int maxS = 1e6 + 13;
const int maxT = 1e3 + 13;
const int MOD = 835672545;
const int base = 19260817;
const int layer = 20;
using namespace std;

inline void read(char &x) {
    scanf("%c", &x);
}
inline void read(ll &x) {
    scanf("%lld", &x);
}
inline void read(ll &x, ll &y) {
    read(x);
    read(y);
}
inline void read(ll &x, ll &y, ll &z) {
    read(x, y);
    read(z);
}
inline void read(int &x) {
    scanf("%d", &x);
}
inline void read(int &x, int &y) {
    read(x);
    read(y);
}
inline void read(int &x, int &y, int &z) {
    read(x, y);
    read(z);
}

// struct node {
//     int x, y;
//     // bool operator <(const node& p) const {
//     // return x<p.x;
//     // }
//     // bool operator ==(const node& p) const {
//     // return x == p.x && y == p.y;
//     //}
// };

// struct tree {
//     int l, r, val, sub;
// };

// struct edge {
//     int to, len;
//     bool operator<(const edge &p) const {
//         return len < p.len;
//     }
// };

int n, m, x, y, z, k, T, kase = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

vector<int> vs[maxS], v;
bool vis[maxS];
int val[maxS][3], res[maxS];
ll f[maxS][3][3];

void dfs(int x, int fa) {
    for (auto y : vs[x])
        if (y != fa) {
            v.push_back(y);
            dfs(y, x);
        }
}

int main() {
    // freopen("C:\Temp\test.txt", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++)
        read(val[i][0]);
    for (int i = 1; i <= n; i++)
        read(val[i][1]);
    for (int i = 1; i <= n; i++)
        read(val[i][2]);
    for (int i = 1; i < n; i++) {
        read(x, y);
        vs[x].push_back(y);
        vs[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (vs[i].size() > 2) {
            printf("-1");
            return 0;
        }
    for (int i = 1; i <= n; i++)
        if (vs[i].size() == 1) {
            v.push_back(i);
            dfs(i, 0);
            break;
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i == j)
                continue;
            else
                f[1][i][j] = val[v[0]][i] + val[v[1]][j];
    for (int id = 2; id < n; id++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;
                int k = 0;
                while (k == i || k == j)
                    k++;
                f[id][j][k] = f[id - 1][i][j] + val[v[id]][k];
            }
    int x = 0, y = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i == j)
                continue;
            else if (f[n - 1][i][j] < f[n - 1][x][y]) {
                x = i;
                y = j;
            }
        }
    printf("%lld\n", f[n - 1][x][y]);
    res[v[n - 1]] = y;
    res[v[n - 2]] = x;
    for (int i = n - 3; i >= 0; i--) {
        int k = 0;
        while (k == x || k == y)
            k++;
        y = x;
        x = k;
        res[v[i]] = x;
    }
    for (int i = 1; i < n; i++)
        printf("%d ", res[i] + 1);
    printf("%d\n", res[n] + 1);
    return 0;
}