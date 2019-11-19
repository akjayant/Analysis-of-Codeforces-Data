#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <map>
#include <bitset>
#include <queue>
#include <functional>  
#include <numeric>      
#include <assert.h>

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef pair<pll, ll>plll;
typedef pair<int, ll>pil;



// be careful everything is 1 based
// always do getParents() after you finish adding edges
struct Tree {
	struct Edge {
		ll dest, weight;
		Edge(ll _dest = -1, ll _weight = 1) {
			dest = _dest;
			weight = _weight;
		}
	};
	int root;
	vector<vector<Edge>> adj;
	int n;
	vi parent;
	vll dist;
	ll INF = (ll)1e15;

	Tree(int _nodes = 0, int _root = 1) { // 1 based
		n = _nodes;
		adj.resize(n + 1);
		root = 1;
	}
	void addEdgeDirected(int u, int v, int w = 1) {
		adj[u].push_back(Edge(v, w));
	}
	void addEdgeUndirected(int u, int v, int w = 1) {
		adj[u].push_back(Edge(v, w));
		adj[v].push_back(Edge(u, w));
	}

	vi getSubtreeNodesCount() {
		// for each node how many nodes it has in its subtree
		vector<int> result(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			if (result[i] == -1) {
				getSubtreeNodesCountRec(-1, i, result);
			}
		}
		return result;
	}
	ll getDiameter() {
		// gets the weight of the diameter of the tree
		return getDiameterRec(-1, root).first;
	}
	void getParents() {
		parent = vi(n + 1, -1);
		stack<int> st;
		st.push(root);
		while (!st.empty()) {
			int cur = st.top();
			st.pop();
			for (auto it : adj[cur]) {
				if (it.dest == parent[cur])continue;
				parent[it.dest] = cur;
				st.push(it.dest);
			}
		}
	}
	void getDistArray() {
		dist = vll(n + 1, INF);
		dist[root] = 0;

		queue<int> q;
		q.push(root);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto it : adj[cur]) {
				if (it.dest == parent[cur]) continue;
				dist[it.dest] = dist[cur] + it.weight;
				q.push(it.dest);
			}
		}
	}

private:

	int getSubtreeNodesCountRec(int par, int cur, vi& subtreeNodesCount) {
		int mySize = 1;
		for (auto it : adj[cur]) {
			if (it.dest == par) continue;
			mySize += getSubtreeNodesCountRec(cur, it.dest, subtreeNodesCount);
		}
		return subtreeNodesCount[cur] = mySize;
	}
	pll getDiameterRec(int par, int cur) {
		ll diam = 0;
		ll maxHeight[3] = { 0, 0, 0 };
		for (auto it : adj[cur]) {
			if (it.dest == par) continue;
			pll subtreeDiam = getDiameterRec(cur, it.dest);
			diam = max(diam, subtreeDiam.first);

			maxHeight[0] = subtreeDiam.second + it.weight;
			sort(maxHeight, maxHeight + 3);
		}

		diam = max(diam, maxHeight[1] + maxHeight[2]);
		return { diam, maxHeight[2] };
	}
};

struct Graph {
	struct Edge {
		int id;
		int dest;
		ll weight;

		Edge(int _dest = -1, ll _weight = 1, int _id = 0) {
			dest = _dest;
			weight = _weight;
			id = _id;
		}

		bool operator<(const Edge& other) const {
			return dest < other.dest;
		}
	};

	int n;
	vector<vector<Edge>> adj;
	vll dist;
	ll INF = (ll)1e15;

	Graph(int nodes = 0) {
		n = nodes;
		adj.resize(n + 1);
	}

	void addEdgeUndirected(int u, int v, ll w = 1, int id = 0) {
		adj[u].push_back(Edge(v, w, id));
		adj[v].push_back(Edge(u, w, id));
	}

	void addEdgeDirected(int u, int v, ll w = 1) {
		adj[u].push_back(Edge(v, w));
	}

	void dijkstra(int src) {
		dist = vll(n + 1, INF);
		set<pll> st;
		dist[src] = 0;
		st.insert({ 0, src });

		while (st.size() > 0) {
			int curNode = st.begin()->second;
			ll curDist = st.begin()->first;
			st.erase(st.begin());

			if (dist[curNode] != curDist) continue;
			for (auto it : adj[curNode]) {
				ll temp = curDist + it.weight;
				if (temp < dist[it.dest]) {
					dist[it.dest] = temp;
					st.insert({ temp, it.dest });
				}
			}
		}
	}

	pair<Tree, ll> MST() {
		// returns Tree, Cost
		ll cost = 0;
		Tree mst(n + 1);
		vector<bool> done(n + 1, 0);
		priority_queue<pair<ll, pii> > q;
		q.push({ 0, {-1, 1} }); // minus cost, from, to
		while (!q.empty()) {
			int v = q.top().se.se, d = -q.top().fi, from = q.top().se.fi;

			q.pop();
			if (done[v]) continue;
			done[v] = 1;
			cost += d;
			if (from != -1)
				mst.addEdgeUndirected(from, v, d);
			for (auto it : adj[v]) {
				if (!done[it.dest]) {
					q.push({ -it.weight, {v, it.dest} });
				}
			}
		}
		return { mst, cost };
	}
};

ll getDist(pii a, pii b) {
	ll ans = (ll)abs(a.first - b.first) + (ll)abs(b.second - a.second);
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	
	vector<pii> cities(n + 1);
	vll c(n + 1), k(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cities[i].first >> cities[i].second;
	}

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}

	Graph g(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ll w = (k[i] + k[j]) * getDist(cities[i], cities[j]);
			g.addEdgeUndirected(i, j, w);
		}
	}

	for (int i = 1; i <= n; i++) {
		g.addEdgeUndirected(i, n + 1, c[i]);
	}

	auto ans = g.MST();

	cout << ans.second << "\n";
	ans.first.root = n + 1;

	ans.first.getParents();
	ll num1 = ans.first.adj[n + 1].size();
	cout << num1 << "\n";
	for (auto it : ans.first.adj[n + 1]) {
		cout << it.dest << " ";
	}
	cout << "\n";
	cout << n - num1 << "\n";
	for (int i = 1; i <= n; i++) {
		if (ans.first.parent[i] == n + 1) continue;
		else cout << ans.first.parent[i] << " " << i << "\n";
	}
}