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


char ch[MAXN];
int sum[MAXN], mn[MAXN][2];

int main()
{
    scanf("%d", &n);
    scanf("%s", ch + 1);
    int ans = 0, x = 1, y = 1;
    for (int i = 1; i <= n; ++ i)
    {
	for (int j = i; j <= n; ++ j)
	{
	    swap(ch[i], ch[j]);
	    int cnt = 0;
	    sum[0] = 0;
	    mn[0][0] = 233333333;
	    mn[n + 1][1] = 233333333;
	    for (int k = 1; k <= n; ++ k) 
	    {
		if (ch[k] == '(') sum[k] = sum[k - 1] + 1;
		else sum[k] = sum[k - 1] - 1;
		mn[k][0] = min(mn[k - 1][0], sum[k]);
	    }
	    int flag = 1;
	    for (int k = 1; k <= n; ++ k) if (sum[k] < 0) flag = 0;
	    if (sum[n] != 0)
	    {
		swap(ch[i], ch[j]);
		continue;
	    }
	    for (int k = n; k > 1; -- k) 
	    {
		mn[k][1] = min(mn[k + 1][1], sum[k]);
		if (mn[k][1] - sum[k - 1] >= 0 && mn[k - 1][0] + sum[n] - sum[k - 1] >= 0) ++ cnt;
	    }
	    cnt = cnt + flag;
	    if (cnt > ans) ans = cnt, x = i, y = j;
	    swap(ch[i], ch[j]);
	}
    }
    printf("%d\n" ,ans );
    printf("%d %d\n", x ,y);
    return 0;
}
