#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;
//s.find_by_order()
//s.order_of_key()
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define SZ(a) (int)a.size()
#define FOR(i, a, b) for(int i = (a);i < (b);++i)
#define RFOR(i, b, a) for(int i = (b)-1;i >= (a);--i)
#define PB push_back
#define MP make_pair
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define f first
#define s second

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1ll * INF * INF;
const long double PI = acos(-1.0);
const int MAXN = 1e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

VI x[MAXN];
int c[MAXN][3];
int col[MAXN];
int best[MAXN];
int colors[3];

void dfs(int v, int par= -1, int h = 0)
{
	col[v] = colors[h % 3];
	FOR(i ,0, SZ(x[v]))
	{
		int to = x[v][i];
		if (to == par)
		{
			continue;	
		}
		dfs(to, v, h + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, 3)
	{
		FOR(j, 0, n)
		{
			cin >> c[j][i];
		}
	}
	
	FOR(i, 1, n)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		x[u].PB(v);
		x[v].PB(u);
	}
	
	FOR(i, 0, n)
	{
		if (SZ(x[i]) > 2)
		{
			cout << -1 << "\n";
			return 0;
		}
	}
	LL ans = LINF;
	
	VI p(3);
	FOR(i, 0, 3)
	{
		p[i] = i;	
	}
	FOR(it, 0, 6)
	{
		FOR(i, 0, 3)
		{
			colors[i] = p[i];	
		}
		FOR(i, 0, n)
		{
			if (SZ(x[i]) == 1)
			{
				dfs(i, -1, 0);	
				break;
			}
		}
		LL res = 0;
		FOR(i, 0, n)
		{
			res += c[i][col[i]];	
		}
		if (ans > res)
		{
			ans = res;
			FOR(i, 0, n)
			{
				best[i] = col[i];
			}
		}
		next_permutation(ALL(p));
	}
	
	cout << ans << "\n";
	FOR(i, 0, n)
	{
		cout << best[i] + 1 << " ";
	}
	
	return 0;
}


















