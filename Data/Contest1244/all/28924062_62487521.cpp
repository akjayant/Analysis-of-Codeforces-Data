#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005
using namespace std;

typedef long long ll;
ll n, mn = 1e18, st, a[N], ans[N], c[3][N];
vector<ll> gr[N];

void f(ll p, ll q) {
	ll i, s = 0, ne;
    if (gr[q].size() == 1) {
		for (i = 1; i <= n; i++) s += c[a[i]][i];
		if (s < mn) {
			mn = s;
			for (i = 1; i <= n; i++) ans[i] = a[i];
		}
		return;
    }
    if (gr[q][0] == p) ne = gr[q][1];
    else ne = gr[q][0];
    for (i = 0; i < 3; i++) {
		if (a[p] != i && a[q] != i) {a[ne] = i; break;}
    }
    f(q, ne);
}

int main()
{
	ll i, j, t1, t2;
	cin >> n;
	for (i = 0; i < 3; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%I64d", &c[i][j]);
		}
	}
	for (i = 1; i < n; i++) {
		scanf("%I64d %I64d", &t1, &t2);
		gr[t1].push_back(t2);
		gr[t2].push_back(t1);
		if (gr[t1].size() > 2 || gr[t2].size() > 2) {puts("-1"); return 0;}
	}
	for (st = 1; st <= n; st++) if (gr[st].size() == 1) break;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i == j) continue;
			a[st] = i;
			a[gr[st][0]] = j;
			f(st, gr[st][0]);
		}
	}
    cout << mn << endl;
    for (i = 1; i <= n; i++) printf("%I64d ", ans[i] + 1);
    return 0;
}