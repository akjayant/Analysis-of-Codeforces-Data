#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;
const int L = 3;
LL dp[MAX][L][L];
VI g[MAX];
LL C[MAX][3];
VI A;
int R[MAX];
int R1[MAX];

int mex(int c1, int c2)
{
	FOR(i, 0, L)
	{
		if (i != c1 && i != c2) return i;
	}
}

void dfs(int v, int p)
{
	A.PB(v);
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (to == p) continue;

		dfs(to, v);
	}
}

int main()
{
	// freopen("in.txt","r", stdin);
	ios::sync_with_stdio(false);cin.tie(0);
	FOR(v, 0, MAX)
	{
		FOR(i, 0, L)
		{
			FOR(j, 0, L) dp[v][i][j] = LINF;
		}
	}

	int n;
	cin >> n;
	FOR(i, 0, L)
	{
		FOR(j, 0, n)
		{
			cin >> C[j][i];
		}
	}

	FOR(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].PB(b);
		g[b].PB(a);
	}

	FOR(i, 0, n)
	{
		if (SZ(g[i]) > 2)
		{
			cout << -1 << endl;
			exit(0);
		}
	}

	int root = -1;
	FOR(v, 0, n)
	{
		if (SZ(g[v]) == 1)
		{
			root = v;
			break;
		}
	}

	dfs(root, -1);

	FOR(c1, 0, L)
	{
		FOR(c2, 0, L)
		{
			if (c1 == c2) continue;

			LL tmp =  C[A[1]][c1] + C[A[0]][c2];
			dp[1][c1][c2] = min(dp[1][c1][c2], tmp);
		}
	}

	FOR(v, 2, n)
	{
		FOR(c, 0, L)
		{
			FOR(c1, 0, L)
			{
				if (c1 == c) continue;
				int c2 = mex(c, c1);

				dp[v][c][c1] = min(dp[v][c][c1], dp[v - 1][c1][c2] + C[A[v]][c]);
			}
		}
	}

	int cc1 = 0, cc2 = 0;
	FOR(c1, 0, L)
	{
		FOR(c2, 0, L)
		{
			if (dp[n - 1][cc1][cc2] > dp[n - 1][c1][c2])
			{
				cc1 = c1;
				cc2 = c2;
			}

		}
	}

	cout << dp[n - 1][cc1][cc2] << endl;
	RFOR(v, n, 1)
	{
		R[v] = cc1;
		R[v - 1] = cc2;

		int tmp = -1;

		FOR(c2, 0, L)
		{
			if (c2 == cc2 || c2 == cc1) continue;

			if (dp[v - 1][cc2][c2] + C[A[v]][cc1] == dp[v][cc1][cc2])
			{
				tmp = c2;
				//break;
			}
		}

		cc1 = cc2;
		cc2 = tmp;
	}

	FOR(v, 0, n)
	{
		R1[A[v]] = R[v];
	}

	FOR(i, 0, n)
	{
		cout << R1[i] + 1 << " ";
	}

	cout << endl;
	return 0;
}
