#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, LL> PIL;
typedef pair <int, int> PII;
#define mkpr make_pair
#define fi first
#define se second
const int MAXN = 1e5 + 2;
LL inline in()
{
    LL x = 0, flag = 1; char ch = getchar(); 
    while (ch < '0' || ch > '9') { if (ch == '-') flag = -1; ch = getchar(); } 
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * flag;
}

int head[MAXN], nume;
struct Adj { int nex, to, w; } adj[MAXN << 1];
void addedge(int from, int to, int w)
{
    adj[++ nume] = (Adj) { head[from], to, w };
    head[from] = nume;
}
void link(int u, int v, int w) 
{ 
    addedge(u, v, w); addedge(v, u, w); 
} 

int n, m;

LL a[MAXN];

int main()
{
    n = in();
    for (int i = 1; i <= n; ++ i) a[i] = in();
    sort(a + 1, a + n + 1);
    LL sx = 0, sy = 0;
    for (int i = 1 ; i <= n / 2; ++ i) 
    {
	sx += a[i];
    }
    for (int i = n / 2 + 1; i <= n; ++ i) sy += a[i];
//    printf("%lld %lld\n", sx, sy);
    printf("%lld\n", sx * sx + sy * sy);
    return 0;
}
