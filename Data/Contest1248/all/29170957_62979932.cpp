#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100000 + 10;
int t,n,p[maxn],q[maxn],a,b,A,B;
signed main() {
	cin >> t;
	while (t--) {
		a = 0;
		b = 0;
		A = 0;
		B = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> p[i];
			if (p[i]&1) a++;
			else b++;
		}
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> q[i];
			if (q[i]&1) A++;
			else B++;
		}
		printf("%lld\n",a*A+b*B);
	}
	return 0;
}