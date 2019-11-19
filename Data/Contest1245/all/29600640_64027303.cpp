#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long 
#define re register
#define F first
#define S second
typedef pair<int, int> P;
const int N = 5e6 + 5;
const int INF = 0x3f3f3f3f;
int read() {
	int x = 0, f = 0; char ch = 0;
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int n, m;
int px[N], py[N], c[N], k[N], fa[N];
int find(int k){
    if (fa[k] == k) return k;
    return fa[k] = find(fa[k]);
}
struct node{
	int x, y, t;
	ll z;
}e[N];
bool cmp(node a, node b){
	return a.z < b.z;
}
ll ans, cnt;
vector <int> elec;
vector <pair<int, int> > path;
void Kruskal(){
	for (int i = 0; i <= n + 1; i++) fa[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++){
		int a = find(e[i].x), b = find(e[i].y);
		if (a == b) continue;
		ans += e[i].z; fa[a] = b; cnt++;
		if (e[i].t == 1) {
			if (e[i].x == 0) elec.push_back(e[i].y);
			else elec.push_back(e[i].x);
		}
		else if (e[i].t == 0) path.push_back(make_pair(e[i].x, e[i].y));
		if(cnt == n + 1) break;
	} 
}
signed main(){
	n = read();
	for (int i = 1; i <= n; i++) px[i] = read(), py[i] = read();
	for (int i = 1; i <= n; i++) c[i] = read();
	for (int i = 1; i <= n; i++) k[i] = read();
	for (int i = 1; i <= n; i++) {
		e[++m].x = 0, e[m].y = i, e[m].z = c[i]; e[m].t = 1;
		e[++m].x = i, e[m].y = 0, e[m].z = c[i]; e[m].t = 1;
	}
	e[++m].x = 0, e[m].y = n + 1, e[m].z = 0; e[m].t = -1;
	e[++m].x = n + 1, e[m].y = 0, e[m].z = 0; e[m].t = -1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			ll z = 1ll * (abs(px[i] - px[j]) + abs(py[i] - py[j])) * (k[i] + k[j]);
			e[++m].x = i, e[m].y = j, e[m].z = z; e[m].t = 0;
			e[++m].x = j, e[m].y = i, e[m].z = z; e[m].t = 0;
		}
	Kruskal();
	printf("%lld\n", ans);
	printf("%d\n", elec.size());
	for (int i = 0; i < elec.size(); i++) printf("%d ", elec[i]);
	printf("\n%d\n", path.size());
	for (int i = 0; i < path.size(); i++) printf("%d %d\n", path[i].first, path[i].second);
	return 0;
}
