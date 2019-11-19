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
const int maxn = 100008;
#define int ll
ll n, k, a[maxn];
map<int,int> cnt;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for(int i = 0;i < n;++i)cin >> a[i];
	for(int i = 0;i < n;++i)++cnt[a[i]];
	for(;k > 0;){
		if(cnt.size() == 1)return cout << 0 << '\n', 0;
		auto f = cnt.begin(), e = prev(cnt.end());
		ll cost = 0;
		if(k < min(f->second, e->second))break;
		if(f->second < e->second){
			cost = min(k / f->second, next(f)->first - f->first);
			k -= cost * f->second;
			cnt[cost + f->first] += f->second;
			// next(f)->second += f->second;
			cnt.erase(f);
		}
		else{
			cost = min(k / e->second, e->first - prev(e)->first);
			k -= cost * e->second;
			cnt[e->first - cost] += e->second;
			// prev(e)->second += e->second;
			cnt.erase(e);
		}
	}
	cout << cnt.rbegin()->first - cnt.begin()->first << '\n';
}