#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#include <cassert>
#include <complex>

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
#define memset0(x) memset(x, 0, sizeof(x))
#define memsetM1(x) memset(x, -1, sizeof(x))
#define memsetINF(x) memset(x, INF, sizeof(x))

using namespace std;

int last;
int n, m, k;

const int MAXN = 1e5 + 5;
set<int> sx[MAXN], sy[MAXN];
bool yes = true;
void dfs(int cx, int cy, int ex, int ey, int dir)
{
	if (cx > ex || cy > ey)
	{
		return;
	}
	if (dir == 0)
	{
		int lasty = ey;
		if (!sx[cx].empty())
		{
			int vy = *(sx[cx].begin());
			lasty = vy - 1;
			long long req = 1ll * (ey - vy + 1) * (ex - cx + 1);
			if (req > last)
			{
				yes = false;
				return;
			}
			last -= req;
			for (int i = cx; i <= ex; i++)
			{
				for (int j = vy; j <= ey; j++)
				{
					if (!sx[i].count(j))
					{
						yes = false;
						return;
					}
					if (!sy[j].count(i))
					{
						yes = false;
						return;
					}
					sx[i].erase(j);
					sy[j].erase(i);
				}
			}
		}
		dfs(cx + 1, cy, ex, lasty, 1);
	}
	else if (dir == 2)
	{
		int lasty = cy;
		if (!sx[ex].empty())
		{
			int vy = *(prev(sx[ex].end()));
			lasty = vy + 1;
			long long req = 1ll * (vy - cy + 1) * (ex - cx + 1);
			if (req > last)
			{
				yes = false;
				return;
			}
			last -= req;
			for (int i = cx; i <= ex; i++)
			{
				for (int j = cy; j <= vy; j++)
				{
					if (!sx[i].count(j))
					{
						yes = false;
						return;
					}
					if (!sy[j].count(i))
					{
						yes = false;
						return;
					}
					sx[i].erase(j);
					sy[j].erase(i);
				}
			}
		}
		dfs(cx, lasty, ex - 1, ey, 3);
	}
	else if (dir == 1)
	{
		int lastx = ex;
		if (!sy[ey].empty())
		{
			int vx = *(sy[ey].begin());
			lastx = vx - 1;
			long long req = 1ll * (ex - vx + 1) * (ey - cy + 1);
			if (req > last)
			{
				yes = false;
				return;
			}
			last -= req;
			for (int i = vx; i <= ex; i++)
			{
				for (int j = cy; j <= ey; j++)
				{
					if (!sx[i].count(j))
					{
						yes = false;
						return;
					}
					if (!sy[j].count(i))
					{
						yes = false;
						return;
					}
					sx[i].erase(j);
					sy[j].erase(i);
				}
			}
		}
		dfs(cx, cy, lastx, ey - 1, 2);
	}
	else
	{
		int lastx = cx;
		if (!sy[cy].empty())
		{
			int vx = *(prev(sy[cy].end()));
			lastx = vx + 1;
			long long req = 1ll * (vx - cx + 1) * (ey - cy + 1);
			if (req > last)
			{
				yes = false;
				return;
			}
			last -= req;
			for (int i = cx; i <= vx; i++)
			{
				for (int j = cy; j <= ey; j++)
				{
					if (!sx[i].count(j))
					{
						yes = false;
						return;
					}
					if (!sy[j].count(i))
					{
						yes = false;
						return;
					}
					sx[i].erase(j);
					sy[j].erase(i);
				}
			}
		}
		dfs(lastx, cy + 1, ex, ey, 0);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int startTime = clock();
#endif
	scanf("%d%d%d", &n, &m, &k);
	last = k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		sx[x].insert(y);
		sy[y].insert(x);
	}
	dfs(1, 1, n, m, 0);
	if (yes)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}

#ifndef ONLINE_JUDGE
	printf("Time = %dms\n", clock() - startTime);
#endif
	return 0;
}
