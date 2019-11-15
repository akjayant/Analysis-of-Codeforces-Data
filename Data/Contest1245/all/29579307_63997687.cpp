#include <bits/stdc++.h>
using namespace std;

int a, b;

int gcd(int a, int b){
	return (b==0 ? a : gcd(b, a%b));
}

signed main(){
	int t; cin >> t;
	while(t--){
		cin >> a >> b;
		if(gcd(a, b)== 1){
			cout << "Finite\n";
		}
		else cout << "Infinite\n";
	}
}
