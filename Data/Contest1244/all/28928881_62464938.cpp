#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	int t, a, b, c, d, k;
	cin >> t;
	while (t--){
		cin >> a >> b >> c >> d >> k;
		a = (a + c - 1) / c;
		b = (b + d - 1) / d;
		if (a + b > k) cout << "-1" << endl;
		else cout << a << " " <<  b << endl;
	}
	return 0;
}