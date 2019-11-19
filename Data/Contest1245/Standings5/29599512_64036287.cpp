#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli, lli> ii;
typedef pair<lli, ii> iii;

struct City {
	lli x, y, c, k;
};

class UnionFind {
private:
  vi p, rank, setSize;
  vector<bool> powered;
  int numSets;
public:
  UnionFind(int N) {
  	powered.assign(N, false);
	setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
	p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {  
	if (!isSameSet(i, j)) { numSets--;  
	int x = findSet(i), y = findSet(j);
	if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; powered[x] = powered[x] || powered[y]; }
	else               	{ p[x] = y; setSize[y] += setSize[x]; powered[y] = powered[x] || powered[y];
                         	if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
  bool isPowered(int i) {
  	return powered[(findSet(i))];
  }
  void setPowered(int i) {
  	powered[i] = true;
  	powered[findSet(i)] = true;
  }
};


int main() {
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	lli n, stations;
	scanf(" %I64d", &n);
	vector<City> cities(n);
	for (lli i = 0; i < n; ++i) scanf(" %I64d %I64d", &cities[i].x, &cities[i].y);
	for (lli i = 0; i < n; ++i) scanf(" %I64d", &cities[i].c);
	for (lli i = 0; i < n; ++i) scanf(" %I64d", &cities[i].k);

	lli minCost = 0;
	for (lli i = 0; i < n; ++i)
	{
		pq.push({cities[i].c, {i, i}});
		for (lli j = i+1; j < n; ++j)
		{
			lli cost = (cities[i].k + cities[j].k) * (abs(cities[i].x - cities[j].x) + abs(cities[i].y - cities[j].y));
			pq.push({cost, {i, j}});
		}
	}
	vector<lli> powerStations;
	vector<ii> edges;
	UnionFind uf(n);
	while(!pq.empty()) {
		lli cost = pq.top().first, source = pq.top().second.first, dest = pq.top().second.second;
		if(source == dest) {
			if(!uf.isPowered(source)) {
				uf.setPowered(source);
				powerStations.push_back(source+1);
				minCost += cost;
			}
		} else {
			if(!uf.isSameSet(source, dest) && (!uf.isPowered(source) || !uf.isPowered(dest))) {
				uf.unionSet(source, dest);
				minCost += cost;
				edges.push_back({source+1, dest+1});
			}
		}
		pq.pop();
	}

	printf("%I64d\n", minCost);
	printf("%d\n", powerStations.size());
	for (int i = 0; i < powerStations.size(); ++i)
	{
		if(i > 0) printf(" ");
		printf("%I64d", powerStations[i]); 
	}
	printf("\n");
	printf("%d\n", edges.size());
	for (int i = 0; i < edges.size(); ++i)
	{
		printf("%I64d %I64d\n", edges[i].first, edges[i].second);
	}

	return 0;
}