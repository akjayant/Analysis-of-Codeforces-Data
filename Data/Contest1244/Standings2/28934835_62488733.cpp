#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <random>
#include <climits>
#include <iomanip>
#include <queue>
#include <bitset>
#include <cctype>
#include <ostream>
#include <functional>
#include <complex>
#include <fstream>
#include <unordered_set>
#include <ctime>
#include <numeric>

using namespace std;

typedef long long li;

#define forn(i,n) for (li i = 0;i < li(n);i++)
#define ford(i,n) for (li i = li(n)-1;i >=0;i--)
#define fore(i,l,r) for (li i = li(l);i < li(r);i++)
#define correct(x,n) (((x) >= 0) && ((x) < n))
#define mp(a,b) make_pair((a),(b))
#define all(a) (a).begin(),(a).end()
#define rnd() (rand() + (RAND_MAX+1)*rand())
//#define DEBUG_

//#define x first
//#define y second
//#define x real()
//#define y imag()

typedef vector<li> vi;
typedef pair<li, li> pi;
typedef vector<pi> vpi;
typedef vector<vector<li>> vvi;
typedef long double ld;
typedef pair<li, li> Point;
//typedef complex<li> Point;
//typedef complex<ld> Point;

void fail()
{
	cout << -1 << endl;
	exit(0);
}

class Graph
{
public:
	vvi a;
	vvi cost;
	int n;
	vi cl;

	void addEdge()
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		a[l].push_back(r);
		a[r].push_back(l);
		if (a[l].size() > 2 || a[r].size() > 2)
			fail();
	}

	Graph()
	{
		cin >> n;
		a.assign(n, vi());
		cost.assign(n, vi(3, -1));
		cl.assign(n, -1);
		forn(j,3) forn(i, n)
			cin >> cost[i][j];
		forn(i, n - 1)
			addEdge();
	}

	li dfs(int v,int col,int d,int p = -1)
	{
		li res = cost[v][col];
		for (int to : a[v])
		{
			if (to == p)
				continue;
			res += dfs(to, (col + d + 3) % 3,d, v);
		}
		return res;
	}

	void dye(int v, int col, int d, int p = -1) 
	{
		cl[v] = col;
		for (int to : a[v])
		{
			if (to == p)
				continue;
			dye(to, (col + d + 3) % 3,d, v);
		}
	}

	void solve()
	{
		li mn = 1000000000000000000;
		int leaf;
		forn(i,n)
			if (a[i].size() == 1)
			{
				leaf = i;
				break;
			}
		int c, d;
		forn(i, 3)
		{
			li v = dfs(leaf, i, 1);
			if (mn > v)
			{
				mn = v;
				c = i;
				d = 1;
			}
			v = dfs(leaf, i, -1);
			if (mn > v)
			{
				mn = v;
				c = i;
				d = -1;
			}
		}
		cout << mn << endl;
		dye(leaf, c, d);
		forn(i, n)
			cout << cl[i] + 1 << " ";
	}
};

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Graph g;
	g.solve();
}