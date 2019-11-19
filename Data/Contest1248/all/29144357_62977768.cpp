# include<bits/stdc++.h>
 
using namespace std;
 
# define int long long
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

void solve()
{
	int c[2][2] = {{0, 0}, {0, 0}};
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		int a;
		cin >> a;
		c[0][a & 1] ++;
	}
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		int a;
		cin >> a;
		c[1][a & 1] ++;
	}
	cout << c[0][0] * c[1][0] + c[0][1] * c[1][1] << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t --)
		solve();

	return 0;
}
