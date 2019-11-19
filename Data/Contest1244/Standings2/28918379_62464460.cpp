#include <iostream>
using namespace std;

int t;

int a, b, c, d, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b >> c >> d >> k;
		int minA = a / c + (a % c ? 1 : 0);
		int minB = b / d + (b % d ? 1 : 0);
		if(minA + minB > k) cout << -1;
		else cout << minA << ' ' << minB;
		cout << "\n";
	}
}