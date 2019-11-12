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
int n;
const int maxn = 400;
vector<int> res[maxn];
int g[maxn];
void build(){
	for(int i = n * n, a = 0;i > 0;a ^= 1){
		if(a & 1)for(int j = 0;j < n;++j)res[j].emplace_back(i--);
		else for(int j = n-1;j > -1;--j)res[j].emplace_back(i--);
	}
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	build();
	for(int i = 0;i < n;++i)for(int j = 0;j < n;++j)cout << res[i][j] << " \n"[j == n-1];
}