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
		int cnt[30] = {0}, cs[30] = {0}, ct[30] = {0};
		rep(i, 0, n)
		{
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
			cs[s[i] - 'a']++;
			ct[t[i] - 'a']++;
		}	
		int f = true;
		rep(i, 0, 26)
		{
			if(cnt[i] % 2) f = false;
		}
		if(!f)
		{
			cout << "NO\n";
			continue;
		}
		vector<pair<int, int> > ans;
		rep(i, 0, n)
		{
			if(s[i] != t[i])
			{
				int pt = 0;
				rep(j, i + 1, n)
				{
					if(t[j] == t[i])
					{
						pt = j;
						break;
					}
				}
				if(pt)
				{
					ans.push_back(make_pair(i, pt));
					swap(s[i], t[pt]);
					continue;
				}
				int ps = 0;
				rep(j, i + 1, n)
				{
					if(t[i] == s[j])
					{
						ps = j;
						break;
					}
				}
				if(ps)
				{
					ans.push_back(make_pair(ps, n - 1));
					swap(s[ps], t[n - 1]);
					ans.push_back(make_pair(i, n - 1));
					swap(s[i], t[n - 1]);
				}
			}
			
		}
		cout << "YES\n";
		cout << ans.size() << endl;
		rep(i, 0, ans.size())
		{
			cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl; 
		}
	}
	return 0;
}
