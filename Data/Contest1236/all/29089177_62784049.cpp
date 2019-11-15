// IN THE NAME OF ALLAH.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back

const int N = 100 * 1000 + 1000;



int32_t main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int _ = 0; _ < t; _++){
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		int k = min(b, c / 2);
		ans += 3 * k;
		b -= k;
		k = min(a, b / 2);
		ans += 3 * k;
		cout << ans << '\n';
	}


	return 0;
}