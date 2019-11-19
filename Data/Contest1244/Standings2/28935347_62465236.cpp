#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

#define N 100003

int main(){
	int t, a, b ,c ,d, k;
	cin >> t;
	while(t --){
		cin >> a >> b >> c >> d >> k;
		int e = a / c + (a % c ? 1 : 0);
		int e2 = b / d + (b % d ? 1 : 0);
		if(e + e2 > k) cout << "-1\n";
		else cout << e << ' ' << e2 << '\n';
	}
}