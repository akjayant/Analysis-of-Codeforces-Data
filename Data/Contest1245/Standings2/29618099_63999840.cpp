#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int main(){
	cin >> t;
	while (t--){
		cin >> a >> b;
		if (a==1||b==1){
			cout << "Finite\n";
		}else
		if (__gcd(a,b)==1){
			cout << "Finite\n";
		}else
			cout << "Infinite\n";
	}
} 