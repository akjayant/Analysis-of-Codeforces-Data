#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) //
#endif
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;
int n;
const int maxn = 200000;
ll c[3][maxn];
vector<int> edge[maxn];
int root;
const ll inf = 100000000000000000ll;
int id[maxn];
int col[maxn];
void iii(){
	id[1] = root;
	set<int> ins;
	ins.insert(root);
	for(int i = 1;i < n;++i){
		for(auto &j : edge[id[i]])if(j != id[i-1])id[i+1] = j;
	}
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int j = 0;j < 3;++j)for(int i = 1;i <= n;++i)cin >> c[j][i];
	for(int i = 1, a, b;i < n;++i){
		cin >> a >> b;
		edge[a].emplace_back(b);
		edge[b].emplace_back(a);
		if(max(edge[a].size(), edge[b].size()) > 2)return cout << -1 << '\n', 0;
	}
	for(int i = 1;i <= n;++i)if(edge[i].size() == 1)root = i;
	iii();
 	ll res = inf;
	{
		for(int i = 0;i < 3;++i)for(int j = 0;j < 3;++j)for(int k = 0;k < 3;++k)if(i != j and i != k and j != k){
			ll tmp = 0;
			vector<int> yee{i, j, k};
			for(int i = 1;i <= n;++i){
				tmp += c[yee[i % 3]][id[i]];
			}	
			res = min(res, tmp);
			// cout << res << ' ' << tmp << '\n';
			if(res == tmp){
				for(int i = 1;i <= n;++i){
					col[id[i]] = yee[i % 3] + 1;
				}	
				// for(int i = 1;i <= n;++i)cout << col[i] << ' ';cout << '\n';
			}
		}
	}
	cout << res << '\n';
	// ll tmp = 0;
	for(int i = 1;i <= n;++i)cout << col[i] << ' ';//, tmp += c[col[i]-1][i];
	// cout << tmp << '\n';
}