// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define f first
#define s second
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())
#define bitc(n) __builtin_popcount(n)
#define MAGIC0 mt19937 rnd(time(0)); //rnd()
 
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = 1LL * INF * INF;
const int MAX = 1e6 + 7;
const double PI = acos(-1.);
const double EPS = 1e-7;
const int MAXN = 2 * 1007; 
const int MOD = 1000 * 1000 * 1000 + 7;

LL g[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("roads.in", "r", stdin);
	//freopen("roads.out", "w", stdout);
	int n;
	cin >> n;
	VI x(n), y(n);
	FOR(i, 0, n)
	{
		cin >> x[i] >> y[i];
	}
	vector<LL> c(n), k(n);
	FOR(i, 0, n)
	{
		cin >> c[i];
	}
	FOR(i, 0, n)
	{
		cin >> k[i];
	}

	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			int len = (abs(x[i] - x[j]) + abs(y[i] - y[j]));
			g[i][j] = (k[i] + k[j]) * len;
			g[j][i] = (k[i] + k[j]) * len;
		}
		g[i][n] = c[i];
		g[n][i] = c[i];
	}

	++n;
	vector<bool> used (n);
	vector<LL> min_e (n, INF), sel_e (n, -1);
	min_e[n-1] = 0;
	set<PII> st;
	LL ans = 0;
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INF) {
			cout << "No MST!";
			exit(0);
		}
	 
		used[v] = true;
		if (sel_e[v] != -1)
		{
			ans += g[v][sel_e[v]];
			st.insert({min((LL)v, sel_e[v]), max((LL) v, sel_e[v])});
			// cout << v << " " << sel_e[v] << endl;
		}
	 
		for (int to=0; to<n; ++to)
			if (g[v][to] < min_e[to]) {
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}

	int cnt = 0;
	for(auto [u, v] : st)
	{
		if (v == n - 1)
		{
			++cnt;
		}
	}
	cout << ans << "\n" << cnt << "\n";
	for(auto [u, v] : st)
	{
		if (v == n - 1)
		{
			cout << u + 1 << " ";
		}
	}
	cout << "\n" << n - cnt - 1 << "\n";
	for(auto [u, v] : st)
	{
		if (v == n - 1)
		{
			continue;
		}
		cout << u + 1 << " " << v + 1 << "\n";
	}


	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
