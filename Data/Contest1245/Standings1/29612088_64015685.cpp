/*
  This C++ Source Is
  Writen By syksykCCC
  (After July, 2019)
*/
#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i < y; i++)
#define REP(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i > y; i--)
#define PER(i, x, y) for(int i = x; i >= y; i--)
#define LLL __int128
#define int128 __int128
#define DEBUG(x) cerr << #x << " : " << x << endl
using namespace std;
typedef unsigned int uint;
typedef long long int64;
typedef long long LL;
typedef unsigned long long uint64;
typedef long long ULL;
typedef long double LLF;
template<typename T> inline void read(T &val)
{
	val = 0; char c = getchar(); int f = 1;
	while(!isdigit(c))
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		val = (val << 3) + (val << 1) + (c ^ 48);
		c = getchar();
	}
	val *= f;
}
template<typename T> void write_(T val)
{
	if(!val) return;
	write_(val / 10);
	putchar(val % 10 + 48);
}
template<typename T> inline void write(T val)
{
	if(val == 0) putchar(48);
	else if(val < 0)
	{
		putchar('-');
		write_(-val);
	}
	else write_(val);
}

const int N = 100005, MOD = 1e9 + 7;
LL fib[N], ans = 1;

int main()
{
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	fib[0] = 1; fib[1] = 1; fib[2] = 2;
	REP(i, 3, s.size())
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	int u = 0, n = 0;
	rep(i, 0, s.size())
	{
		if(s[i] == 'm' || s[i] == 'w') ans = 0;
		if(s[i] == 'u') u++;
		else 
		{
			ans = (ans * fib[u]) % MOD;
			u = 0;
		}
		if(s[i] == 'n') n++;
		else 
		{
			ans = (ans * fib[n]) % MOD;
			n = 0;
		}
	}
	ans = (ans * fib[u] % MOD * fib[n]) % MOD;
	cout << ans << endl;
	return 0;
}
