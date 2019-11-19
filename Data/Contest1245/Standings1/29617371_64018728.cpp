#include <bits/stdc++.h>

using namespace std;

const int N = 2123;
const int M = N * N;

int n;

int x[N], y[N], c[N], k[N];
long long _distance[N][N];

void prepare() {
	
}

void read() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
	}	
}

struct edge {
	int a, b;
	long long c;
};

bool compare(edge a, edge b) {
	return a.c < b.c;
}

int parent[N];
int _rank[N];

void make_set (int v) {
	parent[v] = v;
	_rank[v] = 0;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
bool union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (_rank[a] < _rank[b])
			swap (a, b);
		parent[b] = a;
		if (_rank[a] == _rank[b])
			++_rank[a];
		return true;
	}
	return false;
}

void solve() {	
	for (int i = 0; i <= n; i++) {
		make_set(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			_distance[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		}
	}
	vector<edge> edges;
	for (int i = 1; i <= n; i++) {
		edge e;
		e.a = 0;
		e.b = i;
		e.c = c[i];
		edges.push_back(e);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edge e;
			e.a = i;
			e.b = j;
			e.c = (k[i] + k[j]) * _distance[i][j];
			edges.push_back(e);
		}
	}
	sort(edges.begin(), edges.end(), compare);
	long long answer = 0;
	int need = n;
	vector<int> to_build;
	vector<pair<int, int>> to_connect;
	for (int i = 0; i < (int) edges.size(); i++) {
		if (union_sets(edges[i].a, edges[i].b)) {
			answer += edges[i].c;
			need--;
			if (edges[i].a == 0) {
				to_build.push_back(edges[i].b);
			} else {
				to_connect.push_back(make_pair(edges[i].a, edges[i].b));
			}
			if (need == 0) {
				break;
			}
		}
	}
	printf("%lld\n", answer);
	printf("%d\n", (int) to_build.size());
	for (int i = 0; i < (int) to_build.size(); i++) {
		if (i) printf(" ");
		printf("%d", to_build[i]);
	}
	printf("\n");
	printf("%d\n", (int) to_connect.size());
	for (int i = 0; i < (int) to_connect.size(); i++) {
		if (i) printf("\n");
		printf("%d %d", to_connect[i].first, to_connect[i].second);
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	solve();
	
	return 0;
}



