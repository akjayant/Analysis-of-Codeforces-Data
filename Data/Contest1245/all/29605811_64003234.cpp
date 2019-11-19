#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

#define pb push_back
#define mp make_pair

vector<int> p, rg;

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);

	if (a == b) return;

	if (rg[b] > rg[a]) swap(a, b);
	p[b] = a;
	if (rg[b] == rg[a]) rg[a]++;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> vc(n + 1);
	vector<int> k(n + 1);
	for (int i = 1; i <= n; ++i) cin >> vc[i].fs >> vc[i].sc;

	vector<pair<long long, pair<int, int>>> edges; 

	for (int i = 1; i <= n; ++i) {
		int w;
		cin >> w;
		edges.pb(mp(w, mp(0, i)));
		edges.pb(mp(w, mp(i, 0)));
	}

	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			int cost = k[i] + k[j];
			int dist = abs(vc[i].fs - vc[j].fs) + abs(vc[i].sc - vc[j].sc);

			long long w = 1LL * cost * dist;
			edges.pb(mp(w, mp(i, j)));
			edges.pb(mp(w, mp(j, i)));
		}

	sort(edges.begin(), edges.end());
	rg.assign(n + 1, 0);
	p.resize(n + 1);
	for (int i = 0; i <= n; ++i) p[i] = i;

	unsigned long long ans = 0;

	vector<int> build;
	vector<pair<int, int>> path;

	for (const auto &edge : edges) {
		long long w = edge.fs;
		int a = edge.sc.fs;
		int b = edge.sc.sc;

		if (get(a) == get(b)) continue;

		ans += w;
		unite(a, b);

		if (a == 0 || b == 0) build.pb(a + b);
		else {
			path.pb(mp(a, b));
		}
	}

	cout << ans << endl;
	cout << build.size() << endl;
	for (auto it : build) cout << it << " ";
	cout << endl;
	cout << path.size() << endl;
	for (auto it : path) cout << it.fs << " " << it.sc << endl;

	return 0;
}
