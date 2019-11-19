#include<stdio.h>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
#define M 1000000007
typedef pair<long long int, long long int> pll;
typedef pair<int, int> pii;
typedef pair<long long int, pii> plii;
int n, m;
pll a[2009];
long long int c[2009];
long long int z[2009];
int p[2009];
int h[2009];
priority_queue<plii> tq;
vector<int> plist;
vector<pii> relist;
int find_p(int x) {
	if (x == p[x])return x;
	return p[x] = find_p(p[x]);
}
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i].first, &a[i].second);
		p[i] = i;
		h[i] = 0;
	}
	p[n] = n;
	h[n] = n;
	for (i = 0; i < n; i++)scanf("%lld", &c[i]);
	for (i = 0; i < n; i++)scanf("%lld", &z[i]);
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			long long int dx = a[i].first - a[j].first;
			long long int dy = a[i].second - a[j].second;
			long long int cost = (abs(dx) + abs(dy)) * (z[i] + z[j]);
			tq.push(plii(-cost, pii(i, j)));
		}
		tq.push(plii(-c[i], pii(i, n)));
	}
	long long int res = 0;
	int count = 0;
	while (!tq.empty()) {
		plii tt = tq.top();
		tq.pop();
		long long int dist = -tt.first;
		int ti = tt.second.first;
		int tj = tt.second.second;
		int ii = find_p(ti);
		int jj = find_p(tj);
		if (ii == jj)continue;
		if (h[ii] > h[jj]) { p[jj] = ii; }
		else if (h[ii] < h[jj]) { p[ii] = jj; }
		else { p[ii] = jj; h[jj]++; }

		res += dist;
		if (tj == n) {
			plist.push_back(ti);
		}
		else {
			relist.push_back(pii(ti, tj));
		}
		count++;
		if (count == n)break;
	}
	printf("%lld\n", res);
	printf("%d\n", plist.size());
	for (i = 0; i < plist.size(); i++)
		printf("%d ", plist[i] + 1);
	printf("\n");
	printf("%d\n", relist.size());
	for (i = 0; i < relist.size(); i++) {
		printf("%d %d\n", relist[i].first + 1, relist[i].second + 1);
	}
}