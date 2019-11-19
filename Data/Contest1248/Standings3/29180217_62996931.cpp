#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ep(a) ((a)*10/9)
#define pb push_back
#define mp make_pair
#define inf (0x3f3f3f3f)
using namespace std;
typedef long long ll;
#ifdef DEBUG
#define do(x) x
#define dont(x) 
#else
#define do(x) 
#define dont(x) x 
#endif
namespace IO
{
	template<typename T>inline void putf(T x)
	{
		static char S[20], *end = S + 19;
		static const char lut[201] = 
			"00010203040506070809"
			"10111213141516171819"
			"20212223242526272829"
			"30313233343536373839"
			"40414243444546474849"
			"50515253545556575859"
			"60616263646566676869"
			"70717273747576777879"
			"80818283848586878889"
			"90919293949596979899";
		static const int M = 100000000;
#define output() i = (y % 100) << 1, y /= 100, *--ptr = lut[i + 1], *--ptr = lut[i]
		char *ptr = end;
		bool sign = true;
		unsigned y, i;
		if (x < 0)
			x = -x, sign = false;
		while (x >= M)
		{
			y = (unsigned) (x % M);
			x /= M;
			output(); output();
			output(); output(); 
		}
		y = (unsigned) x;
		while (y >= 100)
			output();
		if (y < 10)
			*--ptr = '0' + y;
		else
			output();
		if (!sign)
			*--ptr = '-';
		puts(ptr);
#undef output
	}
	template<typename T>inline void read(T &x)
	{
		x = 0;
		char c = getchar();
		bool sign = true;
		while (!isdigit(c))
		{
			if (c == '-')
				sign = false;
			c = getchar();
		}
		while (isdigit(c))
			x = x * 10 + (c & 0xf), c = getchar();
		if (!sign)
			x = -x;
	}
	template<typename T>inline void read(T &x, T &y) {read(x), read(y);}
	template<typename T>inline void read(T &x, T &y, T &z) {read(x), read(y), read(z);}
}
using namespace IO;
const int MOD = 1e9 + 7;
int dp[100005][2];
int main()
{

	int n, m;
	read(n, m);
	ll f = 0, g = 2;
	for (int i = 2; i <= m; ++i)
	{
		ll ff, gg;
		ff = g;
		gg = (f + g) % MOD;
		f = ff;
		g = gg;
	}
	dp[1][0] = 2;
	dp[2][0] = 2;
	dp[2][1] = 2;
	for (int i = 3; i <= n; ++i)
	{
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = ((ll)dp[i - 2][0] + dp[i - 1][1] + dp[i - 2][1]) % MOD;
	}
	putf(((ll)f + g + dp[n][1]) % MOD);
	
	return 0;
}