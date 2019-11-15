#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

typedef long long LL;
const int MAXN = 1e6 + 10, MAXM = 1e6 + 10;
using namespace std;
typedef pair <LL, int> PLI;
typedef pair <LL, LL> PLL;
#define mkpr make_pair
#define fi first
#define se second

inline int in()
{
    int x = 0, flag = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') flag = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * flag;
}

int n, m, K;

int head[MAXN], nume;
struct Adj { int nex, to;  } adj[MAXM << 1]; // un g
void addedge(int from, int to)
{
    adj[++ nume] = (Adj) { head[from], to } ;
    head[from] = nume;
}
void link(int u, int v)
{
    addedge(u, v);
    addedge(v, u);
}

int gcd(int a, int b)
{
    if (b ==0 )return a;
    else return gcd(b, a % b);
}

int main()
{
    int t = in();
    while (t --)
    {
	int a = in(), b = in();
	if (gcd(a, b) == 1) printf("Finite\n");
	else printf("Infinite\n");
    }
    return 0;
}
