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

LL f[34][2][2]; 
LL calc(LL n, LL m)
{
	if(n < 0 || m < 0) return 0;
	memset(f, 0, sizeof f);
	f[33][0][0] = 1;
	PER(i, 32, 0) rep(x, 0, 2) rep(y, 0, 2)
	{
		LL nx = x | ((n >> i) & 1), ny = y | ((m >> i) & 1);
		f[i][nx][ny] += f[i + 1][x][y];
		f[i][x][ny] += f[i + 1][x][y] * nx;
		f[i][nx][y] += f[i + 1][x][y] * ny;
	}
	return f[0][0][0] + f[0][0][1] + f[0][1][0] + f[0][1][1];
}

int main()
{
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		LL l, r;
		cin >> l >> r;
		cout << (calc(r, r) + calc(l - 1, l - 1) - calc(l - 1, r) * 2) << endl;
	}
	return 0;
}
