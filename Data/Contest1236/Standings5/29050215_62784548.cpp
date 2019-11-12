#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 101;
int t;
int a,b,c;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		int ans = 0, cur_take = 0;
		cur_take = min(b, c/2);
		b -= cur_take;
		c -= cur_take;
		ans += cur_take * 3;
		cur_take = min(a, b/2);
		ans += cur_take * 3;
		cout << ans << '\n';
	}
}