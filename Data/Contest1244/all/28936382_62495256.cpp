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
const int MAXN = 2e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const db EPS = 1e-6;
const db Pi = acos(-1);
void test() { cerr << "\n"; }
template <typename T,typename...Args>void test(T x,Args...args){cerr<<x<<" ";test(args...); }
ll qpow(ll a, ll b) {return b?((b&1)?a*qpow(a*a%MOD,b>>1)%MOD : qpow(a*a%MOD,b>>1))%MOD :1; }
ll qpow(ll a, ll b, ll c) {return b?((b&1)?a*qpow(a*a%c,b>>1)%c : qpow(a*a%c,b>>1)) % c: 1; }
ll gcd(ll a, ll b){return b?gcd(b,a% b): a; }
int sign(db x) { return x<-EPS ? -1: x>EPS; }
int dbcmp(db l, db r) { return sign(l - r); }

ll a[MAXN];
int main()
{
	int n; ll k;
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
	while (k > 0&&l<r)
	{
		while (l < r && a[l] == a[l + 1])l++;
		while (l < r && a[r] == a[r - 1])r--;
		if (l < n - r+1)
		{
			ll ned = (a[l + 1] - a[l]) * l;
			if (ned > k)
			{
				printf("%lld\n", a[r] - a[l] - k / l);
				return 0;
			}
			k -= ned;
			l++;
		}
		else
		{
			ll ned = (a[r] - a[r-1]) * (n-r+1);
			if (ned > k)
			{
				printf("%lld\n", a[r] - a[l] - k /(n-r+1));
				return 0;
			}
			k -= ned;
			r--;
		}
	}
	printf("%lld\n", a[r] - a[l]);

}
/*

*/