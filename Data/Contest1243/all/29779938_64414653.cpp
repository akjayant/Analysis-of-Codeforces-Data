#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>


using namespace std;

#define _GLIBCXX_DEBUG

#define FOR(i, L, R) for (int i = (L); i < (R); i++)
#define FR(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair <int, int> pii;

const int INF = 1e8;

const int k = 17, sz = (1 << k);
vector <int> d(sz << 1);

vector <vector <int>> v;
vector <bool> use;

int check(int L, int R) {

	int ans = INF;

	L += sz, R += sz;

	while (L <= R) {
		
		if (L % 2 == 1) ans = min(ans, d[L]), L++;
		if (R % 2 == 0) ans = min(ans, d[R]), R--;

		L /= 2, R /= 2;

	}

	return ans;

}

void sw(int x) {
	
	x += sz;
	d[x] = INF;

	x /= 2;
	while (x > 0) {
		
		d[x] = min(d[x * 2], d[x * 2 + 1]);
		x /= 2;

	}

}

void dfs(int x) {
	
	use[x] = 1;
	sw(x);

	FOR(i, 1, v[x].size()) {
	
		int ind = check(v[x][i - 1] + 1, v[x][i] - 1);

		while (ind < INF) {
			
			dfs(ind);
			ind = check(ind + 1, v[x][i] - 1);

		}

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FOR(i, sz, (sz << 1)) d[i] = i - sz;
	for (int i = sz - 1; i > 0; i--) d[i] = min(d[i * 2], d[i * 2 + 1]);

	int n, m; cin >> n >> m;
	v.resize(n);
	use.resize(n, 0);

	FR(i, m) {
		
		int a, b; cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);

	}

	FR(i, n) {
		
		v[i].push_back(-1);
		v[i].push_back(n);

		sort(v[i].begin(), v[i].end());

	}

	int ans = -1;
	FR(i, n) {
		
		if (!use[i]) dfs(i), ans++;

	}

	cout << ans;

	return 0;
}
