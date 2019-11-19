#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define nmax_def 110000
#define Cmax_def 2200
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define graph_from1 true
#define graph_tree true
#define graph_weight false
#define graph_digraph false

class Graph_func
{
public:
	int Vnum;
	int Enum;
	vector<pair<int, int> > edgelist;
	vector<ll> edgeweight;
	vector<vector<int> > adjlist;
	vector<vector<ll> > adjlistweight;
	vector<int> adjnum;
	vector<vl> vertex_costs;

	vector<ll> xdist;

	vector<bool> x_visited;
	vector<int> x_prqarr;
	vector<bool> x_filled;

	void read_edge();
	void adjini();
	void visited_ini();
	void adjsort();
	vector<bool> graph_num_BFS(int BFS_ini, vector<bool> filled);
	int graph_num();
	void graph_BFS(ll BFS_ini);
	void graph_DFS(ll DFS_ini);
	void xydist_fill(int x, ll dist_tmp);
	void xydist_tree(int x, ll dist_tmp);   // ex. xydist_tree(3, 0)
	void xydist(int x);   // ex. xydist(3, 0)
	ll diameter();
	int leaf();

	bool xydist_def = false;
	bool can = true;
	vl colorlist;

};

void Graph_func::read_edge()
{
	cin >> Vnum;
	if (graph_tree)
		Enum = Vnum - 1;// graph
	else
		cin >> Enum;
	edgelist.resize(Enum);
	edgeweight.resize(Enum);
	adjnum.resize(Vnum);
	xdist.resize(Vnum);
	adjlist.resize(Vnum);
	if (graph_weight)
		adjlistweight.resize(Vnum);
	colorlist.resize(Vnum);
	rep(i, 3) {
		vl ctmp;
		rep(j, Vnum) {
			ll c;
			cin >> c;
			ctmp.push_back(c);
		}
		vertex_costs.push_back(ctmp);
	}
	for (int i = 0; i < Enum; i++)
	{
		if (graph_weight)
			cin >> edgelist[i].first >> edgelist[i].second >> edgeweight[i];
		else
			cin >> edgelist[i].first >> edgelist[i].second;
		if (graph_from1)
		{
			edgelist[i].first--;
			edgelist[i].second--;
		}
	}
	return;
}

void Graph_func::adjini()
{
	for (int i = 0; i < Vnum; i++)
		adjnum[i] = 0;
	for (int i = 0; i < Enum; i++)
	{
		int x = edgelist[i].first;
		int y = edgelist[i].second;
		adjlist[x].push_back(y);
		if (!graph_digraph)
			adjlist[y].push_back(x);
		if (graph_weight)
		{
			ll xyweight = edgeweight[i];
			adjlistweight[x].push_back(xyweight);
			if (!graph_digraph)
				adjlistweight[y].push_back(xyweight);
		}
		adjnum[x]++;
		if (!graph_digraph)
			adjnum[y]++;
	}
	x_visited.resize(Vnum);
	for (int i = 0; i < Vnum; i++)
		x_visited[i] = false;

	return;
}

void Graph_func::visited_ini()
{
	for (int i = 0; i < Vnum; i++)
		x_visited[i] = false;
}

void Graph_func::adjsort()
{
	for (int i = 0; i < Vnum; i++)
		sort(adjlist[i].begin(), adjlist[i].end(), less<int>());
	return;
}

vector<bool> Graph_func::graph_num_BFS(int BFS_ini, vector<bool> filled) // ex. graph_num_BFS(i, filled);
{
	x_prqarr.push_back(BFS_ini);
	x_visited[BFS_ini] = true;

	while (!x_prqarr.empty())
	{
		int Ntmp = x_prqarr.size();
		for (int a = 0; a < Ntmp; a++)
		{
			int x = x_prqarr[0];
			x_prqarr.erase(x_prqarr.begin());
			for (int i = 0; i < adjnum[x]; i++)
			{
				int x_new = adjlist[x][i];
				if (!x_visited[x_new])
				{
					x_prqarr.push_back(x_new);
					x_visited[x_new] = true;
					filled[x_new] = true;
				}
			}
		}
	}
	return filled;
}

int Graph_func::graph_num()
{
	int anstmp = 0;
	int i = 0;
	vector<bool> filled;
	filled.resize(Vnum);
	for (int j = 0; j < Vnum; j++)
		filled[j] = false;
	bool end = false;
	while (!end)
	{
		if (i >= Vnum)
			break;
		while (1)
		{
			if (!filled[i])
				break;
			i++;
			if (i >= Vnum)
			{
				end = true;
				break;
			}
		}
		if (end)
			break;
		filled[i] = true;
		filled = graph_num_BFS(i, filled);
		anstmp++;
	}
	return anstmp;
}

void Graph_func::graph_BFS(ll BFS_ini)
{
	x_prqarr.push_back(BFS_ini);
	x_visited[BFS_ini] = true;
	int count = 0;

	while (!x_prqarr.empty())
	{
		int Ntmp = x_prqarr.size();
		for (int a = 0; a < Ntmp; a++)
		{
			int x = x_prqarr[0];
			colorlist[x] = count % 3;
			count++;
			x_prqarr.erase(x_prqarr.begin());
			for (int i = 0; i < adjnum[x]; i++)
			{
				int x_new = adjlist[x][i];
				if (!x_visited[x_new])
				{
					x_prqarr.push_back(x_new);
					x_visited[x_new] = true;
				}
			}
		}
	}
	return;
}

void Graph_func::graph_DFS(ll DFS_ini)
{
	x_prqarr.push_back(DFS_ini);
	x_visited[DFS_ini] = true;
	xdist[DFS_ini] = 0;

	while (!x_prqarr.empty())
	{
		int Ntmp = x_prqarr.size();
		for (int a = 0; a < Ntmp; a++)
		{
			int x = x_prqarr[x_prqarr.size() - 1];
			x_prqarr.pop_back();
			for (int i = 0; i < adjnum[x]; i++)
			{
				int x_new = adjlist[x][i];
				if (!x_visited[x_new])
				{
					xdist[x_new] = xdist[x] + 1;
					x_prqarr.push_back(x_new);
					x_visited[x_new] = true;
				}
			}
		}
	}
	return;
}

void Graph_func::xydist_fill(int x, ll dist_tmp)
{
	xdist[x] = dist_tmp;
	x_visited[x] = true;
}

void Graph_func::xydist_tree(int x, ll dist_tmp)  // ex. xydist_tree(3, 0), DFS
{
	if (!xydist_def)
	{
		xydist_def = true;
		xydist_fill(x, 0);
	}
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (!x_visited[x_new])
		{
			xydist_fill(x_new, dist_tmp + 1);
			xydist_tree(x_new, dist_tmp + 1);
		}
	}
	return;
}

void Graph_func::xydist(int x)  // ex. xydist(3), Dijkstra's algorithm
{
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > xdist_que; //Alive_vertices
	ll max_tmp = pow(10, 18) * 4;
	for (int i = 0; i < Vnum; i++)
		xdist[i] = max_tmp;
	xdist[x] = 0;
	pair<ll, int> xdist_que_tmp;
	xdist_que_tmp.first = 0;
	xdist_que_tmp.second = x;
	xdist_que.push(xdist_que_tmp);
	while (!xdist_que.empty())
	{
		xdist_que_tmp = xdist_que.top();
		xdist_que.pop();
		ll xdist_tmp = xdist_que_tmp.first;
		int x_tmp = xdist_que_tmp.second;
		if (xdist[x_tmp] == xdist_tmp)
		{
			for (int i = 0; i < adjnum[x_tmp]; i++)
			{
				int x_new = adjlist[x_tmp][i];
				ll dist_diff;
				if (graph_weight)
					dist_diff = adjlistweight[x_tmp][i];
				else dist_diff = 1;
				if (xdist[x_new] > xdist[x_tmp] + dist_diff)
				{
					xdist[x_new] = xdist[x_tmp] + dist_diff;
					xdist_que_tmp.first = xdist[x_new];
					xdist_que_tmp.second = x_new;
					xdist_que.push(xdist_que_tmp);
				}
			}
		}
	}
}

ll Graph_func::diameter()
{
	ll anstmp = 0, anstmp_i = 0;
	pair<int, int> longest;
	xydist_tree(0, 0);
	for (int i = 0; i < Vnum; i++)
	{
		if (xdist[i] > anstmp)
		{
			anstmp = xdist[i];
			anstmp_i = i;
		}
	}
	longest.first = anstmp_i;
	anstmp = 0, anstmp_i = 0;
	visited_ini();
	xydist_tree(longest.first, 0);
	for (int i = 0; i < Vnum; i++)
	{
		if (xdist[i] > anstmp)
		{
			anstmp = xdist[i];
			anstmp_i = i;
		}
	}
	longest.second = anstmp_i;
	return anstmp;
}

int Graph_func::leaf() // included adjini()
{
	int anstmp = 0;
	for (int i = 0; i < Vnum; i++)
		adjnum[i] = 0;
	for (int i = 0; i < Enum; i++)
	{
		int x = edgelist[i].first;
		int y = edgelist[i].second;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
		adjnum[x]++;
		adjnum[y]++;
	}
	for (int i = 0; i < Vnum; i++)
	{
		if (adjnum[i] > 2)
			can = 0;
	}
	for (int i = 0; i < Vnum; i++)
	{
		if (adjnum[i] == 1)
			return i;
	}
}

int main(void)
{
	Graph_func graph;
	ll ans;
	graph.read_edge();
	graph.adjini();
	ll Vnum = graph.Vnum;
	ll Enum = graph.Enum;
	ll leaf = graph.leaf();
	graph.graph_BFS(leaf);
	ans = pow(10, 18);
	vi anslist;
	rep(i, 6) {
		ll anstmp = 0;
		vi new_color;
		new_color.resize(3);
		switch (i)
		{
		case 0:
			new_color[0] = 0;
			new_color[1] = 1;
			new_color[2] = 2;
			break;
		case 1:
			new_color[0] = 0;
			new_color[1] = 2;
			new_color[2] = 1;
			break;
		case 2:
			new_color[0] = 1;
			new_color[1] = 0;
			new_color[2] = 2;
			break;
		case 3:
			new_color[0] = 1;
			new_color[1] = 2;
			new_color[2] = 0;
			break;
		case 4:
			new_color[0] = 2;
			new_color[1] = 0;
			new_color[2] = 1;
			break;
		case 5:
			new_color[0] = 2;
			new_color[1] = 1;
			new_color[2] = 0;
			break;
		}
		rep(x, Vnum) {
			int colortmp = (new_color[graph.colorlist[x]])%3;
			anstmp += graph.vertex_costs[colortmp][x];
		}
		if (ans > anstmp) {
			ans = anstmp;
			anslist = new_color;
		}
	}
	if (!graph.can)
		cout << "-1" << endl;
	else {
		cout << ans << endl;
		rep(x, Vnum) {
			cout << (anslist[graph.colorlist[x]] + 1) << " ";
		}
		cout << endl;
	}
	return 0;
}