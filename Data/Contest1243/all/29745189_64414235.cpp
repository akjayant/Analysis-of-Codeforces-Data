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

const int N = 100005;
int n, m, pre[N], nxt[N], ans;
vector<int> G[N];
bool vis[N], vis_[N];

void del(int u)
{
	nxt[pre[u]] = nxt[u]; pre[nxt[u]] = pre[u];
	vis[u] = true;
}
void bfs(int u)
{
	ans++;
	queue<int> que;
	que.push(u);
	del(u);
	while(!que.empty())
	{
		int u = que.front(); que.pop();
		rep(i, 0, G[u].size())
		{
			if(!vis[G[u][i]]) vis_[G[u][i]] = true;
		}
		for(int i = nxt[0]; i; i = nxt[i])
		{
			if(!vis_[i])
			{
				que.push(i);
				del(i);
			}
		}
		rep(i, 0, G[u].size())
		{
			if(!vis[G[u][i]]) vis_[G[u][i]] = false;
		}
	}
}

int main()
{
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m;
	REP(i, 1, n) pre[i] = i - 1, nxt[i] = i + 1;
	nxt[n] = 0; nxt[0] = 1;
	REP(i, 1, m)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int u = 0;
	while(nxt[u])
	{
		vis[nxt[u]] = true;
		bfs(nxt[u]);
		u = 0;
	}
	cout << ans - 1 << endl;
	return 0;
}
