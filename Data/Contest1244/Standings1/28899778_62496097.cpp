//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

ll n, k, a[MAXN], s, e;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	s = 1, e = n;
	sort(a + 1, a + n + 1);
	while (a[s + 1] == a[s])
		s++;
	while (a[e] == a[e - 1])
		e--;
	while (s < e) {
		if (s < (n - e + 1)) {
			//cerr << s << " " << e << " " << k << endl;
			ll dif = a[s + 1] - a[s];
			ll t = k / s;
			if (t < dif) {
				cout << a[e] - (a[s] + t) << endl;
				return 0;
			}
			else {

				k -= s * dif;
				s++;
				while (a[s + 1] == a[s])
					s++;
			}
		}
		else {
			//cerr << "# " << s << " " << e << " " << k << endl;
			ll dif = a[e] - a[e - 1];
			ll t = k / (n - e + 1);
			if (t < dif) {
				cout << (a[e] - t) - a[s] << endl;
				return 0;
			}
			else {

				k -= (n - e + 1) * dif;
				e--;
				while (a[e - 1] == a[e])
					e--;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}
