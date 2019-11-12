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

const int N = 100;
const int M = 26;
char s[N], t[N];
int k, n, vis[N], Q1[N], Q2[N];
int a[N], b[N], cnta[M], cntb[M];
struct node {
	int x, y;
} Ans[2 * N];

void Doit() {
	F(i, 0, 25)
		if ( (cnta[i] + cntb[i]) & 1) {
			puts("No");
			return;
		}
	int L = 0;
	F(i, 0, 25) {
		if (!(cnta[i] + cntb[i])) continue;
		F(i, 1, n) a[i] = s[i] - 'a', b[i] = t[i] - 'a';
		Q1[0] = Q2[0] = 0;
		F(j, 1, n)
			vis[j] = (a[j] == i) + (b[j] == i);
		F(j, 1, n)
			if (vis[j] == 1) {
				if (a[j] == i)
					Q1[++ Q1[0]] = j;
				if (b[j] == i)
					Q2[++ Q2[0]] = j;
			}
		F(i, 1, Q1[0] / 2)
			Ans[++ L] = {Q1[i * 2 - 1], Q1[i * 2]}, swap(s[Ans[L].x], t[Ans[L].y]);
		F(i, 1, Q2[0] / 2)
			Ans[++ L] = {Q2[i * 2], Q2[i * 2 - 1]}, swap(s[Ans[L].x], t[Ans[L].y]);
		if (Q1[0] & 1) {
			Ans[++ L] = {Q1[Q1[0]], Q1[Q1[0]]}, swap(s[Ans[L].x], t[Ans[L].y]);
			Ans[++ L] = {Q2[Q2[0]], Q1[Q1[0]]}, swap(s[Ans[L].x], t[Ans[L].y]);
		}
	}
	if (L > 2 * n) {
		puts("No");
		return;
	}
	pf("Yes\n");
	pf("%d\n", L);
	F(i, 1, L)
		pf("%d %d\n", Ans[i].x, Ans[i].y);
}

int main() {
	for (sf("%d", &k); k --; ) {
		sf("%d%s%s", &n, s + 1, t + 1);
		int L = 0;
		F(i, 0, 25) cnta[i] = cntb[i] = 0;
		F(i, 1, n) a[i] = s[i] - 'a', b[i] = t[i] - 'a', cnta[a[i]] ++, cntb[b[i]] ++;
		Doit();
	}
}