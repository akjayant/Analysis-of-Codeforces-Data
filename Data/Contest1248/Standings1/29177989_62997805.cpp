#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
typedef long long ll;
struct _ {
	int k, t;
} a[100010];
struct cmp {
	bool operator()(const _& a, const _& b) {
		return a.k < b.k;
	}
};
int n, p;
ll ans[100010], cur = 0;
std::queue < _ > q;
std::set < _, cmp > s1, s2;
void pop() {
	_ u = q.front(); q.pop();
	// printf("pop %d\n", u.k);
	s1.erase(u); cur = ans[u.k];
	if (!q.empty()) ans[q.front().k] = std::max < ll > (cur, q.front().t) + p;
}
void push() {
	while (!s2.empty() && (s1.empty() || s2.begin()->k < s1.begin()->k)) {
		// printf("push : %d\n", s2.begin()->k);
		if (q.empty()) ans[s2.begin()->k] = std::max < ll > (cur, s2.begin()->t) + p;
		s1.insert(*s2.begin()), q.push(*s2.begin()), s2.erase(s2.begin());
	}
}
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::cin >> n >> p;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].t; a[i].k = i;
	}
	std::sort(a + 1, a + n + 1, [](const _& a, const _& b) {
		return a.t < b.t || (a.t == b.t && a.k < b.k);
	});
	for (int i = 1; i <= n; ++i) {
		// printf("considering #%d\n", a[i].k);
		while (!q.empty() && a[i].t > ans[q.front().k]) {
			pop(); push();
		}
		s2.insert(a[i]); push();
	}
	while (!q.empty() || !s2.empty()) push(), pop();
	for (int i = 1; i <= n; ++i)
		std::cout << ans[i] << "\n "[i != n];
}