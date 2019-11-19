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

const int MAXN = 100 * 1000 + 10, MOD = 1000 * 1000 * 1000 + 7;
int b[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	b[0] = b[1] = 1;
	for (int i = 2; i <= max(n, m); i ++)
		b[i] = (b[i - 1] + b[i - 2]) % MOD;
	cout << (2 * b[n] + 2 * b[m] - 2) % MOD << endl;
	return 0;
}
