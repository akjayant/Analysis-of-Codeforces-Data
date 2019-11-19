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
#include <unordered_map>
#include <ctime>
#include <deque>
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

#define x first
#define y second
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

class DSU
{
public:
	vi p, r;

	DSU(int n):p(n),r(n,0)
	{
		forn(i, n)
			p[i] = i;
	}

	int find(int v)
	{
		return p[v] = (p[v] == v ? v : find(p[v]));
	}

	bool con(int v, int u)
	{
		int x = find(v);
		int y = find(u);
		return x == y;
	}

	void unite(int v,int u)
	{
		int x = find(v);
		int y = find(u);
		if (x == y)
			return;
		if (r[x] > r[y])
		{
			p[y] = x;
			return;
		}
		p[x] = y;
		if (r[x] == r[y])
			r[y]++;
	}
};

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	DSU dsu(n + 1);

	vpi crd(n);
	forn(i, n)
		cin >> crd[i].first >> crd[i].second;

	vector<tuple<li, li, li>> edges;
	forn(i, n)
	{
		li c;
		cin >> c;
		edges.emplace_back(c, i, n);
	}
	vi cost(n);
	forn(i, n)
		cin >> cost[i];

	forn(i, n) forn(j, i)
	{
		li price = (cost[i] + cost[j]);
		price *= (abs(crd[i].x - crd[j].x) + abs(crd[i].y - crd[j].y));
		edges.emplace_back(price, i, j);
	}
	sort(all(edges));
	
	vi ans;
	vpi ans1;
	li res = 0;
	int k = n;
	for (auto edge : edges)
	{
		li l, r, cost;
		tie(cost, l, r) = edge;
		if (dsu.con(l, r))
			continue;
		k--;
		res += cost;
		dsu.unite(l, r);
		if (r == n)
			ans.push_back(l + 1);
		else
			ans1.emplace_back(l + 1, r + 1);
		if (!k)
			break;
	}
	cout << res << endl;
	cout << ans.size() << endl;
	for (li v : ans)
		cout << v << " ";
	cout << endl;
	cout << ans1.size() << endl;
	for (pi edge : ans1)
		cout << edge.x << " " << edge.y << endl;
}