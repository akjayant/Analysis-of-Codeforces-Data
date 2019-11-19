#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

#define int64 long long
#define pii pair <int64, int64>
#define fr first
#define sc second
#define heap priority_queue
struct piii{
    int64 fr, sc, th;
    bool operator < (const piii &b){
        if (fr != b.fr) return fr < b.fr;
        if (sc != b.sc) return sc < b.sc;
        return th < b.th;
    }
};
///////////////////////////////////////////////
///////////////////////////////////////////////

const int64 oo = 1e18;
int n;
vector <int> e[100005];
int64 c[3][100005], f[100005][3][3];
int tr[100005][3][3], link[100005], cor[100005];

void input(){
    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

void dfs(int u, int p){
    bool isleaf = true;
    for (int v : e[u])
    if (v != p){
        dfs(v, u);
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                for (int z = 0; z < 3; z++)
                    if (x != y && y != z && x != z && c[x][u] + f[v][y][z] < f[u][x][y]){
                        tr[u][x][y] = z;
                        f[u][x][y] = c[x][u] + f[v][y][z];
                    }
        isleaf = false;
        link[u] = v;
    }
    if (isleaf){
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                f[u][x][y] = c[x][u];
    }
}

int main(){
    cout << setprecision(2) << fixed;
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    for (int i = 1; i <= n; i++)
    if (e[i].size() > 2){
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                f[i][x][y] = oo;
    int u;
    for (int i = 1; i <= n; i++)
        if (e[i].size() == 1) u = i;
    dfs(u, 0);
    int64 res = oo;
    int xx, yy;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (f[u][x][y] < res){
                res = f[u][x][y];
                xx = x;
                yy = y;
            }
    cout << res << endl;
    while (u){
        cor[u] = xx;
        int tmp = tr[u][xx][yy];
        xx = yy, yy = tmp;
        u = link[u];
    }
    for (int i = 1; i <= n; i++) cout << cor[i] + 1 << ' ';
    return 0;
}
