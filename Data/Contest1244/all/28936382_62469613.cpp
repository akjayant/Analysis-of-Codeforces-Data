#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<time.h>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<unordered_map>
#include<ctype.h>
#include<random>
#include<iostream>
#include<complex>
using namespace std;
typedef long long ll;
typedef double db;
#define _Zero(a) memset(a,0,sizeof(a))
#define _Neg1(a) memset(a,-1,sizeof(a))
#define _Inf(a) memset(a,0x3f,sizeof(a))
#define _NegInf(a) memset(a,0xcf,sizeof(a))
#define _Rep(i,a,b) for(int (i)=(a);(i)<=(b);i++)
#define _Dep(i,a,b) for(int (i)=(a);(i)>=(b);i--)
#define _Out(a)	cerr<<#a<<" = "<<(a)<<endl
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const db EPS = 1e-6;
const db Pi = acos(-1);
void test() { cerr << "\n"; }
template <typename T, typename...Args>void test(T x, Args...args) { cerr << x << " "; test(args...); }
ll qpow(ll a, ll b) { return b ? ((b & 1) ? a * qpow(a * a % MOD, b >> 1) % MOD : qpow(a * a % MOD, b >> 1)) % MOD : 1; }
ll qpow(ll a, ll b, ll c) { return b ? ((b & 1) ? a * qpow(a * a % c, b >> 1) % c : qpow(a * a % c, b >> 1)) % c : 1; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int sign(db x) { return x<-EPS ? -1 : x>EPS; }
int dbcmp(db l, db r) { return sign(l - r); }

char ss[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d%s", &n, ss + 1);
		int cnt1 = 0,ans=0;
		for (int i = 1; i <= n; i++)
		{
			if (ss[i] == '1')
			{
				cnt1++;
				ans = max(ans, 2 * max(i, n - i + 1));

			}

		}
		ans = max(ans, n + cnt1);
		printf("%d\n", ans);
	}

}