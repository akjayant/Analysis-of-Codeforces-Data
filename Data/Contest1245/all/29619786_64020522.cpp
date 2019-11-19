#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm> 

#define ll long long

using namespace std;

int n;

ll mon[20011], k[20011];

struct city{
	ll x, y;
}a[20011];

int tot;

struct edge{
	int u, v;
	ll wgt;
}b[5000111];

ll dist(int p1, int p2){
	return abs(a[p1].x - a[p2].x) + abs(a[p1].y - a[p2].y);
}

void New(int from, int to, ll wgt) {
	b[++tot].u = from;
	b[tot].v = to;
	b[tot].wgt = wgt;
}

bool cmp(edge p1, edge p2) {
	return p1.wgt < p2.wgt;
}

ll ans;

int fa[20011];

int find(int w){
	if(w == fa[w]) return w;
	return fa[w] = find(fa[w]);
}

int jian[20011], cnt;

int bian[5000111], lcc;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y, fa[i] = i;
	for(int i = 1; i <= n; i++) cin >> mon[i];
	for(int i = 1; i <= n; i++) cin >> k[i];
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			New(i, j, (k[i] + k[j]) * dist(i, j));
		}
		New(i, 0, mon[i]);
	} 
	sort(b+1, b+tot+1, cmp);
	ans = 0;
	for(int i = 1; i <= tot; i++) {
		if(find(b[i].u) != find(b[i].v)) {
			fa[find(b[i].u)] = find(b[i].v);
			ans += b[i].wgt;
			if(b[i].v == 0){
				jian[++cnt] = b[i].u;
			}
			else bian[++lcc] = i;
		}
	}
	cout << ans << endl;
	cout << cnt << endl;
	for(int i = 1; i <= cnt; i++) {
		cout << jian[i] << " ";
	}
	cout << endl;
	cout << lcc <<endl;
	for(int i = 1; i <= lcc; i++) {
		cout << b[bian[i]].u << " "<< b[bian[i]].v<<endl;
	}
	return 0;
}