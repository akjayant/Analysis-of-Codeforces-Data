//besmellah
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t --){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		a = ceil((double)a / double(c));
		b = ceil((double)b / double(d));
		if (a + b > k){
			cout << "-1\n";
		}
		else{
			cout << a << ' ' << b << '\n';
		}
	}
}
