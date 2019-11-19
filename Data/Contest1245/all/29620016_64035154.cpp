#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<long long, pii> edge;

const int MAXN = 2000;

pii coord[MAXN];
int n, par[MAXN + 1], compSize[MAXN + 1], c[MAXN], k[MAXN];
long long answ;
vector<edge> e;
vector<int> ans1;
vector<pii> ans2;

void readInput();
void makeGraph();
void mst();
int findPar(int u);
void merge(int pu, int pv);
void writeOutput();

int main() {
	readInput();
	makeGraph();
	mst();
	writeOutput();
}
void readInput() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> coord[i].X >> coord[i].Y;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		cin >> k[i];
}
void makeGraph() {
	for (int i = 0; i < n; i++) {
		edge t;
		t.X = c[i];
		(t.Y).X = n;
		(t.Y).Y = i;
		e.push_back(t);
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			edge t;
			t.X = ((long long) abs(coord[i].X - coord[j].X) + abs(coord[i].Y - coord[j].Y)) * ((long long) k[i] + k[j]);
			(t.Y).X = i;
			(t.Y).Y = j;
			e.push_back(t);
		}
}
void mst() {
	sort(e.begin(), e.end());
	for (int i = 0; i <= n; i++) {
		par[i] = i;
		compSize[i] = 1;
	}
	for (int i = 0; i < e.size(); i++) {
		int u = (e[i].Y).X, v = (e[i].Y).Y;
		long long w = e[i].X;
		int pu = findPar(u), pv = findPar(v);
		if (pu != pv) {
			merge(pu, pv);
			answ += w;
			if (u == n)
				ans1.push_back(v);
			else if (v == n)
				ans1.push_back(v);
			else
				ans2.push_back(pii(u, v));
		}
	}
}
int findPar(int u) {
	if (par[u] == u)
		return u;
	return par[u] = findPar(par[u]);
}
void merge(int pu, int pv) {
	if (compSize[pu] < compSize[pv])
		swap(pu, pv);
	par[pv] = pu;
	compSize[pu] += compSize[pv];
}
void writeOutput() {
	cout.sync_with_stdio(false);
	cout << answ << endl;
	cout << ans1.size() << endl;
	for (int i = 0; i < ans1.size(); i++)
		cout << ans1[i] + 1 << ' ';
	cout << endl;
	cout << ans2.size() << endl;
	for (int i = 0; i < ans2.size(); i++)
		cout << ans2[i].X + 1 << ' ' << ans2[i].Y + 1 << endl;
}
