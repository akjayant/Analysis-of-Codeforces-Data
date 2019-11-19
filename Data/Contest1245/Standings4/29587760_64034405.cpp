#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int d[2001];

int dsu(int a) {
	if (d[a] == a) return a;
	return dsu(d[a]);
}



typedef pair<long long int,pair<int,int>> Edge;
int n;
int vvv;


long long yen = 0;

int x[2001], y[2001], c[2001];
long long k[2001];


vector<Edge> v;
vector<pair<int,int>> con;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	vvv = n;

	for (int i = 0; i < 2001; ++i) d[i] = i;

	v.reserve(n * n);
	con.reserve(n * n);

	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i) { cin >> c[i]; yen += c[i]; }
	for (int i = 0; i < n; ++i) cin >> k[i];




	// todo : handle n == 1;

	Edge e;
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
		e.first = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
		e.second.first = i, e.second.second = j;
		v.push_back(e);
	}

	sort(v.begin(), v.end());

	for (auto e : v) {
		int x1 = dsu(e.second.first), x2 = dsu(e.second.second);
		if (x1 == x2) continue;
		if (e.first >= c[x1] && e.first >= c[x2]) continue; // connecting is expensive
		con.push_back({e.second.first + 1, e.second.second + 1});
		if (c[x1] <= c[x2]) {
			d[x2] = x1;
			yen -= c[x2];
			vvv --;
			yen += e.first;
		} else {
			d[x1] = x2;
			yen -= c[x1];
			vvv --;
			yen += e.first;
		}
	}

	cout << yen << endl;
	cout << vvv << endl;
	for (int i = 0; i < n; ++i) {
		if (d[i] == i) cout << i + 1 << " ";
	}
	cout << endl;
	cout << con.size() << endl;
	for (auto p : con) cout << p.first << " " << p.second << endl;
	
	return 0;
}