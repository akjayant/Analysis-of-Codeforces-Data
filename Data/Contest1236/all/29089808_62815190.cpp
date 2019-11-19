#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> p[200001];
vector<int> a[100001], b[100001];
int n, m, k;

int main( ) {
	int x, y;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i ++) {
		scanf("%d %d", &x, &y);
		p[i] = make_pair(x, y); 
	}
	sort(p + 1, p + 1 + k);
	if (k == 0) printf("Yes\n");
	else {
		for (int i = 1; i <= n; i ++) a[i].push_back(0);
		for (int i = 1; i <= m; i ++) b[i].push_back(0);
		for (int i = 1; i <= k; i ++) {
			a[p[i].first].push_back(p[i].second);
		}
		for (int i = 1; i <= k; i ++) {
			swap(p[i].first, p[i].second);
		}
		sort(p + 1, p + 1 + k);
		for (int i = 1; i <= k; i ++) {
			b[p[i].first].push_back(p[i].second);
		}
		for (int i = 1; i <= n; i ++) {
			a[i].push_back(m + 1);
		}
		for (int i = 1; i <= m; i ++) {
			b[i].push_back(n + 1);
		}
		x = 1, y = 1;
		int dir = 1;
		long long ans = 1;
		int tmp = 0;
		int hengmin = 0, shumin = 0;
		int hengmax = n + 1, shumax = m + 1;
		int count = 0;
		for (; ; ) {
			++ count;
			if (dir == 1) {
				int idx = *lower_bound(a[x].begin(), a[x].end(), y);
				idx = min(idx, shumax);
				tmp = idx - y - 1;
				dir ++;
				if (count == 1 && tmp == 0) continue;
				hengmin = max(hengmin, x);
				y = idx - 1;
			}
			else if (dir == 2) {
				int idx = *lower_bound(b[y].begin(), b[y].end(), x);
				idx = min(idx, hengmax);
				tmp = idx - x - 1;
				dir ++;
				shumax = min(shumax, y);
				x = idx - 1;
			}
			else if (dir == 3) {
				int idx = *(--lower_bound(a[x].begin(), a[x].end(), y));
				idx = max(idx, shumin);
				tmp = y - (idx + 1);
				dir ++;
				hengmax = min(hengmax, x);
				y = idx + 1;
			}
			else {
				int idx = *(--lower_bound(b[y].begin(), b[y].end(), x));
				idx = max(idx, hengmin);
				tmp = x - (idx + 1);
				dir = 1;
				shumin = max(shumin, y);
				x = idx + 1;
			}
			if (tmp == 0) break;
			ans += tmp;
		}
		if (ans == 1LL * n * m - k) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
			