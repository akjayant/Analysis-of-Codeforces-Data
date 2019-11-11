#include <cstdio>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))

typedef long long ll;
ll read()
{
	ll ret = 0, t = 1; char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100005, MOD = 1000000007;
char S[MAXN]; ll ans = 1, qaq[MAXN]; int N;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	#endif
	scanf("%s", S + 1), N = strlen(S + 1);
	int i, count = 0;
	qaq[0] = qaq[1] = 1;
	for (i = 2; i <= N; ++i) qaq[i] = (qaq[i - 1] + qaq[i - 2]) % MOD;
	for (i = 1; i <= N; ++i)
	{
		if (S[i] == 'm' || S[i] == 'w') { puts("0"); return 0; }
		if (i != 1 && S[i] != S[i - 1])
		{
			if (S[i - 1] == 'n' || S[i - 1] == 'u') ans = (ans * qaq[count]) % MOD;
			count = 0;
		}
		++count;
	}
	if (S[N] == 'n' || S[N] == 'u') ans = (ans * qaq[count]) % MOD;
	printf("%lld", ans);
	return 0;
}