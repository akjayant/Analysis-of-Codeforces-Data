#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200;

set <int> S;
vector <int> g[N], w;
int n, k;
int a[N], c[N][4], m[N], ans[N], us[N];
string ss;

void dfs(int v){
	us[v] = 1;
	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if (!us[to]){
			dfs(to);
		}
	}
	w.pb(v);
}

main (){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 1; j <= 3; j++){
		for (int i = 1; i <= n; i++){
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		m[x]++;
		m[y]++;
		g[x].pb(y);
		g[y].pb(x);
	}
	int id = 1;
	for (int i = 1; i <= n; i++){
		if (m[i] > 2){
			cout << -1;
			return 0;
		}
		else if(m[i] == 1){
			id = i;
		}	
	}
	dfs(id);
	int mn = 1e18;
	string s = "123", ot;
	for (int ii = 1; ii <= 6; ii++){
		int sum = 0;
		for (int j = 0; j < w.size(); j++){
			sum += c[w[j]][s[(j % 3)] - '0'];
		}
		if (mn > sum){
			mn = sum;
			ot = s;
		}
		//cout << s << endl;
		next_permutation(s.begin(), s.end());
	}
	cout << mn << endl;
	for (int j = 0; j < w.size(); j++){
		ans[w[j]] = ot[(j % 3)] - '0';
	}
	for (int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}










