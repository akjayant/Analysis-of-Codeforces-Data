#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
const int N = 2005;
ll dis[N]; int frm[N];
int p[N], ptot;
int lp[N], rp[N], etot;
ll ans;
int C[N], K[N];
int x[N], y[N];
int n;

ll get_dis(int a, int b)
{
	int d = std::abs(x[a] - x[b]) + std::abs(y[a] - y[b]);
	return 1ll * (K[a] + K[b]) * d;
}

void prim()
{
	FOR(i, 1, n) dis[i] = C[i], frm[i] = -1;
	FOR(i, 1, n)
	{
		int id = -1;
		FOR(j, 1, n) if(dis[j] != -1)
		{
			if(id == -1 || dis[j] < dis[id]) id = j;
		}
		ans += dis[id];
		if(frm[id] == -1) p[++ptot] = id;
		else lp[++etot] = id, rp[etot] = frm[id];
		dis[id] = -1;
		FOR(j, 1, n) if(dis[j] != -1)
			if(chk_min(dis[j], get_dis(id, j)))
				frm[j] = id;
	}
}

int main()
{
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	FOR(i, 1, n) scanf("%d", &C[i]);
	FOR(i, 1, n) scanf("%d", &K[i]);
	prim();
	printf("%lld\n", ans);
	printf("%d\n", ptot);
	FOR(i, 1, ptot) printf("%d%c", p[i], (i == iEND ? '\n' : ' '));
	printf("%d\n", etot);
	FOR(i, 1, etot) printf("%d %d\n", lp[i], rp[i]);
	return 0;
}
