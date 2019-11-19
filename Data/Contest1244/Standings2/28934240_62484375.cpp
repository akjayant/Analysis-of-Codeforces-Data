#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> neighbors;
vector<vector<ll>> c;
vector<int> colors;

void colorGraph(int parent, int startNode, int a, int b) {
	colors[startNode] = 6 - a - b;
	trav(next, neighbors[startNode]) {
		if (next != parent) {
			colorGraph(startNode, next, b, colors[startNode]);
		}
	}
}

ll getCost() {
	ll retvalue = 0;
	rep(i, 0, n) {
		retvalue += c[i][colors[i]-1];
	}
	return retvalue;
}

ll getTotCost(int startNode) {
	colors.resize(n);
	ll temp;
	int bestA = 1;
	int bestB = 2;

	colorGraph(-1, startNode, 1, 2);
	ll retvalue = getCost();

	colorGraph(-1, startNode, 1, 3);
	temp = getCost();
	if (temp < retvalue) {
		retvalue = temp;
		bestA = 1;
		bestB = 3;
	}

	colorGraph(-1, startNode, 2, 1);
	temp = getCost();
	if (temp < retvalue) {
		retvalue = temp;
		bestA = 2;
		bestB = 1;
	}

	colorGraph(-1, startNode, 2, 3);
	temp = getCost();
	if (temp < retvalue) {
		retvalue = temp;
		bestA = 2;
		bestB = 3;
	}

	colorGraph(-1, startNode, 3, 1);
	temp = getCost();
	if (temp < retvalue) {
		retvalue = temp;
		bestA = 3;
		bestB = 1;
	}

	colorGraph(-1, startNode, 3, 2);
	temp = getCost();
	if (temp < retvalue) {
		retvalue = temp;
		bestA = 3;
		bestB = 2;
	}

	colorGraph(-1, startNode, bestA, bestB);

	return retvalue;
}


int getALeaf(int parent, int startNode) {
	if (neighbors[startNode].size() == 1) {
		return startNode;
	}
	trav(next, neighbors[startNode]) {
		if (next != parent) {
			return getALeaf(startNode, next);
		}
	}
	// can't happen
	return -1;
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n;
	neighbors.resize(n);
	c.resize(n);
	rep(j, 0, 3) {
		rep(i, 0, n) {
			ll temp;
			cin >> temp;
			c[i].push_back(temp);
		}
	}
	rep(i, 0, n-1) {
		int u, v;
		cin >> u >> v;
		neighbors[u-1].push_back(v-1);
		neighbors[v-1].push_back(u-1);
	}

	rep(i, 0, n) {
		if (neighbors[i].size() > 2) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << getTotCost(getALeaf(-1,0)) << endl;
	rep(i, 0, n) {
		cout << colors[i] << " ";
	}
	cout << endl;
}
