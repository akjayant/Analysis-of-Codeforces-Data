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
const LL MOD  = 1e9 + 7;

char ch[MAXN];

LL f[MAXN][2];

int main()
{
    scanf("%d%d", &n, &m);
    f[0][0] = f[0][1] = 1;
    for (int i = 1; i <= max(m, n); ++ i)
    {
	(f[i][0] += f[i - 1][1]) %= MOD;
	(f[i][1] += f[i - 1][0]) %= MOD;
	if (i >= 2)
	{
	    (f[i][0] += f[i - 2][1]) %= MOD;
	    (f[i][1] += f[i - 2][0]) %= MOD;
	}
//	printf("f[%d][] = %lld %lld\n", i, f[i][0], f[i][1]);
    }
    printf("%lld\n", ((f[n][0] + f[n][1] + f[m][0] + f[m][1]) % MOD - 2 + MOD) % MOD);
    return 0;
}
