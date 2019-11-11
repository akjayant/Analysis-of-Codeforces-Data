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


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("roads.in", "r", stdin);
	//freopen("roads.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if (__gcd(a, b) == 1)
		{
			cout << "Finite\n";
		}
		else
		{
			cout << "Infinite\n";
		}
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
