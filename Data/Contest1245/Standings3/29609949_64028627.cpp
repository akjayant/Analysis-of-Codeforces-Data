#include <bits/stdc++.h>
using namespace std;
pair<int,int> t[1000111], c[1000111];
long long k[1000111];
pair<long long, int> cheapest[1000111];
int f[1000111];
int findUsed[1000111];
vector<pair<int,int>> connections;
vector<int> stations;
vector<int> electrized;
vector<pair<long long, pair<int,int>>> available_connections;
long long cost(int i, int j) {
	long long weight = k[i] + k[j];
	long long distance = abs(t[i].first - t[j].first) + abs(t[i].second - t[j].second);
	return weight*distance;
}

int find(int w) {
	if (f[w] == w) return w;
	f[w] = find(f[w]);
	return f[w];
}
void UNION(int a, int b) {
	a = find(a);
	b = find(b);
	auto cheap = min(cheapest[a], cheapest[b]);
	cheapest[a] = cheap;
	f[b] = a;
}
int main()
{
	int n;
	long long spent = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		t[i] = make_pair(a,b);
	}
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		c[i] = make_pair(a,i);
	}
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		k[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		f[i] = i;
		cheapest[i] = make_pair(c[i].first, c[i].second);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			available_connections.push_back(make_pair(cost(i,j), make_pair(i,j)));
			// if (find(i) != find(j)) {
			// 	if (cost(i,j) < max(cheapest[find(i)], cheapest[find(j)])) union(i,j);
			// }
		}
	}
	sort(available_connections.begin(), available_connections.end());
	int len = available_connections.size();
	for (int i = 0; i < len; i++) {
		long long cost = available_connections[i].first;
		int a = available_connections[i].second.first;
		int b = available_connections[i].second.second;
		if (find(a) == find(b)) continue;
		if (cost < max(cheapest[find(a)].first, cheapest[find(b)].first)) {
			UNION(a,b);
			spent += cost;
			connections.push_back(make_pair(a,b));
		}
	}

	//set stations
	for (int i = 1; i<= n; i++) {
		int father = find(i);
		if (findUsed[father] == 1) continue;
		findUsed[father] = 1;
		spent += cheapest[father].first;
		stations.push_back(cheapest[father].second);
	}
	

	printf("%lld\n", spent);
	printf("%d\n", (int)stations.size());
	for (auto i : stations) {
		printf("%d ", i);
	}
	if (stations.size() > 0) printf("\n");
	printf("%d\n", (int)connections.size());
	for (int i = 0; i < connections.size(); i++) {
		printf("%d %d\n", connections[i].first, connections[i].second);
	}

	return 0;
}