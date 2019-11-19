#include <iostream>

using namespace std;

int main()
{
	int t;
	
	cin >> t;
	
	while (t--) {
		long long p1 = 0, p2 = 0, q1 = 0, q2 = 0, p, q, n, m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p;
			if (p & 1) {
				p1++;
			} else {
				p2++;
			}
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> q;
			if (q & 1) {
				q1++;
			} else {
				q2++;
			}
		}
		cout << p1 * q1 + p2 * q2 << endl;
	}
	
	return 0;
}