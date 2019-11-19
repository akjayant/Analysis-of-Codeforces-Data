#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<ll, ll> pll;
//typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const int maxN = 1e5 + 5;

int n, c[5][maxN];
int deg[maxN], down[maxN], used[maxN];
vi graph[maxN];
int cl[maxN], bestCl[maxN];

vector<vi> perms = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

void DFS(int root) {
	used[root] = true;
	for (auto x:graph[root]) {
		if (!used[x]) {
			down[root] = x;
			DFS(x);
		}
	}
}

ll color(int v, int cnt, int dir, const vi& perm) {
	if (v == 0) return 0;
	ll tmp = c[perm[cnt]][v];
	cl[v] = perm[cnt];
	cnt += dir;
	if (dir == -1 && cnt == -1) cnt = 2;
	if (dir == 1 && cnt == 3) cnt = 0;
	return tmp + color(down[v], cnt, dir, perm);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	RI(i, n) {
		cin >> c[1][i];
	}
	RI(i, n) {
		cin >> c[2][i];
	}
	RI(i, n) {
		cin >> c[3][i];
	}
	int root = -1;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		graph[a].pb(b);
		graph[b].pb(a);
		if (deg[a] > 2 || deg[b] > 2) {cout << "-1"; return 0;}
		if (deg[a] == 2) {
			root = a;
		}
		if (deg[b] == 2) {
			root = b;
		}
	}
	DFS(root);
	ll best = inf;
	for (auto perm: perms) {
		ll ans = c[perm[0]][root];
		cl[root] = perm[0];
		ans += c[perm[1]][graph[root][0]];
		cl[graph[root][0]] = perm[1];
		ans += c[perm[2]][graph[root][1]];
		cl[graph[root][1]] = perm[2];
		ans += color(down[graph[root][0]], 2, 1, perm);
		ans += color(down[graph[root][1]], 1, -1, perm);
		if (ans < best) {
			RI(i, n) {
				bestCl[i] = cl[i];
			}
			best = ans;
		}
	}
	cout << best << endl;
	RI(i, n) cout << bestCl[i] << " ";
	return 0;
}
