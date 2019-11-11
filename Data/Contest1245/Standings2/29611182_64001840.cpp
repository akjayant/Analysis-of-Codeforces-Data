#include <cstdio>

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
const int MAXN = 105;
int T, N, R, P, S, Rt, Pt, St, aim, ans; char str[MAXN], My[MAXN];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	#endif
	T = read();
	while (T--)
	{
		N = read(), R = read(), P = read(), S = read(); scanf("%s", str + 1); int i;
		Rt = Pt = St = 0;
		if (N & 1) aim = N / 2 + 1;
		else aim = N / 2;
		for (i = 1; i <= N; ++i)
		{
			if (str[i] == 'R') ++Rt;
			else if (str[i] == 'P') ++Pt;
			else ++St;
		}
		ans = min(P, Rt) + min(S, Pt) + min(R, St);
		if (ans >= aim)
		{
			puts("YES");
			for (i = 1; i <= N + 1; ++i) My[i] = '\0';
			for (i = 1; i <= N; ++i)
			{
				if (str[i] == 'R') { if (P) --P, My[i] = 'P'; }
				else if (str[i] == 'P') { if (S) --S, My[i] = 'S'; }
				else { if (R) --R, My[i] = 'R'; }
			}
			for (i = 1; i <= N; ++i)
			{
				if (My[i]) continue;
				if (R) --R, My[i] = 'R';
				else if (P) --P, My[i] = 'P';
				else if (S) --S, My[i] = 'S';
			}
			puts(My + 1);
		}
		else puts("NO");
	}
	return 0;
}