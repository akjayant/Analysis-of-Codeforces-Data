#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const LL mod = 1e9+7;

int n , m , q , lx , ly , rx , ry;
LL s , s0;
set<int> sx1[maxn] , sy1[maxn] , sx2[maxn] , sy2[maxn];

int main()
{
	int i , j , x , y;
	cin >> n >> m >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&x,&y);
		sx1[x].insert(y);
		sy1[y].insert(x);
		sx2[x].insert(-y);
		sy2[y].insert(-x);
	}
	rx = n+1;
	ry = m+1;
	lx = x = 1;
	ly = y = s = 0;
	while (1)
	{
		s0 = s;
		auto p1 = sx1[x].lower_bound(y);
		if (p1 == sx1[x].end() || (*p1) >= ry)
		{
			s += ry-y-1;
			ry--;
			y = ry;
		}
		else
		{
			s += (*p1)-y-1;
			ry = (*p1)-1;
			y = ry;
		}
		if (s0 == s) break;
		s0 = s;
		auto p2 = sy1[y].lower_bound(x);
		if (p2 == sy1[y].end() || (*p2) >= rx)
		{
			s += rx-x-1;
			rx--;
			x = rx;
		}
		else
		{
			s += (*p2)-x-1;
			rx = (*p2)-1;
			x = rx;
		}
		if (s0 == s) break;
		s0 = s;
		auto p3 = sx2[x].lower_bound(-y);
		if (p3 == sx2[x].end() || -(*p3) <= ly)
		{
			s += y-ly-1;
			ly++;
			y = ly;
		}
		else
		{
			s += y+(*p3)-1;
			ly = 1-(*p3);
			y = ly;
		}
		if (s0 == s) break;
		s0 = s;
		auto p4 = sy2[y].lower_bound(-x);
		if (p4 == sy2[y].end() || -(*p4) <= lx)
		{
			s += x-lx-1;
			lx++;
			x = lx;
		}
		else
		{
			s += x+(*p4)-1;
			lx = 1-(*p4);
			x = lx;
		}
		if (s0 == s) break;
	}
	if (s == (LL)n*m-q) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
