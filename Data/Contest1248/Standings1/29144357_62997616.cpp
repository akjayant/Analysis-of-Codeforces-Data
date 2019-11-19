# include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define UB upper_bound 

const int MAXN = 500 + 10;
int n;
string s;
int sum[MAXN], minf[MAXN], minb[MAXN];

int cnt(int x, int y)
{
	swap(s[x - 1], s[y - 1]);
	for (int i = 0; i < n; i ++)
		sum[i + 1] = sum[i] + ((s[i] == '(') ? 1 : -1);
	minf[0] = INT_MAX;
	for (int i = 1; i <= n; i ++)
		minf[i] = min(minf[i - 1], sum[i]);
	minb[n + 1] = INT_MAX;
	for (int i = n; i >= 1; i --)
		minb[i] = min(minb[i + 1], sum[i]);
	
	int res = 0;
	for (int i = 0; i < n; i ++)
		if (minb[i + 1] - sum[i] >= 0 && minf[i] + (sum[n] - sum[i]) >= 0)
			res ++;
	swap(s[x - 1], s[y - 1]);
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> s;

	int ans = 0;
	pii p = {1, 1};
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			int a = cnt(i, j);
			if (a > ans)
			{
				ans = a;
				p.F = i, p.S = j;
			}
		}

	if (sum[n] != 0)
		kill("0\n1 1");

	cout << ans << "\n" << p.F << " " << p.S << "\n";
	
	return 0;
}
