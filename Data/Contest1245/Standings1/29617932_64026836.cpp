#include <cstdio>
#include <algorithm>
using namespace std;

#define R register
struct _e {
	int u, v; long long w;
	bool operator < (const _e &B) const {
		return w < B.w;
	}
} E[4010000];

int N, tot, x[2010], y[2010], c[2010], k[2010];
long long ans;

bool bo[4010000];
int pa[2010], cnt, cnt1, cnt2;
int find(R int u) {
	return u == pa[u]? u: pa[u] = find(pa[u]);
}

int main() {
	scanf("%d", &N);
	for(R int i = 1; i <= N; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for(R int i = 1; i <= N; ++i) scanf("%d", &c[i]);
	for(R int i = 1; i <= N; ++i) scanf("%d", &k[i]);
	for(R int i = 1; i <= N; ++i) {
		E[++tot] = (_e) {0, i, c[i]};
	}
	for(R int i = 1; i <= N; ++i) {
		for(R int j = i + 1; j <= N; ++j) {
			E[++tot] = (_e) {i, j, 1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
		}
	}
	std::sort(E + 1, E + tot + 1);
	for(R int i = 0; i <= N; ++i) pa[i] = i;
	for(R int i = 1; i <= tot; ++i) {
		R int p1 = find(E[i].u), p2 = find(E[i].v);
		if(p1 != p2) {
			pa[p1] = p2;
			ans += E[i].w;
			if(!E[i].u || !E[i].v) ++cnt1;
			else ++cnt2;
			bo[i] = 1;
			if(++cnt == N) break;
		}
	}
	printf("%lld\n%d\n", ans, cnt1);
	for(R int i = 1; i <= tot; ++i) if(bo[i]) {
		if(!E[i].v) printf("%d ", E[i].u);
		if(!E[i].u) printf("%d ", E[i].v);
	}
	printf("\n%d\n", cnt2);
	for(R int i = 1; i <= tot; ++i) if(bo[i]) {
		if(E[i].u && E[i].v) printf("%d %d\n", E[i].u, E[i].v);
	}
	return 0;
}
