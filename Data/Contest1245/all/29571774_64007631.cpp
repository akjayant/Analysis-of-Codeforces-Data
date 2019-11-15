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

char ch[MAXN];
char ans[MAXN];
const LL MOD = 1e9 + 7;
LL f[MAXN][2];

int main()
{
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    for (int  i = 1; i <= n; ++ i)
    {
	if (ch[i] == 'w' || ch[i] == 'm')
	    return puts("0");
    }
    LL cnt = 0, pre = 0;
    LL ans = 1;
    f[1][0] = 1; f[1][1] = 0;
    for (int i = 2; i <= n; ++ i)
    {
	f[i][1] = f[i - 1][0];
	f[i][0] = (f[i - 1][0] + f[i - 1][1]) % MOD;
//	printf("f[%d]: %lld %lld\n" ,i, f[i][0], f[i][1]);
    }
    for (int i = 1; i <= n; ++ i)
    {
	if (ch[i] == 'n')
	{
	    if (pre == 1) ++ cnt;
	    else
	    {
		if (cnt)
		{
		    (ans *= (f[cnt][0] + f[cnt][1]) % MOD) %= MOD;
		}
		cnt = 1;
		
	    }
	    pre = 1;
	}
	else if (ch[i] == 'u')
	{
	    if (pre == 2) ++ cnt;
	    else
	    {
		if (cnt)
		{
		    (ans *= (f[cnt][0] + f[cnt][1]) % MOD) %= MOD;
		}
		cnt = 1;
	    }
	    pre = 2;
	}
	else
	{
	    if (cnt)
	    {
		(ans *= (f[cnt][0] + f[cnt][1]) % MOD) %= MOD;
	    }
	    cnt = pre = 0;
	}
    }
    if (cnt)
    {
	(ans *= (f[cnt][0] + f[cnt][1]) % MOD) %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
