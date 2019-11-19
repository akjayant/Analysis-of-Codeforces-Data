#include <iostream>
using namespace std;
int val[2][2],t,n,m,x;
inline void solve(){
	for(int i = 0;i < 2;i++)
		for(int j = 0;j < 2;j++)
			val[i][j] = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> x,val[0][x % 2]++;
	cin >> m;
	for(int i = 1;i <= m;i++)
		cin >> x,val[1][x % 2]++;
	long long ans = 0;
	ans += 1ll * val[0][0] * val[1][0];
	ans += 1ll * val[0][1] * val[1][1];
	cout << ans << '\n';
}
int main(){
	cin >> t;
	while(t--)solve();
	return 0;
} 