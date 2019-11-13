// In The Name Of GOD
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1024;
int q;
int n;
int a[MAXN];

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cerr << "HELLO WORLD:)\n";
	cin >> q;
	while (q--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = n; i; i--) {
			int cnt = 0;
			for (int j = 0; j < n; j++)
				if (a[j] >= i)
					cnt++;
			if (cnt >= i) {
				cout << i << '\n';
				break;
			}
		}
	}
	return false;
}