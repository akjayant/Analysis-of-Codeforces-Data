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
		int a, b, c;
		int m = 0;
		cin >> a >> b >> c;
		for (int i=0; i<=50; i++) {
			for (int j=0; j<=50; j++) {
				if (a-i >= 0 && b-i*2-j >= 0 && c-j*2 >= 0) {
					m = max(m, (i+j)*3);
				}
			}
		}
		cout << m << "\n";
	}

	return 0;
}
