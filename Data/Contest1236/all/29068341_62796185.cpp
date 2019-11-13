
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 3e2;
int n, g[nsz + 5][nsz + 5], ans[nsz + 5][nsz + 5];

int inline calc(int i, int j) {
	int cnt = 0;
	cont (k1, n) {
		cont (k2, n) {
			if (ans[i][k1] > ans[j][k2]) {
				++cnt;
			}
		}
		
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	int cnt = 0;
	bool d = 0;
	cont (j, n) {
		if (d) {
			cont (i, n) {
				g[i][j] = ++cnt;
			}
			d ^= 1;
		} else {
			for (int i = n; i >= 1; --i) {
				g[i][j] = ++cnt;
			}
			d ^= 1;
		}
	}
	cont (i, n) {
		cont (j, n) {
			cout << g[i][j] << ' ';
		}
		cout << ln;
	}
}