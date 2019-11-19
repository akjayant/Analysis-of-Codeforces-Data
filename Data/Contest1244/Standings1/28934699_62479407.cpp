#include<algorithm>
#include <cstdio>
#include <string>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
#include<map>
#include<iostream>
#include<functional>
#include<cstring>
#include<stack>

using namespace std;
void fastio() {
	iostream::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}

long long cost[111111][3];
vector<int> v[111111];
long long color[111111];
int nxt[111111];
int main() {
	fastio();
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[j][i];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].size() >= 3) {
			cout << -1;
			return 0;
		}
	}
	int start;
	for (start = 1; start <= n; start++) {
		if (v[start].size() == 1)break;
	}
	nxt[start] = v[start][0];
	
	int bf = start;
	int cur = nxt[start];

	while (v[cur].size() > 1) {
		for (int x : v[cur]) {
			if (bf == x)continue;
			nxt[cur] = x;
			bf = cur;
			cur = x;
			break;
		}
	}
	long long mn = -1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == j || j == k || k == i)continue;
				long long sum = 0;
				int cur = start;
				int state = 0;
				while (1) {
					if (state == 0)sum += cost[cur][i];
					else if (state == 1)sum += cost[cur][j];
					else sum += cost[cur][k];
					if (nxt[cur] == 0)break;
					cur = nxt[cur];
					state = (state + 1) % 3;
				}

				if (mn==-1||mn>sum) {
					mn=sum;
					cur = start;
					state = 0;
					while (1) {
						if (state == 0)color[cur]=i;
						else if (state == 1)color[cur] = j;
						else color[cur] = k;
						if (nxt[cur] == 0)break;
						cur = nxt[cur];
						state = (state + 1) % 3;
					}
				}

			}
		}
	}
	cout << mn << '\n';
	for (int i = 1; i <= n; i++)cout << color[i]+1 << ' ';
}