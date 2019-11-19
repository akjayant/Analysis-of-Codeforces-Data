/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e6+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

int n;
pii P[maxn];
ll c[maxn], k[maxn];

struct edge {
    int id;
    int u, v;
    ll w;
    edge() {}
    edge(int d, int a, int b, ll c):
        u(a), v(b), w(c), id(d) {}
} Edge[5 * maxn];

bool operator < (edge a, edge b) {
    return a.w < b.w;
}

int father[maxn], rank_[maxn];
void init()
{
    for(int i = 0; i <= n; i++)
    {
        father[i] = i;
        rank_[i] = 0;
    }
}

int find(int id)
{
    return father[id] == id ? id : father[id] = find(father[id]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        if(rank_[a] > rank_[b]) father[b] = a;
        else
        {
            father[a] = b;
            if(rank_[a] == rank_[b])    rank_[b]++;
        }
    }
}

bool mark[5 * maxn];
vector<int> ans_v;
vector<pii> ans_e;

ll dist(pii A, pii B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &P[i].first, &P[i].second);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &k[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        Edge[cnt] = edge(cnt, 0, i, c[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cnt++;
            Edge[cnt] = edge(cnt, i, j, (k[i] + k[j]) * dist(P[i], P[j]));
        }
    }
    sort(Edge + 1, Edge + 1 + cnt);

    ull ans = 0;
    for (int i = 1; i <= cnt; i++) {
        int u = Edge[i].u;
        int v = Edge[i].v;
        ll w = Edge[i].w;
        if (find(u) == find(v)) continue;
        mark[i] = true;
        merge(u, v);
        ans += w;
        if (u == 0) ans_v.pb(v);
        else {
            ans_e.pb(pii(u, v));
        }
    }
    printf("%llu\n", ans);
    printf("%d\n", (int)ans_v.size());
    for (int i = 0; i < ans_v.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", ans_v[i]);
    }
    puts("");
    printf("%d\n", (int)ans_e.size());
    for (auto ed: ans_e) {
        printf("%d %d\n", ed.first, ed.second);
    }

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
