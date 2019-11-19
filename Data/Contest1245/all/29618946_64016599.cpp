#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 4096
ll x[N], y[N];
ll c[N], k[N];

class UF{
public:
	int p[N], d[N];
	UF(){
		REP(i, N) p[i] = i;
		REP(i, N) d[i] = i;
	}

	int parent(int a){
		if(a == p[a]) return a;
		else return p[a] = parent(p[a]);
	}

	bool merge(int a, int b){
		a = parent(a), b = parent(b);
		if(a == b) return false;
		if(d[a] < d[b]) swap(a, b);
		// d[a] > d[b];
		p[b] = a;
		LAR(d[a], d[b]+1);
		return true;
	}
} uf;

typedef pair<ll, pii> edge;
vector<edge> que;

vector<int> ps;
vector<pii> cs;

int main(){
	int n; scanf("%d", &n);
	REP(i, n) scanf("%lld%lld", x+i, y+i);
	REP(i, n) scanf("%lld", c+i);
	REP(i, n) scanf("%lld", k+i);

	REP(i, n){
		FOR(j, i+1, n){
			que.EB( (k[i] + k[j]) * ( abs(x[i] - x[j]) + abs(y[i] - y[j]) ),  MP(i, j));
		}
	}
	REP(i, n) que.EB( c[i],  MP(i, i + n) );
	FOR(i, 1, n) uf.merge(0 + n, i + n);

	ll sm = 0;
	sort(ALL(que));
	for(auto &p : que){
		int &a = p.second.first, &b = p.second.second;
		ll c = p.first;
		if(!uf.merge(a, b)) continue;
		sm += c;
		if(b >= n){ // power plant
			ps.EB(a);
		}else{
			cs.EB(a, b);
		}
	}

	printf("%lld\n", sm);
	printf("%d\n", (int)ps.size());
	for(auto &i : ps) printf("%d ", i + 1);
	printf("\n");
	printf("%d\n", (int)cs.size());
	for(auto &i : cs) printf("%d %d\n", i.first + 1, i.second + 1);
}



