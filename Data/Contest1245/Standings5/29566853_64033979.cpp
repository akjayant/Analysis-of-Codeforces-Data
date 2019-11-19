#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define i(a) scanf("%d",&a)
#define l(a) scanf("%lld",&a)
#define INF 1000000000
typedef long long ll;
using namespace std;
struct pw {
	ll c;
	int x;
	int y;
	
};
struct cmp {
	bool operator()(pw t, pw u) {
		return t.c > u.c;
	}
};

priority_queue<pw,vector<pw>,cmp> pq;
vector<pair<ll, ll>> cor;
vector<ll> k;
int parent[2001];
int sz[2001];
int findparent(int x) {
	if (parent[x] == x) return x;
	return parent[x]=findparent(parent[x]);
}
int merge(int a, int b) {
	int pa = findparent(a);
	int pb = findparent(b);
	if (pa == pb) return -1;
	if (sz[pa] > sz[pb]) {
		parent[pb] = pa; sz[pa] += sz[pb];
	}
	else {
		parent[pa] = pb; sz[pb] += sz[pa];
	}
	return 0;
}
ll ab(ll x) {
	return x < 0 ? -x : x;
}
int main(){
	int n; i(n);
	rep(i, 0, n + 1) {
		parent[i] = i;
			sz[i] = 1;
	}
	rep(i, 0, n) {
		ll x, y; l(x); l(y);
		cor.push_back({ x,y });
	}
	rep(i, 1, n+1) {
		ll c; l(c);
		pq.push({ c,0,i });
	}
	rep(i, 0, n) {
		ll kk; l(kk);
		k.push_back(kk);
	}
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			ll c = (k[i] + k[j]) * (ab(cor[i].first - cor[j].first) + ab(cor[i].second - cor[j].second));
			if (c < 0) continue;
			pq.push({ c,i+1,j+1 });
		}
	}
	int cnt = 0;
	ll ans = 0;
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	while (cnt < n) {
		pw x = pq.top(); pq.pop();
		int res = merge(x.x, x.y);
		if (res == -1) continue;
		cnt++;
		ans += x.c;
		if (x.x == 0) {
			ans1.push_back(x.y);
		}
		else ans2.push_back({ x.x,x.y });
	}
	printf("%lld\n", ans);
	printf("%d\n", ans1.size());
	for (int i : ans1) {
		printf("%d ", i);
	}
	printf("\n");
	printf("%d\n", ans2.size());
	for (auto x : ans2) {
		printf("%d %d\n", x.first, x.second);
	}
}