// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int main() {
	int T;
	cin >> T;
	for (int t=0; t<T; t++) {
		int n, m;
		ll a1=0, a2=0;
		ll b1=0, b2=0;
		int tmp;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> tmp;
			if (tmp&1) a1 ++;
			else a2 ++;
		}
		cin >> m;
		for (int i=0; i<m; i++) {
			cin >> tmp;
			if (tmp&1) b1 ++;
			else b2 ++;
		}
		printf("%lld\n", (long long) a1*b1+a2*b2);
	}

	return 0;
}
