#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <bitset>
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], * p1 = buf, * p2 = buf;
//#define int long long
#define lowbit(x) (x&(-x))
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<int, int> pii;
#define bug puts("BUG")
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
template<class T>inline void read(T& x) {
	int sign = 1; char c = getchar(); x = 0;
	while (c > '9' || c < '0') { if (c == '-')sign = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	x *= sign;
}
using namespace std;
const int maxn = 110;
char s[maxn], ans[maxn];
int main()
{
	int t;
	int n;
	int R, P, S;
	int cntr, cntp, cnts;
	for (read(t); t--;)
	{
		read(n);
		read(cntr), read(cntp), read(cnts);
		scanf("%s",s);
		int wins = 0;
		for (int i = 0; s[i]; ++i)
		{
			if (s[i] == 'R' && cntp)
			{
				ans[i] = 'P';
				--cntp;
				++wins;
			}else if (s[i] == 'P' && cnts)
			{
				ans[i] = 'S';
				--cnts;
				++wins;
			}
			else if (s[i] == 'S' && cntr)
			{
				ans[i] = 'R';
				--cntr;
				++wins;
			}
			else
			{
				ans[i] = 0;
			}
		}
		if (wins >= (n + 1) / 2)
		{
			for (int i = 0; i < n; ++i)
			{
				if (!ans[i])
				{
					if (cntr)ans[i] = 'R', --cntr;
					else if (cnts)ans[i] = 'S', --cnts;
					else if (cntp)ans[i] = 'P', --cntp;
				}
			}
			puts("YES");
			for (int i = 0; i < n; ++i)
				putchar(ans[i]);
			puts("");
		}else
		{
			puts("NO");
		}
	}
}