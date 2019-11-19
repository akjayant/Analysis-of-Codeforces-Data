#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long ll;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define print(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll N = 1e5 + 1;

struct edge
{
    int u, v, w;
    bool operator< (auto& x) {return w < x.w;}
};

vi parent, size;
int root (int v)
{
	if (parent[v] == v) return v;
	return parent[v] = root(parent[v]);
}

void merge (int a, int b)
{
	a = root(a);
	b = root(b);
	if (a != b)
	{
		if (size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	READ(n);
	int x[n + 1], y[n + 1];
	FOR (i, 1, n) cin >> x[i] >> y[i];
	
	READARR(c, n);
	READARR(k, n);
	
	parent.resize(n + 1);
	size.resize(n + 1, 1);
	FOR (i, 0, n) parent[i] = i;
	
	vector <edge> e;
	FOR (i, 1, n)
	    FOR (j, i + 1, n)
    	    e.pb({i, j, (k[i] + k[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j]))});
    
    FOR (i, 1, n) e.pb({0, i, c[i]});
    sort(e.begin(), e.end());
    
    int cost = 0;
    vi power;
    vpi con;
    for (auto x: e)
    {
        if (root(x.u) != root(x.v))
        {
            cost += x.w;
            if (x.u == 0) power.pb(x.v);
            else con.pb({x.u, x.v});
            merge(x.u, x.v);
        }
    }
    
    cout << cost << endl << power.size() << endl;
    for (int i: power) cout << i << " "; cout << endl;
    cout << con.size() << endl;
    for (pi i: con) cout << i.fi << " " << i.se << endl;
}