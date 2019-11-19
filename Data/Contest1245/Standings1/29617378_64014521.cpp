#include <bits/stdc++.h>
using namespace std;

constexpr const int maxn = 2000;
int x[maxn], y[maxn], c[maxn], k[maxn], vis[maxn], link[maxn];
pair<int, int> edge[maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i != n; ++i) cin >> c[i];
	for (int i = 0; i != n; ++i) cin >> k[i];
	vector<int> builds;
	vector<pair<int, int>> lines;
	while (true) {
		int best = -1, cost = INT_MAX;
		for (int i = 0; i != n; ++i) if (!vis[i] && c[i] < cost) best = i, cost = c[i];
		if (best == -1) break;
		vis[best] = 1;
		if (link[best]) lines.push_back(edge[best]);
		else builds.push_back(best + 1);
		for (int i = 0; i != n; ++i) if (!vis[i]) {
			long long temp = 1LL * (k[best] + k[i]) * (abs(x[best] - x[i]) + abs(y[best] - y[i]));
			if (temp < c[i]) {
				c[i] = temp;
				link[i] = 1;
				edge[i] = pair<int, int>(best + 1, i + 1);
			}
		}
	}
	cout << accumulate(c, c + n, 0LL) << "\n" << builds.size() << "\n" << builds[0];
	for (int i = 1; i != int(builds.size()); ++i) cout << " " << builds[i];
	cout << "\n" << lines.size() << "\n";
	for (const auto& line : lines) cout << line.first << " " << line.second << "\n";
}
