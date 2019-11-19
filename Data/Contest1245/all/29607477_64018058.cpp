#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
#define pi 3.14159265358979323846
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
 
const int o = 1 << 17;
 
const int mod = 1000000007;
 
const int inf = 0x3f3f3f3f;
const ll huge = 100000000000000000LL;
 
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<pli, int> st;
typedef priority_queue<st> pq;

const int maxn = 2005;

int n, cnt;
int k[maxn];
int x[maxn], y[maxn];

struct edge { 
	int x, y;
	ll w;
	edge() {}
	edge(int _x, int _y, ll _w) {
		x = _x; 
		y = _y;
		w = _w;	
	}
};

bool cmp(edge x, edge y) {
	if (x.w != y.w)
		return x.w < y.w;
	if (x.x != y.x)
		return x.x < y.x;
	return x.y < y.y;
}

int sz[maxn];
int dad[maxn];
edge edges[maxn * maxn];

int get_dad(int x) {
	if (dad[x] == x)
		return x;
	return dad[x] = get_dad(dad[x]);
}

bool join(int x, int y) {
	int dadx = get_dad(x);
	int dady = get_dad(y);
	if (dadx == dady)
		return false;
	if (sz[dadx] < sz[dady]) {
		sz[dady] += sz[dadx];
		dad[dadx] = dady;	
	}
	else {
		sz[dadx] += sz[dady];
		dad[dady] = dadx;	
	}
	return true;
}

vector<int> ps;
vector<pii> es;
 
int main() {
    ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		edges[cnt++] = edge(i, n, c);
	}
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) 
			edges[cnt++] = edge(i, j, (ll)(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])));
	sort(edges, edges + cnt, cmp);
	for (int i = 0; i <= n; i++)
		dad[i] = i;
	ll sol = 0;
	for (int i = 0; i < cnt; i++) 
		if (join(edges[i].x, edges[i].y)) {
			sol += edges[i].w;
			if (edges[i].y == n)
				ps.push_back(edges[i].x + 1);
			else
				es.push_back(pii(edges[i].x + 1, edges[i].y + 1));		
		}
	cout << sol << endl;
	cout << (int)ps.size() << endl;
	for (int i = 0; i < ps.size(); i++)
		cout << ps[i] << ' ';
	cout << endl;
	cout << (int)es.size() << endl;
	for (int i = 0; i < es.size(); i++)
		cout << es[i].first << ' ' << es[i].second << endl;
    return 0;
}
