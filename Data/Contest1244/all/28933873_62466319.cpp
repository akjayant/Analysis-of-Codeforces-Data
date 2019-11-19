#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int ru = a / c, ka = b / d;
		if (a % c)
			ru++;
		if (b % d)
			ka++;
		if (ru + ka > k)
			cout << "-1\n";
		else
			cout << ru << ' ' << ka << '\n';
	}
	return 0;
} 
