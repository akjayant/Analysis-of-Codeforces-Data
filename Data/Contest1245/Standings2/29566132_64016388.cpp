#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d",&a)
#define sc2(a,b) sc(a), sc(b)
#define sc3(a,b,c) sc2(a, b), sc(c)
#define pri(x) printf("%d\n",x)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(0)
#define pri(x) printf("%d\n",x)
#define prif() printf("\n")
#define prie(x) printf("%d ", x)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e3+10;
const int MAX2 = 2.1e6+10;
int n;
int c[MAX], k[MAX], x[MAX], y[MAX];
pair<double, ii> ar[MAX2];
int p[MAX];
vector<int> power;
vector<ii> arr;

void build() {
	for (int i = 0; i <= n; i++) p[i] = i;	
}
int find(int kk) {
	return p[kk] == kk ? kk : p[kk]=find(p[kk]);	
}
void une(int a, int b) {
	p[find(a)]=find(b);
}

ll custo(int i, int j) {
	if (!i) return c[j];
	return (k[i]+k[j])*ll(abs(x[i]-x[j])+abs(y[i]-y[j]));
}

int main() {
	sc(n);
	for (int i = 1; i <= n; i++) sc2(x[i], y[i]);
	for (int i = 1; i <= n; i++) sc(c[i]);
	for (int i = 1; i <= n; i++) sc(k[i]);
	int qt = 0;
	for (int i = 0; i <= n; i++) for (int j = i+1; j <= n; j++)
		ar[qt++] = {custo(i, j), {i, j}};
	sort(ar, ar+qt);
	build();
	ll ans = 0;
	for (int i = 0; i < qt; i++) {
		int a = ar[i].s.f, b = ar[i].s.s;
		if (find(a)==find(b)) continue;
		if (!a) power.pb(b);
		else arr.pb({a, b});
		ans += ar[i].f;
		une(a, b);
	}
	printf("%lld\n", ans);
	pri(int(power.size()));
	for (int i : power) printf("%d ", i);
	prif();
	pri(int(arr.size()));
	for (auto i : arr) printf("%d %d\n", i.f, i.s);
	exit(0);
}
