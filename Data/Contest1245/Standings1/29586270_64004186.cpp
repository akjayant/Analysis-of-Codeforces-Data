#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

const int MAX = 1e5+1;
const ll MOD = 1e9 + 7;

ll fib[MAX];

void calc(void)
{
	fib[1] = 1;
	fib[2] = 2;
	FOR(i,3, MAX)
		fib[i] = (fib[i-1] + fib[i-2])%MOD;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	calc();

	ll ans(1);

	string s;
	read(s);
	int n = s.size();
	FOR(i,0,n)
		if (s[i] == 'w' or s[i] == 'm')
		{
			cout << 0 << endl;
			return 0;
		}

	int i(0);
	while (i < n)
	{
		if (s[i] != 'n' and s[i] != 'u')
		{
			++i;
			continue;
		}

		int j(0);
		while (i + j < n and s[i] == s[i+j])
			++j;
		ans = (ans * fib[j])%MOD;
		i += j;
	}

	pnl(ans);
}

