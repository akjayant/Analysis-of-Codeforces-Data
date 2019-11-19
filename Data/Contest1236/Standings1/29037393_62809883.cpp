#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) 0 and 0
#endif
#define rout(i) (cout << i << '\n', 0)
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;
string res[2] = {"No", "Yes"};
ll n, m, k;
map<int,vector<int>> ho, ve;
const int maxn = 100000;
// vector<pair<pair<int,int>, pair<int,int>> unab;
ll step = 1;
int l = 1, r = m, u = 1, d = n;
int x = 1, y = 1, w = 1;	
void tr(){
	l = 1, r = m, u = 2, d = n;
	x = 1, y = 1, w = 1;
	set<pair<int,int>> tu;
	for(;;){
		int go;
		// dout(x);dout(y)<<'\n';
		// dout(step)<<'\n';
		if(w == 1){
			go = min(r, (*lower_bound(ho[x].begin(), ho[x].end(), y)) - 1);
			if(go <= y){
				if(tu.count({x,y}))return;
				++w;
				tu.insert({x,y});
			}
			else{
				step += go - y;
				y = go;
				r = y-1;
				// ++w;
				// tu.insert({x,y});
			}
		}
		if(w == 2){
			go = min(d, (*lower_bound(ve[y].begin(), ve[y].end(), x)) - 1);
			if(go <= x){
				if(tu.count({x,y}))return;
				++w;
				tu.insert({x,y});
			}
			else{
				step += go - x;
				x = go;
				d = x-1;
				// ++w;
				// tu.insert({x,y});
			}
		}
		if(w == 3){
			go = max(l, (*prev(lower_bound(ho[x].begin(), ho[x].end(), y))) + 1);
			if(go >= y){
				if(tu.count({x,y}))return;
				++w;
				tu.insert({x,y});	
			}
			else{
				step += y - go;
				y = go;
				l = y+1;
				// ++w;
				// tu.insert({x,y});	
			}
		}
		if(w == 4){
			go = max(u, (*prev(lower_bound(ve[y].begin(), ve[y].end(), x))) + 1);
			if(go >= x){
				if(tu.count({x,y}))return;
				w = 1;
				tu.insert({x,y});
			}
			else{
				step += x - go;
				x = go;
				u = x+1;
				// w = 1;
				// tu.insert({x,y});
			}
		}
	}
		
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++i)ho[i].emplace_back(0);
	for(int i = 1;i <= m;++i)ve[i].emplace_back(0);
	for(int i = 0;i < k;++i){
		int x, y;
		cin >> x >> y;
		ho[x].emplace_back(y);
		ve[y].emplace_back(x);
	}
	for(auto &i : ho)sort(i.second.begin(), i.second.end());
	for(auto &i : ve)sort(i.second.begin(), i.second.end());
	for(int i = 1;i <= n;++i)ho[i].emplace_back(maxn+10);
	for(int i = 1;i <= m;++i)ve[i].emplace_back(maxn+10);
	tr();
// dout(x);dout(y)<<'\n';
// dout(step)<<'\n';
	cout << res[step + k == (ll)n * (ll)m] << '\n';
}