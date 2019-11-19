#define make_pair mp
#define emplace_back pb
#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
const int N = 1e5 + 5, C = 3;
int n, c[5][N], tab[N], col[N];
vector<int> v[N];

struct triple {
	int x, y, z;
};

bool inv[N];
int wsk = 1;
void dfs(int x) {
	tab[wsk] = x;
	inv[x] = 1;
	wsk++;
	for(auto y : v[x]) if(!inv[y]) dfs(y);
}

int main()
{
	scanf("%d", &n);
	for(int i=1;i<=C;i++)
	for(int j=1;j<=n;j++) scanf("%d", &c[i][j]);

	for(int i=2;i<=n;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}

	bool ok = 1;
	int cnt = 0;
	int leaf = 0;
	for(int i=1;i<=n;i++) {
		if(v[i].size() == 1) {
			leaf = i;
			cnt++;
		}
		else if(v[i].size() != 2) {
			ok = 0;
		}
	}
	if(cnt != 2) ok = 0;

	if(!ok) {
		printf("-1\n");
		return 0;
	}

	vector<triple> perms = { {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1} };
	dfs(leaf);

	long long cost = 1e18;
	triple ww;
	for(auto p : perms) {
		long long cc = 0;
		for(int i=1;i<=n;i++) {
			if(i % 3 == 1) cc += c[p.x][tab[i]];
			else if(i % 3 == 2) cc += c[p.y][tab[i]];
			else cc += c[p.z][tab[i]];
		}
		if(cost > cc) {
			cost = cc;
			ww = p;
		}	
	}

	printf("%lld\n", cost);
	for(int i=1;i<=n;i++) {
		if(i % 3 == 1) col[tab[i]] = ww.x;
		else if(i % 3 == 2) col[tab[i]] = ww.y;
		else col[tab[i]] = ww.z;
	}

	for(int i=1;i<=n;i++) printf("%d ", col[i]);

	return 0;
}
