#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int x[N], y[N], par[N], c[N], k[N], sr[N];
bool mark[N];
vector<pair<long long, pair<int, int> > > e;
long long ans;
vector<pair<int, int> > ct;
vector<int> rtr;
int getPar(int v) {
	if (par[v] == v)
		return v;
	par[v] = getPar(par[v]);
	return par[v];
}
int main() {
	ios_base::sync_with_stdio (false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		cin >> c[i], ans += c[i], sr[i] = i, par[i] = i;
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			long long w = 1ll * (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
			e.push_back({w, {i, j}});
		}
	}
	sort(e.begin(), e.end());
//	for (int i = 0; i < e.size(); i++) {
//		cout << e[i].first << ", ";
//	}
//	cout << endl << endl;
	for (int i = 0; i < e.size(); i++) {
		long long w = e[i].first;
		int v = e[i].second.first, u = e[i].second.second;
		int pv = getPar(v), pu = getPar(u);
		if (pv == pu)
			continue;
		long long fr = c[sr[pv]], sd = c[sr[pu]];
		if (max(fr, sd) > w) {
			ans = ans - max(fr, sd) + w;
			ct.push_back({v, u});
			if (fr < sd) {
				par[pu] = pv;
				mark[sr[pu]] = 1;
			}
			else {
				par[pv] = pu;
				mark[sr[pv]] = 1;
			}
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < n; i++) {
		if (!mark[i])
			rtr.push_back(i);
	}
	cout << rtr.size() << "\n";
	for (int i = 0; i < rtr.size(); i++)
		cout << rtr[i] + 1 << " ";
	cout << "\n" << ct.size() << "\n";
	for (int i = 0; i < ct.size(); i++) {
		cout << ct[i].first + 1 << " " << ct[i].second + 1 << "\n";
	}
	return 0;
}	
