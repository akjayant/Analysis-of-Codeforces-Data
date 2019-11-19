#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=int(b);++i)
using namespace std;
typedef long long ll;
const int maxn = 2010;
const int inf = 0x3f3f3f3f;
ll Co[maxn][maxn];
ll c[maxn], k[maxn];
ll x[maxn], y[maxn];
ll dp[maxn];
int use[maxn];
struct edge
{
	int f, t; ll v;
	bool operator<(const edge&ri)const
	{
		return v < ri.v;
	}
};
vector<edge>es;
vector<int>G[maxn];
int fa[maxn];
int ff(int x)
{
	return fa[x] == x ? x : fa[x] = ff(fa[x]);
}
int uni(int x, int y)
{
	x = ff(x), y = ff(y);
	if (x == y)return 0;
	fa[x] = y; return 1;
}

ll kru(int n)
{
	ll ans(0);
	F(i, 1, n)fa[i] = i;
	sort(es.begin(), es.end());
	int cnt(0);
	for (auto &e : es)
	{
		if (uni(e.f, e.t))
		{
			ans += e.v, ++cnt;
			G[e.f].push_back(e.t);
			G[e.t].push_back(e.f);
		}
		if (cnt == n - 1)break;
	}
	return ans;
}
vector<int>ans0, ans1;
void dfs(int u, int p,int d)
{
	if (d == 2)ans0.push_back(u);
	if (d >= 3)ans1.push_back(u), ans1.push_back(p);
	for (auto v : G[u])if (v != p)dfs(v, u, d + 1);
}
#define endl '\n'
int main()
{
#ifndef endl
	freopen("C:\\Users\\VULCAN\\Desktop\\data.in", "r", stdin);
	cout << "************************************Local Test*********************************" << endl;
#endif // !endl
	ios::sync_with_stdio(false);
	int T(1), cas(0);
	while (T--)
	{
		int n; cin >> n;
		F(i, 1, n)cin >> x[i] >> y[i];
		F(i, 1, n)cin >> c[i];F(i,1,n)cin>> k[i];
		F(i, 1, n)F(j, 1,i-1)
		{
			Co[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j]))*(k[i] + k[j]);
			es.push_back({ i,j,Co[i][j] });
		}
		F(i, 1, n)es.push_back({ n + 1,i,c[i] });
		
		cout << kru(n+1) << endl;
		dfs(n + 1, -1, 1);
		cout << ans0.size() << endl;
		F(i, 0, ans0.size() - 1)
		{
			if (i)cout << ' ';
			cout << ans0[i];
		}
		cout << endl;
		cout << n - ans0.size() << endl;
		for (int i = 0; i < ans1.size(); i += 2)
			cout << ans1[i] << ' ' << ans1[i + 1] << endl;
	}
	return 0;
}
//What to Debug
/*
-1.最好把全部warning都X掉,否则:https://vjudge.net/solution/19887176
0.看看自己是否有可能需要快读，禁endl
1.数组越界，爆int,浮点精度(查看精度是否达到题目要求,看有没有浮点数比较:eps)，取模操作，初始化数组，边缘数据,输出格式(cas),强制在线是否更新了las
2.通读代码，代码无逻辑错误
3.读题，找到题意理解失误或算法错误
4.放弃
*/