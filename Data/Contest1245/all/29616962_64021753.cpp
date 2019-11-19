#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;

typedef long long LL;
const int maxn = 4002000 + 100;
struct Node {
	LL x, y, k;
};

LL dis(const Node &a, const Node &b) {
	return (a.k + b.k) * (abs(a.x - b.x) + abs(a.y - b.y));
}

struct Edge {
	int u, v;
	LL dis;
	Edge() {}
	Edge(int uu, int vv) {
		u = uu;
		v = vv;
	}
};

bool operator<(const Edge &a, const Edge &b) {
	return a.dis < b.dis;
}

int n, cnt, c, len;
LL ans;
Node node[2000 + 10];
int fa[2000 + 100];
Edge edge[maxn];
vector<int> vct;
vector<Edge> e;

void Init() {
	ans = 0;
	cnt = 0;
	vct.clear();
	e.clear();
	for(int i = 0; i <= n; ++i) {
		fa[i] = i;
	}
}

int Find(int x) {
	return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void unit(int x, int y) {
	x = Find(x);
	y = Find(y);
	fa[x] = y;
}

int main() {
	ios::sync_with_stdio(false);

	while(cin >> n) {
		Init();
		for(int i = 1; i <= n; ++i) {
			cin >> node[i].x >> node[i].y;
		}
		for(int i = 1; i <= n; ++i) {
			cin >> c;
			edge[cnt].u = 0;
			edge[cnt].v = i;
			edge[cnt].dis = c;
			++cnt;
		}
		for(int i = 1; i <= n; ++i) {
			cin >> node[i].k;
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				edge[cnt].u = i;
				edge[cnt].v = j;
				edge[cnt].dis = dis(node[i], node[j]);
				++cnt;
			}
		}
		sort(edge, edge + cnt);
		for(int i = 0; i < cnt; ++i) {
			if(Find(edge[i].u) != Find(edge[i].v)) {
				ans += edge[i].dis;
				unit(edge[i].u, edge[i].v);
				if(edge[i].u == 0) {
					vct.push_back(edge[i].v);
				} else {
					e.push_back(edge[i]);
				}
			}
		}
		cout << ans << endl;
		cout << vct.size() << endl;
		len = vct.size();
		for(int i = 0; i < len; ++i) {
			if(i != 0) {
				cout << " ";
			}
			cout << vct[i];
		}
		cout << endl;
		len = e.size();
		cout << len << endl;
		for(int i = 0; i < len; ++i) {
			cout << e[i].u << " " << e[i].v << endl;
		}
	}

    return 0;
}