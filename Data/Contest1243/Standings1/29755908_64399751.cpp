#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, m, u, v, cnt, len;
bool vis[maxn];
queue<int> que;
unordered_set<int> st;
unordered_set<int> G[maxn];
unordered_set<int>::iterator it;
vector<unordered_set<int>::iterator> ers;

void Init() {
	for(int i = 1; i <= n; ++i) {
		st.insert(i);
	}
}

void bfs(int s) {
	vis[s] = true;
	st.erase(s);
	que.push(s);
	while(!que.empty()) {
		s = que.front();
		que.pop();
		ers.clear();
		for(it = st.begin(); it != st.end(); ++it) {
			if(G[s].find(*it) == G[s].end()) {
				vis[*it] = true;
				ers.push_back(it);
				que.push(*it);
			}
		}
		len = ers.size();
		for(int i = 0; i < len; ++i) {
			st.erase(ers[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	scanf("%d%d", &n, &m);
	Init();
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) {
			continue;
		}
		++cnt;
		bfs(i);
	}
	printf("%d\n", cnt - 1);

    return 0;
}