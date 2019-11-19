#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

struct Edge{
	int u, v;
	ll cost;
	bool operator <(const Edge &o)const{
		return cost < o.cost;
	}
};

ll absx(ll x){ return x < 0? -x : x; }

ll c[2003], k[2003], x[2003], y[2003];
vector<int> ans, ansu, ansv;
Edge cand[2003 * 2003];
int par[2003];
bool on[2003];

int find(int x){
	return x == par[x] ? x : (par[x] = find(par[x]));
}

void link(int px, int py){
	on[px] |= on[py];
	par[py] = px;
}

int main()
{
	int N, E = 0; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld %lld", &x[i], &y[i]);
	for(int i = 0; i < N; i++){
		scanf("%lld", &c[i]);
		cand[E++] = {i, i, c[i]};
		par[i] = i;
	}
	for(int i = 0; i < N; i++)
		scanf("%lld", &k[i]);

	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			cand[E++] = {i, j, (k[i] + k[j]) * (absx(x[i] - x[j]) + absx(y[i] - y[j]))};

	sort(cand, cand + E);

	ll sum = 0;
	for(int i = 0; i < E; i++){
		int u = cand[i].u, v = cand[i].v;
		ll cost = cand[i].cost;
		if(u == v){
			int pv = find(u);
			if(!on[pv]){
				sum += c[v];
				ans.push_back(v);
				on[pv] = true;
			}
			continue;
		}
		int pu = find(u), pv = find(v);
		if(on[pu] && on[pv]) continue;
		if(pu == pv) continue;
		link(pu, pv);
		sum += cost;
		ansu.push_back(u);
		ansv.push_back(v);
	}

	printf("%lld\n", sum);
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++)
		printf("%d%c", ans[i] + 1, " \n"[i == (int)ans.size() - 1]);
	printf("%d\n", (int)ansv.size());
	for(int i = 0; i < (int)ansv.size(); i++)
		printf("%d %d\n", ansv[i] + 1, ansu[i] + 1);

	return 0;
}