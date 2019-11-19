#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define fi first
#define se second
#define lson (rt<<1)
#define rson (rt<<1|1)
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://Code//in.txt","r",stdin)

const double eps = 1e-8;
const int mod = 1000000007;
const int maxn = 2000 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n;
int fa[maxn];
vector<int> vec1;
vector<pii> vec2;
int pre[maxn], x[maxn], y[maxn], c[maxn], k[maxn];
struct node {
	int u, v;
	LL w;
	bool operator < (const node& x) const {
		return w < x.w;
	}
};
vector<node> edge;

int fi(int x) {
	return fa[x] == x ? x : fa[x] = fi(fa[x]);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= n; ++i) {
    	scanf("%d%d", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; ++i) {
    	scanf("%d", &c[i]);
    	edge.push_back({0, i, c[i]});
    }
    for(int i = 1; i <= n; ++i) {
    	scanf("%d", &k[i]);
    	for(int j = 1; j < i; ++j) {
    		edge.push_back({i, j, 1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))});
    	}
    }
    sort(edge.begin(), edge.end());
    LL ans = 0;
    for(int i = 0; i < (int)edge.size(); ++i) {
    	int u = edge[i].u, v = edge[i].v;
    	LL w = edge[i].w;
    	int p1 = fi(u), p2 = fi(v);
    	if(p1 == p2) continue;
    	fa[p1] = p2;
    	ans += w;
    	if(u > v) swap(u, v);
    	if(u == 0) vec1.push_back(v);
    	else vec2.push_back({u, v});
    }
    printf("%lld\n", ans);
    int sz = vec1.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i) {
    	printf("%d%c", vec1[i], i == sz - 1 ? '\n' : ' ');
    }
    sz = vec2.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i) {
    	printf("%d %d\n", vec2[i].fi, vec2[i].se);
    }
    return 0;
}
