#include <bits/stdc++.h>
using namespace std;
namespace fastIO
{
#define BUF_SIZE 100000
#define OUT_SIZE 100000
//fread->read
bool IOerror = 0;
inline char nc()
{
	static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
	if (p1 == pend)
	{
		p1 = buf;
		pend = buf + fread(buf, 1, BUF_SIZE, stdin);
		if (pend == p1)
		{
			IOerror = 1;
			return -1;
		}
	}
	return *p1++;
}
inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
template <class T>
inline bool read(T &x)
{
	bool sign = 0;
	char ch = nc();
	x = 0;
	for (; blank(ch); ch = nc())
		;
	if (IOerror)
		return false;
	if (ch == '-')
		sign = 1, ch = nc();
	for (; ch >= '0' && ch <= '9'; ch = nc())
		x = x * 10 + ch - '0';
	if (sign)
		x = -x;
	return true;
}
inline bool read(double &x)
{
	bool sign = 0;
	char ch = nc();
	x = 0;
	for (; blank(ch); ch = nc())
		;
	if (IOerror)
		return false;
	if (ch == '-')
		sign = 1, ch = nc();
	for (; ch >= '0' && ch <= '9'; ch = nc())
		x = x * 10 + ch - '0';
	if (ch == '.')
	{
		double tmp = 1;
		ch = nc();
		for (; ch >= '0' && ch <= '9'; ch = nc())
			tmp /= 10.0, x += tmp * (ch - '0');
	}
	if (sign)
		x = -x;
	return true;
}
inline bool read(char *s)
{
	char ch = nc();
	for (; blank(ch); ch = nc())
		;
	if (IOerror)
		return false;
	for (; !blank(ch) && !IOerror; ch = nc())
		*s++ = ch;
	*s = 0;
	return true;
}
inline bool read(char &c)
{
	for (c = nc(); blank(c); c = nc())
		;
	if (IOerror)
	{
		c = -1;
		return false;
	}
	return true;
}
template <class T, class... U>
bool read(T &h, U &... t) { return read(h) && read(t...); }
#undef OUT_SIZE
#undef BUF_SIZE
}; // namespace fastIO
using namespace fastIO;
typedef long long ll;
const int MAXN = 100005;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
int n;
ll c[MAXN][4];
vector<int> v[MAXN];
int p[3], ans[3];
ll temp;
ll pos;
int color[MAXN];
void dfs(int u, int fa)
{
	temp += c[u][p[(pos++ - 1) % 3]];
	for (auto w : v[u])
		if (w == fa)
			continue;
		else
			dfs(w, u);
}
void getcolor(int u, int fa)
{
	color[u] = ans[(pos++ - 1) % 3];
	for (auto w : v[u])
		if (w == fa)
			continue;
		else
			getcolor(w, u);
}
int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i)
		read(c[i][1]);
	for (int i = 1; i <= n; ++i)
		read(c[i][2]);
	for (int i = 1; i <= n; ++i)
		read(c[i][3]);
	int a, b;
	for (int i = 1; i < n; ++i)
	{
		read(a);
		read(b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i].size() > 2)
		{
			printf("-1\n");
			return 0;
		}
	}
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	int root;
	for (int i = 1; i <= n; ++i)
		if (v[i].size() == 1)
		{
			root = i;
			break;
		}
	ll ret = LLINF;
	do
	{
		temp = 0;
		pos = 1;
		dfs(root, 0);
		if (temp < ret)
		{
			ret = temp;
			ans[0] = p[0];
			ans[1] = p[1];
			ans[2] = p[2];
		}
	} while (next_permutation(p, p + 3));
	printf("%lld\n", ret);
	pos = 1;
	getcolor(root, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d ", color[i]);
	return 0;
}