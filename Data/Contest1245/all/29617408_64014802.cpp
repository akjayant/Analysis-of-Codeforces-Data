//In the name of God
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e3 + 10;

int n, x[N], y[N], c[N], k[N];
int par[N];
int a[N * N + N], b[N * N + N], w[N * N + N], per[N * N + N], res;
vector<int> vec, sec;

int root(int x){ return par[x] = (par[x] == x ? x : root(par[x])); }

bool merge(int u, int v){
	u = root(u);	v = root(v);
	if(u == v)	return false;
	par[u] = v;
	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	for(int i = 1; i <= n; i ++)
		cin >> k[i];
	for(int i = 1; i <= n; i ++)
		a[i] = 0, b[i] = i, w[i] = c[i];
	int t = n + 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j < i; j ++)
			a[t] = i, b[t] = j, w[t ++] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
	iota(per + 1, per + t, 1);
	sort(per + 1, per + t, [](int i, int j)	{ return w[i] < w[j];});
	iota(par, par + n + 1, 0);
	for(int i = 1; i < t; i ++){
		int u = a[per[i]], v = b[per[i]];
		if(merge(u, v)){
			res += w[per[i]];
			if(per[i] <= n)
				vec.push_back(per[i]);
			else
				sec.push_back(per[i]);
		}
	}
	cout << res << "\n" << vec.size() << "\n";
	for(auto v : vec)
		cout << v << " ";
	cout << "\n" << sec.size() << "\n";
	for(auto i : sec)
		cout << a[i] << " " << b[i] << "\n";
	return 0;
}
