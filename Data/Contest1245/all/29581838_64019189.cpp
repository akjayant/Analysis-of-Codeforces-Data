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
const int MAXN = 2 * 100007; 
const int MOD = 1000 * 1000 * 1000 + 7;

LL fact[MAXN];
LL invfact[MAXN];

LL binpow(LL a, LL n)
{
	LL res = 1;
	while(n > 0)
	{
		if (n % 2)
		{
			res = res % MOD * a % MOD;
			res %= MOD;
		}
		a = a % MOD * a % MOD;
		a %= MOD;
		n >>= 1;
	}
	return res;
}

LL C(LL n, LL k)
{
	return (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("roads.in", "r", stdin);
	//freopen("roads.out", "w", stdout);
	string s;
	cin >> s;

	fact[0] = 1;
	FOR(i, 1, MAXN)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	invfact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
	RFOR(i, MAXN - 1, 0)
	{
		invfact[i] = invfact[i + 1] * (i + 1);
		invfact[i] %= MOD;
	}

	FOR(i, 0, SZ(s))
	{
		if (s[i] == 'm' || s[i] == 'w')
		{
			cout << "0\n";
			return 0;
		}
	}

	int w = 0, m = 0;
	LL ans = 1;
	FOR(i, 0, SZ(s))
	{
		if (s[i] == 'u')
		{
			++w;
			LL res = 0;
			if (m > 1)
			{
				FOR(j, 0, m/2+1)
				{
					res += C(m - j, j);
					res %= MOD;
				}
				// cout << "resm " << res << "\n";
				ans *= res;
				ans %= MOD;
			}
			m = 0;			
		}
		else
		if (s[i] == 'n')
		{
			++m;
			LL res = 0;
			if (w > 1)
			{
				FOR(j, 0, w / 2 + 1)
				{
					res += C(w - j, j);
					res %= MOD;
				}
				// cout << "resw " << res << "\n";
				ans *= res;
				ans %= MOD;
			}		
			w = 0;	
		}
		else
		{
			LL res = 0;
			if (w > 1)
			{
				FOR(j, 0, w / 2 + 1)
				{
					res += C(w - j, j);
					res %= MOD;
				}
				// cout << "resw " << res << "\n";
				ans *= res;
				ans %= MOD;
			}
			res = 0;
			w = 0;	
			if (m > 1)
			{
				FOR(j, 0, m/2+1)
				{
					res += C(m - j, j);
					res %= MOD;
				}
				// cout << "resm " << res << "\n";
				ans *= res;
				ans %= MOD;
			}
			m = 0;
		}
	}

	LL res = 0;
	if (w > 1)
	{
		FOR(j, 0, w / 2 + 1)
		{
			res += C(w - j, j);
			res %= MOD;
		}
		ans *= res;
		ans %= MOD;
	}	
	res = 0;
	if (m > 1)
	{
		// cout << "kek\n";
		FOR(j, 0, m / 2 + 1)
		{
			res += C(m - j, j);
			res %= MOD;
		}
		// cout << res << "\n";
		ans *= res;
		ans %= MOD;
	}	
	cout << ans << "\n";

	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
