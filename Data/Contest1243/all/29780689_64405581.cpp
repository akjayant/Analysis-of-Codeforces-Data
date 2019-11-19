#include<bits/stdC++.H>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define pb push_back
#define mp  make_pair

const int N = int(2e5);
int x, y, n, m, p[N];
pair <int, int> f[N], g[N];
vector <int> r[N];

int get(int v) {
 	if (v == p[v]) return v;
 	return p[v] =get(p[v]);
}
void merge(int u, int v) {
 	u = get(u);
 	v = get(v);
 	if (u != v) {
 	 	if (rand()&1)
 	 		p[u] = v;
 	 	else
 	 		p[v] = u;
 	}
}




int main(){
	srand(time(0));
	set <int>s; 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		f[i].s = i;
		s.insert(i);
	}
	for (int i = 1; i <= m; i++) {
	 	cin >> x >> y;
	 	f[x].f++;
	 	f[y].f++;
	 	r[x].pb(y);
	 	r[y].pb(x);
		g[i] = mp(x, y);
	}


	for (int i = 1; i <= n; i++) {
	 	for (int k = 0; k < r[i].size(); k++) {
	 	 	s.erase(r[i][k]);
		}

	 	vector <int> del;
	 	for (int k = 1; k <= min(n - 1 - f[i].f, 25); k++) {
	        int v = *s.begin();
			merge(i, v);
	 		s.erase(v);
	 		del.pb(v);
	 	}
	 	for (int k = 0; k < r[i].size(); k++) {
	 	 	s.insert(r[i][k]);
	 	}
	 	for (int k = 0; k < del.size(); k++) {
	 	 	s.insert(del[k]);
	 	}

	}
	int ans = 0;

	for (int i = 1; i <= m; i++) {
	 	int u = get(g[i].f);
	 	int v = get(g[i].s);
	 	if (u != v) {
	 	 	merge(u, v);
	 	 	ans++;
	 	}
	}
	cout << ans;
}
