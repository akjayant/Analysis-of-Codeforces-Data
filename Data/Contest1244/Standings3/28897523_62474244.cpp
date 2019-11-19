#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, p, w, d;
bool vis[100005];

int main() {
	cin >> n >> p >> w >> d;
	for(int y = 0; ; y++) {
		int m = (p % w - y * d % w + w) % w;
		if(m == 0) {
			LL x = (p - y * d) / w;
			LL z = n - x - y;
			if(x >= 0 && z >= 0)
				cout << x << ' ' << y << ' ' << z << endl;
			else cout << -1 << endl;
			return 0;
		}
		if(!vis[m]) vis[m] = true;
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	return 0;
}
	
