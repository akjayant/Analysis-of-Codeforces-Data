#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <bitset>
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], * p1 = buf, * p2 = buf;
//#define int long long
#define lowbit(x) (x&(-x))
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<int, int> pii;
#define bug puts("BUG")
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
template<class T>inline void read(T& x) {
	int sign = 1; char c = getchar(); x = 0;
	while (c > '9' || c < '0') { if (c == '-')sign = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	x *= sign;
}
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn];
ll dp[maxn];
int main()
{
	scanf("%s", s + 1);
	int len = 1;
	dp[0] = dp[1] = 1;
	for (int i = 2; s[i]; ++i, ++len)
	{
		if (s[i] == 'm' || s[i] == 'w')
		{
			puts("0");
			return 0;
		}
		else if (s[i] == 'u' && s[i - 1] == 'u')
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		else if (s[i] == 'n' && s[i - 1] == 'n')
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		else
			dp[i] = dp[i - 1];
	}
	if (s[1] == 'm' || s[1] == 'w')dp[len] = 0;
	printf("%lld\n", dp[len]);
}