#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
#define ull unsigned long long
int T, n;
vector<int> graph[100005];
int weight[100005][3];
int nxt[100005];
int num[100005];
int col[100005][6];
void dfs(int x, int dep = 0) {
	for(int i=0;i<graph[x].size();++i)
		if (num[graph[x][i]] == -1) {
			num[graph[x][i]] = dep;
			nxt[x] = graph[x][i];
			dfs(graph[x][i], dep + 1);
		}
}
ull calc(int a, int b, int x, int idx) {
	ull ans = 0;
	while (x != -1) {
		int c = (0 ^ 1 ^ 2 ^ a ^ b);
		col[x][idx] = c;
		a = b; b = c;
		ans += weight[x][c];
		x = nxt[x];
	}
	return ans;
}
int main() {
#ifdef _DEBUG
	freopen("stdin.txt", "r", stdin);
#endif
	cin >> n;
	for (int j = 0; j < 3; ++j)
		for (int i = 0; i < n; ++i)
			cin >> weight[i][j];
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int s = 0;
	bool flag = 0;
	for (int i = 0; i < n; ++i)
		if (graph[i].size() > 2 || graph[i].size() == 0) {
			cout << "-1" << endl;
			return 0;
		}
		else if (graph[i].size() == 1)
			s = i;
	memset(nxt, -1, sizeof(nxt));
	memset(num, -1, sizeof(num));
	num[s] = 0;
	dfs(s);
	int idx = 0;
	ull ans[6] = { 0 };
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if (i != j) {
				ans[idx] = calc(i, j, nxt[nxt[s]], idx) + weight[s][i] + weight[nxt[s]][j];
				col[s][idx] = i;
				col[nxt[s]][idx] = j;
				++idx;
			}
	idx = 0;
	for (int i = 1; i < 6; ++i)
		if (ans[i] < ans[idx])idx = i;
	cout << ans[idx] << endl;
	for (int i = 0; i < n; ++i)
		cout << col[i][idx] + 1 << ' ';
	cout << endl;
}