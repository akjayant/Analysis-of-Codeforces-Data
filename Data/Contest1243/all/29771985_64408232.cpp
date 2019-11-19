#include <bits/stdc++.h>

using namespace std;

const int N = 100123;

int n, m;
vector<int> edge[N];

int from[N];

void prepare() {
	
}

void read() {
	
}

vector<int> intersect(vector<int> &a, vector<int> &b) {
	vector<int> result;
	if (a.size() < b.size()) {
		for (int x : a) {
			auto iter = lower_bound(b.begin(), b.end(), x);
			if (iter != b.end() && (*iter) == x) {
				result.push_back(x);
			}
		}
	}	else {
		for (int x : b) {
			auto iter = lower_bound(a.begin(), a.end(), x);
			if (iter != a.end() && (*iter) == x) {
				result.push_back(x);
			}
		}
	}
	return result;
}

//combine(i, from[edge_to], edges[i], edges[from[edge_to]], comps[i], comps[from[edge_to]]);

void combine(int id_1, int id_2, vector<int> &edges_1, vector<int> &edges_2, vector<int> &comp_1, vector<int> &comp_2) {
	if (comp_1.size() > comp_2.size()) {
		comp_1.insert(comp_1.end(), comp_2.begin(), comp_2.end());
		for (int x : comp_2) {
			from[x] = id_1;
		}
		edges_1 = intersect(edges_1, edges_2);
	} else {
		comp_2.insert(comp_2.end(), comp_1.begin(), comp_1.end());
		for (int x : comp_1) {
			from[x] = id_2;
		}
		edges_2 = intersect(edges_1, edges_2);
	}
}

bool one_comp() {
	for (int i = 0; i < n; i++) {
		if (from[i] != from[0]) {
			return false;
		}
	}
	return true;
}

#define LOG(...) fprintf(stderr, __VA_ARGS__)

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}	
	for (int i = 0; i < n; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	
	vector<vector<int>> comps;
	vector<int> seen(n, 0);
	vector<vector<int>> edges(n, vector<int>());
	for (int i = 0; i < n; i++) {
		from[i] = i;
		vector<int> comp;
		comp.push_back(i);
		comps.push_back(comp);
		edges[i] = edge[i];
	}
	int answer = 0;
	while ( !one_comp() ) {
		/*
		for (int i = 0; i < n; i++) {
			LOG("c(%d)\n", i);
			for (int x : comps[i]) {
				
			}
		}
		*/
		seen.assign(n, 0);
		for (int i = 0; i < (int) comps.size(); i++) {
			if (seen[i]) continue;
			if (from[comps[i][0]] != i) continue;		
			int ptr = -1;
			int edge_to = -1;
			for (int j = 0; j < n; j++) {
				if (from[j] == i) continue;
				while (ptr + 1 < (int) edges[i].size() && edges[i][ptr + 1] <= j) {
					ptr++;
				}
				if (ptr == -1 || edges[i][ptr] != j) {
					edge_to = j;
					break;
				}
			}
			if (edge_to == -1) {
				edge_to = edges[i][0];
				answer++;
			}
			seen[from[edge_to]] = 1;
			combine(i, from[edge_to], edges[i], edges[from[edge_to]], comps[i], comps[from[edge_to]]);
		}
	}
	printf("%d\n", answer);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	solve();
	
	return 0;
}


 