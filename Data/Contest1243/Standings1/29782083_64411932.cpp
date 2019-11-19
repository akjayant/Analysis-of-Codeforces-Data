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
#include <list>

std::vector<std::set<int>> graph;
std::vector<int> parent, size;
int findSet(int at)
{
	if(parent[at] == at) return at;
	return parent[at] = findSet(parent[at]);
}
void unionSets(int a, int b)
{
	a = findSet(a);
	b = findSet(b);
	if(a == b) return;
	if(size[a] < size[b]) std::swap(a, b);
	parent[b] = a;
	size[a] += size[b];
}
int main(/*int argc, char*argv[]*/)
{
	int n, m; std::cin >> n >> m;
	graph.resize(n);
	parent.resize(n);
	size.resize(n, 1);
	for(int i = 0; i < m; i++)
	{
		int a, b; std::cin >> a >> b;
		a--; b--;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	//extra bad implementation of kruskal's algorithm?
	std::vector<int> vec(n);
	//std::set<int> nz;
	std::map<int, int> nz;
	for(int i = 0; i < n; i++) vec[i] = i, parent[i] = i, nz[i] = 3;
	std::sort(vec.begin(), vec.end(), [&](int a, int b) { return graph[a].size() != graph[b].size() ? graph[a].size() < graph[b].size() : (12345 ^ a) < (12345 ^ b); });
	for(int _i = 0; _i < n; _i++)
	{
		int i = vec[_i]; //the ACTUAL i
		for(auto it = nz.begin(); it != nz.end();)
		{
			bool del = false;
			if(graph[i].find(it->first) == graph[i].end())
			{
				//printf("union: %d and %d\n", i, it->first);
				unionSets(i, it->first);
				nz[it->first]--;
				if(nz[it->first] == 0) del = true;
			}
			if(del) it = nz.erase(it);
			else it++;
		}
	}
	for(int i = 0; i < n; i++) findSet(i);
	std::set<int> uniq; //originally this part of the code cruelly dismembered the DSU by sorting parent
	for(int el : parent) uniq.insert(el);
	std::cout << (uniq.size() - 1) << '\n';
}
