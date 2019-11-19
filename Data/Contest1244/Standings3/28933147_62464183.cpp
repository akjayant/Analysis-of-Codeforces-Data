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
	for (int t=0; t<T; t++){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int pens = (a-1) / c + 1;
		int pencils = (b-1) / d + 1;
		if (pens + pencils > k) {
			puts("-1");
		} else {
			printf("%d %d\n", pens, pencils);
		}
	}

	return 0;
}
