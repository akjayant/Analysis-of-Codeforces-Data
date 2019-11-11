#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
char s[maxn];
int dp[maxn];

int main()
{
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	int n;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'w' || s[i] == 'm')
			return printf("0\n"), 0;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (s[i] == 'u' && s[i - 1] == 'u')
			(dp[i] += dp[i - 2]) %= mod;
		if (s[i] == 'n' && s[i - 1] == 'n')
			(dp[i] += dp[i - 2]) %= mod;
	}
	printf("%d\n", dp[n]);
	return 0;
}