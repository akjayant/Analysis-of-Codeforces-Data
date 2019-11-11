// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < (b); ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
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
const int MAXN = 2 * 1000007; 

void solve()
{
	int n, R, P, S;
	cin >> n >> R >> P >> S;
	string t;
	cin >> t;

	string ans(n, 'a');
	int res = 0, a = 0, b = 0, c = 0;
	FOR(i, 0, SZ(t))
	{
		a += t[i] == 'R';
		b += t[i] == 'P';
		c += t[i] == 'S';
	}
	res += min(a, P);
	res += min(b, S);
	res += min(c, R);
	if (!(res >= (n + 1) / 2))
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	FOR(i, 0, n)
	{
		if (t[i] == 'S' && R)
		{
			--R;
			ans[i] = 'R';
		}
	}
	FOR(i, 0, n)
	{
		if (t[i] == 'R' && P)
		{
			--P;
			ans[i] = 'P';
		}
	}
	FOR(i, 0, n)
	{
		if (t[i] == 'P' && S)
		{
			--S;
			ans[i] = 'S';
		}
	}
	FOR(i, 0, n)
	{
		if (ans[i] == 'a')
		{
			if (S > 0)
			{
				--S;
				ans[i] = 'S';
			}
			else
			if (P > 0)
			{
				ans[i] = 'P';
				--P;
			}
			else
			if (R > 0)
			{
				ans[i] = 'R';
				--R;
			}
		}
		cout << ans[i];
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("roads.in", "r", stdin);
	//freopen("roads.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
