#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
const int N = 1e5 + 5;
const int P = 1e9 + 7;
char str[N];
int dp[N];
int n;

int main()
{
	scanf("%s", str + 1);
	n = strlen(str + 1);
	FOR(i, 1, n) if(str[i] == 'm' || str[i] == 'w')
	{
		puts("0");
		return 0;
	}
	dp[0] = dp[1]= 1;
	FOR(i, 2, n)
	{
		if(str[i] == str[i - 1] && (str[i] == 'u' || str[i] == 'n'))
			dp[i] = (dp[i - 1] + dp[i - 2]) % P;
		else dp[i] = dp[i - 1];
	}
	printf("%d\n", dp[n]);
	return 0;
}
