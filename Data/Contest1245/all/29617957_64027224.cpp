#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e3 + 7, M = 2e6 + 7;

struct node{
	short u, v;
	long long w;
	bool operator < (const node &a) const {
		return a.w > w;
	}
}edge[M + N];

pair<int, int> city[N], connection[N << 1];
int c[N], fa[N], powerStation[N];
int n, cnt, pcnt, ccnt;
long long k[N], ans;


int Find(int x) {
	int p = x;
	while (fa[p] > 0)
		p = fa[p];
	while (x != p) {
		int tmp = fa[x];
		fa[x] = p;
		x = tmp;
	}
	return x;
}

long long dist(int x, int y) {
	return (long long)abs(city[x].first - city[y].first) + (long long)abs(city[x].second - city[y].second);
}

void kruskal() {
	int tot = 0;
	for (int i = 0; i < cnt; i++) {
		int u = edge[i].u, v = edge[i].v;
		long long w = edge[i].w;
		int fau = Find(u), fav = Find(v);
		if (fau == fav)
			continue;
		ans += w;
		if (u == 0) {
			powerStation[pcnt++] = v;
		}
		else {
			connection[ccnt++] = make_pair(u, v);
		}
		fa[fau] = fav;
		if (++tot >= n) {
			break;
		}
	}
}

int main() {
	memset(fa, -1, sizeof(fa));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &city[i].first, &city[i].second);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
	}
	for (short i = 1; i <= n; i++) {
		for (short j = i + 1; j <= n; j++) {
			edge[cnt++] = {i, j, (k[i] + k[j]) * dist(i, j)};
		}
	}
	for (short i = 1; i <= n; i++) {
		edge[cnt++] = { 0, i, c[i] };
	}
	sort(edge, edge + cnt);
	kruskal();
	cout << ans << endl << pcnt << endl;
	for (int i = 0; i < pcnt; i++) {
		printf("%d ", powerStation[i]);
	}
	cout << endl << ccnt << endl;
	for (int i = 0; i < ccnt; i++) {
		printf("%d %d\n", connection[i].first, connection[i].second);
	}
	return 0;
}