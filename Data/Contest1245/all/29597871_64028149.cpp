#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iomanip>
#define int long long
#define double long double
using namespace std;

const int MAXN = 2000 + 10;
const int MAXM = 9e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-5;

int n;
int build = 0, connect = 0;
int builds[MAXN];
pair<int, int> E[MAXN];

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

int F[MAXN]; //并查集使用
struct Edge
{
    int u;    //起点
    int v;    //终点
    int w;    //权值
} edge[MAXM]; //存储边的信息

int tol; //边数，加边前赋值为0

void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return;
}

bool cmp(Edge a, Edge b)
{
    //排序函数，将边按照权值从小到大排序
    return a.w < b.w;
}

int find(int x)
{
    if (F[x] == -1)
    {
        return x;
    }
    else
    {
        return F[x] = find(F[x]);
    }
}

int Kruskal(int n) //传入点数，返回最小生成树的权值，如果不连通则返回-1
{
    memset(F, -1, sizeof(F));
    sort(edge, edge + tol, cmp);
    int cnt = 0; //计算加入的边数
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            ans += w;
            F[tOne] = tTwo;
            cnt++;
            if (u == n || v == n)
            {
                builds[++build] = u == n ? v : n;
            }
            else
            {
                connect++;
                E[connect].first = u;
                E[connect].second = v;
            }
        }
        if (cnt == n - 1)
        {
            break;
        }
    }
    if (cnt < n - 1)
    {
        return -1; //不连通
    }
    else
    {
        return ans;
    }
}

struct Node
{
    int x, y;
} nodes[MAXN];

int C[MAXN], K[MAXN];

int dist(int i, int j)
{
    return abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y);
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        nodes[i].x = read(), nodes[i].y = read();
    }
    for (int i = 1; i <= n; i++)
    {
        C[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        K[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            int cost = dist(i, j) * (K[i] + K[j]);
            addEdge(i, j, cost);
            addEdge(j, i, cost);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        addEdge(n + 1, i, C[i]);
    }
    n++;
    cout << Kruskal(n) << endl;
    cout << build << endl;
    for (int i = 1; i <= build; i++)
    {
        if (i != 1)
            cout << " ";
        cout << builds[i];
    }
    cout << endl;
    cout << connect << endl;
    for (int i = 1; i <= connect; i++)
    {
        cout << E[i].first << " " << E[i].second << endl;
    }
    return 0;
}
