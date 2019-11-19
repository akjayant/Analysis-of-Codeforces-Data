#include <bits/stdc++.h>

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define G(i, a, b) for (int i = a; i >= b; i --)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define pf printf
#define sf scanf

using namespace std;

const int N = 1e5 + 10;
const int M = 2 * N;

int n, m, u, v, val[N], Ans, k, vis[N];
int tov[M], nex[M], las[N], tot;
struct node {
	int k, v;
	bool operator < (const node &a) const { return a.v < v; }
} a;
priority_queue <node> Q;

void ins(int x, int y) {
	tov[++ tot] = y, nex[tot] = las[x], las[x] = tot;
}

int main() {
	sf("%d %d", &n, &m);
	F(i, 1, m) sf("%d %d", &u, &v), ins(u, v), ins(v, u);
	F(i, 2, n) Q.push({i, 0});

	k = 1;
	for (int x = las[k]; x ; x = nex[x])
		val[tov[x]] ++;

	vis[1] = 1;
	F(i, 2, n) {
		while (1) {
			a = Q.top();
			if (val[a.k] != a.v) {
				Q.pop();
				Q.push({a.k, val[a.k]});
			}
			else {
				k = a.k;
				Q.pop();
				break;
			}
		}
		if (a.v == i - 1)
			Ans ++;
		vis[k] = 1;
		for (int x = las[k]; x; x = nex[x])
			val[tov[x]] ++;
	}

	pf("%d\n", Ans);
}