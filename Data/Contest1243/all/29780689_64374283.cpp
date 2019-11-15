#include<bits/stdC++.H>
using namespace std;
int n, k, a[200000];
int main(){
	cin >> k;
	for (int it = 1; it <= k; it++) {

		cin >> n;
		for (int i = 1; i <= n; i++) {

			cin >> a[i];	
		}
		int res = 0;
		sort(a + 1, a + 1 + n);
		reverse(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
		    res = max(res, min(a[i], i));
		}	
		cout << res << endl;
	}
}
