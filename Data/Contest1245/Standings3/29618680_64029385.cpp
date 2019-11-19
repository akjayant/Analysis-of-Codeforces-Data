#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <array>
#include <valarray>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <random>
#include <iterator>
#include <numeric>
#include <functional>
#include <queue>
#include <deque>
#include <stack>

std::vector<int> parent, rank;
int getSet(int at)
{
	if(parent[at] == at) return at;
	parent[at] = getSet(parent[at]);
	return parent[at];
}
void unionSets(int a, int b)
{
	a = getSet(a);
	b = getSet(b);
	if(a == b) return;
	if(rank[a] < rank[b]) std::swap(a, b);
	parent[b] = a;
	rank[a] += rank[b];
}
struct event
{
	int64_t cost;
	bool station;
	int a, b;
};
int main(/*int argc, char*argv[]*/)
{
	int n; std::cin >> n;
	parent.resize(n+1);
	for(int i = 0; i <= n; i++) parent[i] = i;
	std::vector<event> evs;
	rank.resize(n+1);
	evs.reserve(n*(n + 1) / 2);
	std::vector<std::pair<int,int>> coords(n);
	std::vector<int> costs(n);
	std::vector<int> coeffs(n);
	for(int i = 0; i < n; i++)
	{
		int x, y; std::cin >> x >> y;
		coords[i] = {x, y};
	}
	for(int i = 0; i < n; i++) std::cin >> costs[i], evs.push_back({costs[i], true, i, i});
	for(int i = 0; i < n; i++) std::cin >> coeffs[i];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			evs.push_back({int64_t(coeffs[i] + coeffs[j]) * int64_t(std::abs(coords[i].first - coords[j].first) + std::abs(coords[i].second - coords[j].second)), false, i, j});
		}
	std::sort(evs.begin(), evs.end(), [](event a, event b){return a.cost < b.cost;});
	int64_t ans = 0;
	std::vector<int> stations;
	std::vector<std::pair<int,int>> edges;
	for(int i = 0; i < evs.size(); i++)
	{
		event cur = evs[i];
		if(!cur.station)
		{
			if(getSet(cur.a) == getSet(cur.b)) continue;
			ans += cur.cost;
			edges.push_back({cur.a, cur.b});
			unionSets(cur.a, cur.b);
		}
		else
		{
			if(getSet(n) == getSet(cur.a)) continue; //already connected
			ans += cur.cost;
			stations.push_back(cur.a);
			unionSets(cur.a, n);
		}
	}
	std::cout << ans << '\n';
	std::cout << stations.size() << '\n';
	for(int el : stations) std::cout << el+1 << " ";
	std::cout << '\n' << edges.size() << '\n';
	for(auto[a, b] : edges) std::cout << a+1 << " " << b+1 << '\n';
	std::cout << '\n';
}
