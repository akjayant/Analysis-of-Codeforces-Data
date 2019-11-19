#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int all, n;
struct rp1 {
	ll x; ll y;
} a[2100000];
struct rp {
	int x; int y; ll z;
} e[11000000];
ll d[4100], c[4100];
vector<int> v1, v2;
int f[4100];

int find(int i) {
	if (f[i] != i) f[i] = find(f[i]);
	return f[i];
}

void add(int x, int y, ll z) {
	all++;
	e[all].x = x;
	e[all].y = y;
	e[all].z = z;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
	}
	for (int i = 1; i <= n + 1; i++)
		f[i] = i;
	all = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
		add(n + 1, i, c[i]);
	}
	for (int i = 1; i <= n; i++)
		scanf("%lld", &d[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			ll temp1 = 0, temp2 = 0;
			temp1 = (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
			temp2 = d[i] + d[j];
			temp1 *= temp2;
			add(i, j, temp1); 
		}
	sort(e + 1, e + all + 1, [&](const rp&a, const rp&b) {
		return a.z < b.z;
	});
	int now = 0; ll ans = 0;
	for (int i = 1; i <= all; i++) {
		if (find(e[i].x) != find(e[i].y) && now < n) {
			now++;
			ans += e[i].z;
			f[find(e[i].x)] = find(e[i].y);
			if (e[i].x == n + 1) {
				v1.push_back(e[i].y);
			} else if (e[i].y == n + 1) {
				v1.push_back(e[i].x);
			} else {
				v2.push_back(i);
			}
		}
	}
	printf("%lld\n", ans);
	printf("%d\n", v1.size());
	for (auto i:v1) {
		printf("%d ", i);
	} puts("");
	printf("%d\n", v2.size());
	for (auto i:v2) {
		printf("%d %d\n", e[i].x, e[i].y);
	}
	return 0;
}