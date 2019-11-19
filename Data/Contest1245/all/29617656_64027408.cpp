/*
 * "Voce acha que esta um passo a minha frente, mas na verdade,
 * estou uma volta ao mundo menos um passo a frente de voce", ppA, Lo (Jan, 2018)
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2123;
ll n, x[N], y[N], c[N], k[N];

class uni {
public:
	int pai[N], size[N];
	int cps;

	uni() {
		memset(pai, -1, sizeof pai);
		for(int i = 0; i < N; i++)
			size[i] = 1;
	}

	uni(int n) {
		memset(pai, -1, sizeof pai);
		for(int i = 0; i < N; i++)
			size[i] = 1;
		cps = n;
	}

	int find (int u) {
		if (pai[u] == -1)
			return u;
		else 
			return pai[u] = find(pai[u]);
	}

	bool une (int u, int v) {
		u = find(u);	v = find(v);
		if (u == v) return false;

		if (size[u] < size[v])
			swap(u, v);

		pai[v] = u;
		size[u] += size[v];
		size[v] = 0;
		cps--;
		return true;
	}

	int comps () { return cps; }
};

vector <pair<ll, ii> > edg;
vector <ii> mst;

ll kruskal () {
	sort(edg.begin(), edg.end());
	ll ret = 0;
	uni U;

	for (int i = 0; i < (int)edg.size(); i++) {
		int u = edg[i].se.fi, v = edg[i].se.se;
		ll dist = edg[i].fi;
		if (U.une(u,v)) {
			mst.pb(mk(u,v));
			ret += dist;
		}
	}

	return ret;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> x[i] >> y[i];
  for(int i = 1; i <= n; i++)
    cin >> c[i];
  for(int i = 1; i <= n; i++)
    cin >> k[i];

  for(int i = 1; i <= n; i++)
    edg.eb(c[i] , ii(0,i));

  for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
      edg.eb((k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])) , ii(i,j));

  cout << kruskal() << endl;

  vector<int> a;
  vector<ii> b;
  for(auto it : mst) {
    if(it.fi == 0)
      a.pb(it.se);
    else
      b.eb(it.fi, it.se);
  }

  cout << a.size() << endl;
  for(auto it : a)
    cout << it << " ";
  cout << endl;

  cout << b.size() << endl;
  for(auto it : b)
    cout << it.fi << " " << it.se << endl;

  return 0;
}
