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
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int cnt = 0, p1 = 0, p2 = 0;
		rep(i, 0, n)
		{
			if(s[i] != t[i]) 
			{
				cnt++;
				if(!p1) p1 = i;
				else p2 = i;
			}
		}
		if(cnt > 2 || cnt == 1)
		{
			cout << "NO\n";
		}
		else if(cnt == 0)
		{
			cout << "YES\n";
		}
		else
		{
			if(s[p1] == s[p2] && t[p1] == t[p2])
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
