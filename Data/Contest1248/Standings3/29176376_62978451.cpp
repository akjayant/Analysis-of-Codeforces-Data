#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	ll i, t, e, n, p, q, m, A = 0, B = 0, C = 0, D = 0, tmp;
	cin >> t;

	for(i = 0; i < t; i++) {
		A = 0; B = 0; C = 0; D = 0;
		cin >> n;
		for(e = 0; e < n; e++) {
			cin >> tmp;
			if(tmp % 2 == 0) A++;
			else B++;
		}
		cin >> m;
		for(e = 0; e < m; e++) {
			cin >> tmp;
			if(tmp % 2 == 0) C++;
			else D++;
		}
		cout << A * C + B * D << endl;
	}
	
}


