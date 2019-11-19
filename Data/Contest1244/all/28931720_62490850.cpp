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

int valid = 2;
std::vector<int> marks;
std::vector<std::vector<int>> graph;
void dfs(int at, int c = 1)
{
	marks[at] = c;
	int calls = 0;
	for(int to : graph[at])
	{
		calls++;
		if(marks[to]) continue;
		dfs(to, 1 + (c % 3));
	}
	if(calls == 2) return; 
	if(calls == 1) valid--; //valid should be 0 in the very end to be valid
}
int main(/*int64_t argc, char*argv[]*/)
{
	int n; std::cin >> n;
	marks.resize(n);
	graph.resize(n);
	//tree is a chain
	std::vector<int> c1(n);
	std::vector<int> c2(n);
	std::vector<int> c3(n);
	for(int i = 0; i < n; i++) scanf("%d", &c1[i]);
	for(int i = 0; i < n; i++) scanf("%d", &c2[i]);
	for(int i = 0; i < n; i++) scanf("%d", &c3[i]);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b; std::cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
		if(graph[i].size() == 1)
		{
			dfs(i, 1);
			break;
		}
	if(valid) { std::cout << -1; return 0; }
	int64_t sc11 = 0, sc12 = 0, sc13 = 0, sc21 = 0, sc22 = 0, sc23 = 0, sc31 = 0, sc32 = 0, sc33 = 0;
	for(int i = 0; i < n; i++)
	{
		if(marks[i] == 1)
			sc11 += c1[i],
			sc12 += c2[i],
			sc13 += c3[i];
		if(marks[i] == 2)
			sc21 += c1[i],
			sc22 += c2[i],
			sc23 += c3[i];
		if(marks[i] == 3)
			sc31 += c1[i],
			sc32 += c2[i],
			sc33 += c3[i];
		//printf("sc11=%d, sc12=%d, sc13=%d, sc21=%d, sc22=%d, sc23=%d, sc31=%d, sc32=%d, sc33=%d\n", sc11, sc12, sc13, sc21, sc22, sc23, sc31, sc32, sc33);
	}
	int bo = -1;
	int64_t max = LLONG_MAX;
	if(max > sc11 + sc22 + sc33) max = sc11 + sc22 + sc33, bo = 0; //thx vim for block copy&paste
	if(max > sc11 + sc23 + sc32) max = sc11 + sc23 + sc32, bo = 1;
	if(max > sc12 + sc21 + sc33) max = sc12 + sc21 + sc33, bo = 2;
	if(max > sc12 + sc23 + sc31) max = sc12 + sc23 + sc31, bo = 3;
	if(max > sc13 + sc21 + sc32) max = sc13 + sc21 + sc32, bo = 4;
	if(max > sc13 + sc22 + sc31) max = sc13 + sc22 + sc31, bo = 5;
	std::cout << max << '\n';
	for(int i = 0; i < n; i++)
	{
		int cur = marks[i];
		//printf("cc=%d, bo=%d\n", cur, bo);
		if(bo == 0)
			std::cout << (cur==1?1:cur==2?2:3);
		if(bo == 1)
			std::cout << (cur==1?1:cur==2?3:2);
		if(bo == 2)
			std::cout << (cur==1?2:cur==2?1:3);
		if(bo == 3)
			std::cout << (cur==1?2:cur==2?3:1);
		if(bo == 4)
			std::cout << (cur==1?3:cur==2?1:2);
		if(bo == 5)
			std::cout << (cur==1?3:cur==2?2:1);
		std::cout << " ";
	}
}
