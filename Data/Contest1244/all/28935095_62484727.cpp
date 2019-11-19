#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int N = 1e5 + 7;

using namespace std;

struct node {
	int to;
	int next;
}edge[N << 1];

long long ans;
int head[N], a[N], b[N], c[N], deg[N], col[N], rk[N];
int n, cnt, flag;

void add(int u, int v) {
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int u, int fa, int cnt) {
	rk[cnt] = u;
	for (int i = head[u]; ~i && !flag; i = edge[i].next) {
		int v = edge[i].to;
		if (v == fa)
			continue;
		dfs(v, u, cnt + 1);	
	}
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] >= 3) {
			cout << -1 << endl;
			return 0;
		}
	}
	int arr[4];
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			dfs(i, -1, 1);
			break;
		}
	}
	ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i == j) {
				continue;
			}
			for (int k = 1; k <= 3; k++) {
				if (k == j || k == i) {
					continue;
				}
				long long tmp = 0;
				for (int l = i; l <= n; l += 3) {
					tmp += a[rk[l]];
				}
				for (int l = j; l <= n; l += 3) {
					tmp += b[rk[l]];
				}
				for (int l = k; l <= n; l += 3) {
					tmp += c[rk[l]];
				}
				if (ans > tmp) {
					ans = tmp;
					arr[0] = i, arr[1] = j, arr[2] = k;
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = arr[i]; j <= n; j += 3) {
			col[rk[j]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", col[i] + 1);
	}
	return 0;
}
