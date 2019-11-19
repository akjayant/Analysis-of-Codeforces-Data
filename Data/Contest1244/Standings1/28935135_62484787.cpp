#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
 
const int N = 111111;
const int M = 666;
const ll md = 1e9 + 7;
 
int n, m, k, q;
int ans;
int a[3][N];
vector<int> v[N];
int aa[N], c[N];

int f(int a, int b)
{
	int c = 7 ^ (1 << a) ^ (1 << b);
	if (c == 1)
		return 0;
	if (c == 2)
		return 1;
	return 2;
}

int work()
{
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() > 2)
		{
			return 0;
		}
	}
	if (v[1].size() == 1)
	{
		k = 1;
	}
	else
	{
		k = v[1][0];
		for (int last = 1; v[k].size() != 1;)
		{
			int nxt = v[k][0] == last ? v[k][1] : v[k][0];
			last = k;
			k = nxt;
		}
	}
	
	ll ans = md * md;
	for (int c1 = 0; c1 < 3; c1++)
	{
		for (int c2 = 0; c2 < 3; c2++)
		{
			if (c1 == c2)
			{
				continue;
			}
			for (int i = 1; i <= n; i++)
			{
				c[i] = -1;
			}
			c[k] = c1;
			c[v[k][0]] = c2;
			ll s = a[c1][k] + a[c2][v[k][0]];
			for (int cur = v[k][0], last = k; v[cur].size() > 1;)
			{
				//printf("%d %d\n", last, cur);
				int nxt = v[cur][0] == last ? v[cur][1] : v[cur][0];
				int nxtc = f(c[last], c[cur]);
				last = cur;
				cur = nxt;
				c[cur] = nxtc;
				s += a[nxtc][nxt];
				//printf("nxt %d %d %d\n", nxt, nxtc, s);
			}
			if (s < ans)
			{
				ans = s;
				for (int i = 1; i <= n; i++)
				{
					aa[i] = c[i] + 1;
				}
			}
		}
	}
	
	printf("%I64d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", aa[i], i == n ? '\n' : ' ');
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false); cout<<setprecision(20);
 
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (!work())
	{
		puts("-1");
	}
	
	return 0;
}