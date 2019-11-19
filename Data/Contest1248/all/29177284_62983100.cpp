#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<unordered_map>
#include<random>
using namespace std;
typedef  long long ll;
const int MAXN = 1e6 + 5;
#define CLR(a) memset(a,0,sizeof a)
#define _space putchar(' ')
#define _endl putchar('\n')
#define _unique(v) sort(v.begin(), v.end()),v.erase(unique(v.begin(), v.end()),v.end());
mt19937_64 _r(random_device{}());
template <class T>inline void in(T& x) { static char ch; static bool neg; for (ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar()); for (x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar()); x = neg ? -x : x; }
template <class T>T quick_pow(T a, T b, T mod) { T base = a, res = 1; while (b) { if (b & 1)res = (res * base) % mod; base = (base * base) % mod; b >>= 1; }return res; }
template <class T>inline void o(T x) { if (x < 0) { putchar('-'); x = -x; }if (x > 9)o(x / 10); putchar(x % 10 + '0'); }
//--------------------------------------Azir------------------------------


int32_t main()
{
		//freopen("Azir.in", "r", stdin); 
	int t;
	in(t);
	while (t--)
	{
		int n;
		in(n);
		int a, b, c, d;
		a = b = c = d = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			in(tmp);
			if (tmp & 1)a++;
			else b++;
		}

		int m;
		in(m);
		for (int i = 0; i < m; i++)
		{
			int tmp;
			in(tmp);
			if (tmp & 1)c++;
			else d++;
		}
		printf("%lld\n", 1ll*a*c + 1ll*b*d);

	}

	return 0;
}
