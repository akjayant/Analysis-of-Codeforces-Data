#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF (0x3f3f3f3f)

typedef long long ll;
typedef pair<int,int> pii;
const int N = 2019;
ll a[N][N], W[N], C[N];
int ect, fa[N], n;
int find( int x ) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

struct Node{
	int u, v;
	ll w;
	Node(){}
	Node( int t2, int t3, ll t4 ) :
		u(t2), v(t3), w(t4){}
};
Node e[N*N*2];
pii nod[N];
bool cmp(Node a, Node b) {
	return a.w < b.w;
}

vector<int> ans1;
vector<pii> ans2;
ll kk() {
	for ( int i = 0; i <= n; i ++ )
		fa[i] = i;
	ll cst = 0;
	for ( int i = 0; i < ect; i ++ ) {
		int u = e[i].u, v = e[i].v;
		ll w = e[i].w;
		int uu = find(u), vv = find(v);
		if ( uu != vv ) {
			fa[uu] = vv;
			cst += w;
		}
		else continue;
		if ( u == 0 ) ans1.pb(v);
		else if ( v == 0 ) ans1.pb(u);
		else ans2.pb(mp(u,v));
	}
	return cst;
}

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ )
		scanf("%d%d", &nod[i].first, &nod[i].second);
	for ( int i = 1; i <= n; i ++ ) {
		scanf("%lld", &W[i]);
		e[ect++] = Node(0,i,W[i]);
	}
	for ( int i = 1; i <= n; i ++ )
		scanf("%lld", &C[i]);
	for ( int i = 1; i <= n; i ++ )
		for ( int j = i+1; j <= n; j ++ ) {
			ll nw = (C[i]+C[j])*( abs(nod[i].first-nod[j].first) + abs(nod[i].second-nod[j].second) );
			e[ect++] = Node(i,j,nw);
		}
	sort(e,e+ect,cmp);
	ll mn = kk();
	printf("%lld\n", mn);
	int sz1 = ans1.size(), sz2 = ans2.size();
	printf("%d\n", sz1);
	for ( int i = 0; i < sz1; i ++ )
		printf("%d ", ans1[i]);
	printf("\n%d\n", sz2);
	for ( int i = 0; i < sz2; i ++ )
		printf("%d %d\n", ans2[i].first, ans2[i].second);
	return 0;
}
	