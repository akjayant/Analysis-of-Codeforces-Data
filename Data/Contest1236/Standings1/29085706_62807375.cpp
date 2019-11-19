#include <iostream>
#include <set>
#include <functional>
#include <algorithm>
typedef long long ll;
using namespace std;
set<int> row[100010];
set<int> col[100010];
set<int, greater<int> > rrow[100010];
set<int, greater<int> > rcol[100010];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		row[x].insert(y);
		col[y].insert(x);
		rrow[x].insert(y);
		rcol[y].insert(x);
	}
	int u = 1, l = 0, d = n + 1, r = m + 1;
	int px = 1;
	int py = 0;
	ll cnt = 0;
	int t = 0;
	for (int i = 0; i <= n; i++)
	{
		row[i].insert(0);
		row[i].insert(m + 1);
		rrow[i].insert(0);
		rrow[i].insert(m + 1);
	}

	for (int i = 0; i <= m; i++)
	{
		col[i].insert(0);
		col[i].insert(n + 1);
		rcol[i].insert(0);
		rcol[i].insert(n + 1);
	}
	// remove start point (1, 0)
	row[1].erase(0);
	rrow[1].erase(0);
	col[0].erase(1);
	rcol[0].erase(1);
	for(;;)
	{
		int nx = px;
		int ny = py;
		bool finish = false;
		switch (t)
		{
			case 0:
			{
				ny = min(r, *(row[px].lower_bound(py))) - 1;
				finish |= ny == py;
				cnt += ny - py;
				r = ny;
				t = 1;
				break;
			}
			case 1:
			{
				nx = min(d, *(col[py].lower_bound(px))) - 1;
				finish |= nx == px;
				cnt += nx - px;
				d = nx;
				t = 2;
				break;
			}
			case 2:
			{
				ny = max(l, *(rrow[px].lower_bound(py))) + 1;
				finish |= ny == py;
				cnt += py - ny;
				l = ny;
				t = 3;
				break;
			}
			case 3:
			{
				nx = max(u, *(rcol[py].lower_bound(px))) + 1;
				finish |= nx == px;
				cnt += px - nx;
				u = nx;
				t = 0;
				break;
			}
		}
		if (finish)
		{
			if (k + cnt == 1ll * n * m)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			break;
		}
		px = nx;
		py = ny;
	}
}