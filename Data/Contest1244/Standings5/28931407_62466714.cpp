#include <bits/stdc++.h>
#define lowbit(x) x & (-x)
#define S second
#define F first
using namespace std;
const int maxn = 1e5 + 5;
typedef long long LL;

int a, b, c, d, k;
int x, y;

int main(){
	int T; cin >> T;
	while(T--){
		cin >> a >> b >> c >> d >> k;
		x = (a % c == 0) ? a / c : a / c + 1;
		y = (b % d == 0) ? b / d : b / d + 1;
		if(x + y > k) puts("-1");
		else{
			cout << x << ' ' << y << endl;
		}
	}
}