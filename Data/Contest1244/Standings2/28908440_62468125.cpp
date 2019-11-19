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
int T;
int n;
const int maxn = 10000;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		vector<int> pos;
		for(int i = 1;i <= n;++i){
			char tmp;cin >> tmp;
			if(tmp == '1')pos.push_back(i);
		}
		int res = n;
		if(!pos.empty()){
			res = max(res, pos.back() * 2);
			res = max(res, (n+1-pos.front()) * 2);
		}
		cout << res << '\n';
	}
}