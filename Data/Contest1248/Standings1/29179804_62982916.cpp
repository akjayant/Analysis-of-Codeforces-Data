#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n, m;
ll x, one, one2, zero, zero2;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		one=one2=zero=zero2=0;
		for(int i=1; i<=n; i++) {
			scanf("%lld", &x);
			if (x%2) one++;
			else zero++;
		}
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			scanf("%lld", &x);
			if (x%2) one2++;
			else zero2++;
		}
		cout<<one*one2+zero*zero2<<endl;
	}
	return 0;
}
