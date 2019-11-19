#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
#define int long long

using namespace std;

const int N = (1e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);

int x[N], y[N], c[N], k[N], used[N], mx[N], p[N], sz[N];
vector<pair<int,pair<int,int > > > g;
vector<pair<int,int > > path;

int find_set (int v) {
	if (v == p[v])
		return v;
	return p[v] = find_set(p[v]);
}
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
}
main()
{
	int n, ans = 0;
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> x[i] >> y[i];
		p[i] = i;
		sz[i] = 1;
	}
	for(int j = 1;j <= n; j++){
		cin >> c[j];
		ans += c[j];
		mx[j] = c[j];
	}
	for(int i = 1;i <= n; i++){
		cin >> k[i];
	}
	for(int i = 1;i <= n; i++){
		for(int j = i + 1;j <= n; j++){
			g.pb({(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}});
		}
	}
	sort(all(g));
	for(int i = 0;i < g.size(); i++){
		int u = g[i].sc.fr, v = g[i].sc.sc, w = g[i].fr;
		int pu = find_set(u), pv = find_set(v);
		if(pu != pv && w < max(mx[pu],mx[pv])){
			union_sets(pu, pv);
			ans -= max(mx[pu],mx[pv]);
			ans += w;
			if(mx[pu] > mx[pv]){
				mx[pu] = mx[pv];
				p[pu] = pv;
			}
			else{
				mx[pv] = mx[pu];
				p[pv] = pu;
			}
			path.pb({u,v});
		}
	}
	vector<int > vec;
	for(int i = 1;i <= n; i++){
		if(find_set(i) != i){
			continue;
		}
		vec.pb(i);
	}
	cout << ans << endl;
	cout << vec.size() << endl;
	for(int i = 0;i < vec.size(); i++){
		cout << vec[i] << endl;
	}
	cout << path.size() << endl;
	for(int i = 0;i < path.size(); i++){
		cout << path[i].fr << " " << path[i].sc << endl;
	}
}

