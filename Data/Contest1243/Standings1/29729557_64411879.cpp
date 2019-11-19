#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 7;

set<int> st;
int n, m, u, v;
vector<int> vec[maxn], has;

void solve(int u) {
	st.erase(u);
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		u = q.front(); q.pop();
		for(int i = 0; i < (int)vec[u].size(); ++i) {
			int v = vec[u][i];
			if(!st.count(v)) continue;
			st.erase(v);
			has.push_back(v);
		}
		for(auto it:st) {
			q.push(it);
		}
		st.clear();
		for(auto x:has) st.insert(x);
		has.clear();
	}
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) st.insert(i);
    for(int i = 1; i <= m; ++i) {
    	scanf("%d%d", &u, &v);
    	vec[u].emplace_back(v);
    	vec[v].emplace_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
    	if(st.count(i)) solve(i), ++ans;
    }
    printf("%d\n", ans - 1);
    return 0;
}
