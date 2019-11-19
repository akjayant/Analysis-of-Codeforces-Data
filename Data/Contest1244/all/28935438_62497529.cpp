#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100 * 1000 + 5;
const int C = 3;

using ll = long long;
ll n;
ll costs[C][N];
vector<ll> graph[N];
ll start;
vector<ll> order;

ll minCost = -1;
vector<ll> bestCols;

ll coloring[N];

void input() {
	cin >> n;
	for (int c = 0; c < C; c++) {
		for (int i = 1; i <= n; i++) {
			cin >> costs[c][i];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

bool isPath() {
	for (int i = 1; i <= n; i++) {
		if (graph[i].size() > 2) {
			return false;
		}
		else if (graph[i].size() == 1) {
			start = i;
		}
	}
	return true;
}

void computeOrder() {
	order.push_back(start);
	int prev = -1;
	while (order.size() < n) {
		int last = order.back();
		for (auto nei : graph[last]) {
			if (nei != prev) {
				order.push_back(nei);
				prev = last;
				break;
			}
		}
	}
}

void checkCost(vector<ll> cols) {
	ll curCost = 0;
	for (int i = 0; i < n; i++) {
		ll v = order[i];
		ll curCol = cols[i % C];
		curCost += costs[curCol][v];
	}

	if (minCost == -1 || curCost < minCost) {
		minCost = curCost;
		bestCols = cols;
	}
}

void findMin() {
	for (int c0 = 0; c0 < C; c0++) {
		for (int c1 = 0; c1 < C; c1++) {
			for (int c2 = 0; c2 < C; c2++) {
				if (c0 == c1 || c0 == c2 || c1 == c2) {
					continue;
				}
				checkCost({c0, c1, c2});
			}
		}
	}
}

void output() {
	cout << minCost << "\n";

	for (int i = 0; i < n; i++) {
		coloring[order[i]] = bestCols[i % C];
	}

	for (int i = 1; i <= n; i++) {
		cout << coloring[i] + 1 << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	if (not isPath()) {
		cout << -1 << "\n";
		return 0;
	}
	computeOrder();
	findMin();
	output();
	return 0;
}