#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

vector<int> comps;
set<pair<int, int>> ones;
set<int> vleft;

bool iszero(int u, int v) {
	if (v < u) swap(u, v);
	return ones.count({ u, v }) == 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (b < a) swap(a, b);
		ones.insert({ a - 1, b - 1 });
	}
	for (int i = 0; i < n; i++) vleft.insert(i);

	comps = vector<int>(n, -1);
	int maxc = 0;
	
	for (int i = 0; i < n; i++) {
		if (comps[i] != -1) continue;
		maxc++;
		queue<int> Q;
		Q.push(i);
		while (Q.size() > 0) {
			int u = Q.front();
			Q.pop();

			for (auto it = vleft.begin(); it != vleft.end();) {
				int v = *it;
				if (iszero(u, v)) {
					it = vleft.erase(it);
					comps[v] = maxc;
					Q.push(v);
				} else it++;
			}
		}
	}
	
	cout << maxc - 1 << endl;

	return 0;
}
