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

int main()
{
    int t = in();
    while (t --)
    {
        scanf("%d", &n);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int cnt = 0;
	scanf("%s", ch + 1);
	for (int i = 1; i <= n; ++ i)
	{
	    if (ch[i] == 'R')
	    {
		if (b > 0) ++ cnt, -- b, ans[i] = 'P';
		else ans[i] = ' ';
	    }
	    else if (ch[i] == 'P')
	    {
		if (c > 0) ++ cnt, -- c, ans[i] = 'S';
		else ans[i] = ' ' ;
	    }
	    else
	    {
		if (a > 0) ++ cnt, -- a, ans[i] = 'R';
		else ans[i] = ' ' ;
	    }
	}
	if (cnt >= (int)ceil(n * 0.5))
	{
	    puts("YES");
	    for (int i = 1; i <= n; ++ i)
	    {
		if (ans[i] == ' ')
		{
		    if (a) printf("R"), --a;
		    else if (b) printf("P"), -- b;
		    else if (c) printf("S"), --c;
		}
		else printf("%c", ans[i]);
	    }
	    puts("");
	}
	else 
	{
	    puts("NO");
	}
    }
    return 0;
}
