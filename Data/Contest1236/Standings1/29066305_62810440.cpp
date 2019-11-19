#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX = 100005;

int n, m, k;
LL cnt;
set<int> sx[MX], sy[MX];

int grt(const set<int> &s, int x) {
	set<int>::iterator it = s.lower_bound(x);
	if(it == s.end()) return MX;
	else return *it;
}

int les(const set<int> &s, int x) {
	set<int>::iterator it = s.upper_bound(x);
	if(it == s.end()) return *s.rbegin();
	if(it == s.begin()) return -MX;
	it--;
	return *it;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	cnt = 1LL * n * m - k;
	for(int x, y, i = 1; i <= k; i++) {
		scanf("%d%d", &x, &y);
		sx[x].insert(y);
		sy[y].insert(x);
	}
	int d = 1;
	int l = 1, r = n, b = 1, t = m;
	while(l <= r && b <= t) {
		if(d == 1) {
			if(sx[l].size()) t = min(t, grt(sx[l], b) - 1);
			cnt -= (t - b + 1), d = 2, l++;
		} else if(d == 2) {
			if(sy[t].size()) r = min(r, grt(sy[t], l) - 1);
			cnt -= (r - l + 1), d = 3, t--;
		} else if(d == 3) {
			if(sx[r].size()) b = max(b, les(sx[r], t) + 1);
			cnt -= (t - b + 1), d = 4, r--;
		} else {
			if(sy[b].size()) l = max(l, les(sy[b], r) + 1);
			cnt -= (r - l + 1), d = 1, b++;
		}
	}
	
	puts(cnt ? "No" : "Yes");
}

		
