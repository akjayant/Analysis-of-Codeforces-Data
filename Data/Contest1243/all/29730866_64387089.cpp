#include <bits/stdc++.h>
#define ll long long
#define ld long double
#pragma 03
using namespace std;
int main(){
	ll n;
	cin >> n;
	ll m = n;
	for (int i = 2; i<=sqrt(n); i++){
		if (n % i == 0){
			while (n % i == 0) n /= i;
			if (n == 1){
				cout << i << endl;
				return 0;
			}
			else{
				cout << 1 << endl;
				return 0;
			}
		}
	}
	if (n == m) cout << n << endl;
	return 0;
}
 
