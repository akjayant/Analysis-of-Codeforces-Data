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
		int n, r, p, ss, cntR, cntP, cntS, ans;
		cin >> n >> r >> p >> ss;
		string s, op = "";
		cin >> s;
		cntR = cntP = cntS = ans = 0;
		rep(i, 0, n)
		{
			op += ' ';
			if(s[i] == 'R') cntR++;
			else if(s[i] == 'P') cntP++;
			else if(s[i] == 'S') cntS++;
		}
		ans += min(r, cntS);
		ans += min(p, cntR);
		ans += min(ss, cntP);
		if(ans >= (n + 1 >> 1)) 
		{
			puts("YES");
			rep(i, 0, n)
			{
				if(s[i] == 'R')
				{
					if(p) {p--; op[i] = 'P';}
				}
				if(s[i] == 'P')
				{
					if(ss) {ss--; op[i] = 'S';}
				}
				if(s[i] == 'S')
				{
					if(r) {r--; op[i] = 'R';}
				}
			}
			rep(i, 0, n)
			{
				if(op[i] == ' ')
				{
					if(p) op[i] = 'P', p--;
					else if(r) op[i] = 'R', r--;
					else if(ss) op[i] = 'S', ss--;
				}
			}
			cout << op << endl;
		}
		else puts("NO");
	}
	return 0;
}
